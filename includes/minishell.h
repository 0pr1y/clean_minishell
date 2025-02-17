#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <linux/limits.h>
# include <fcntl.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include <stdbool.h>
# include <stddef.h>
# include "../libft/libft.h"
# include "macros.h"

typedef struct s_pipes
{
	int	pipefd[2];
}	t_pipes;

typedef struct s_parsed
{
	char	**cmd;
	char	*entry;
	char	*exit;
	int		ex_append;
	char	**lim;
	char	*err_msg;
	int		err_code;
	char	*lim_data;
}	t_parsed;

typedef struct s_minish
{
	char		**envp;
	char		pwd[PATH_MAX];
	int			nb_cmds;
	int			ex_code;
	t_pipes		*pipes;
	pid_t		*pids;
	t_parsed	*all_parsed;
}				t_minish;

typedef int	t_fd;

typedef struct s_check_path
{
	char		*dir_or_f;
	int			counter;
	int			last;
	int			end_of_first;
	int			first;
	struct stat	sb;
}	t_check_path;

typedef struct s_extremes
{
	int	*j;
	int	*i;
}	t_extremes;

typedef struct s_line_n_ind
{
	char	*line;
	int		*i;
}	t_line_n_ind;

void	handle_sigint(int sig);
int		ft_isempty(char *str);
void	obtain_cmds(char *line, t_minish *minish);
void	show(t_parsed *all_parsed, int nb_cmds);
int		count_chars(char *str, char c);
int		end_of_word(int *i, char *line);
void	skip_spaces(int *i, char *line);
void	quote_to_quote(int *j, char *line, char quote);
char	*reduce_str(char *str, int strt, int end);
void	failed_malloc(void *str);
void	words_free(char **list);
void	free_all_parsed(t_parsed *all_parsed, int nb_cmds);

void	define_exp(char **dst, char *src, t_minish *minish);
int		last_wrd(int first, int last);
void	found_error(t_parsed *parsed, char *exp, char *dir_or_f,
			const char *msg);
void	free_redir(t_parsed *parsed);
char	*no_quotes(char *str);

void	entry_error(char *entry, t_parsed *parsed, t_minish *minish);
int		not_readable(char **exp, t_parsed *parsed);
int		path_error_en(char *exp, t_parsed *parsed);
void	put_cursors(char *exp, int end, int *first, int *last);
void	next_dir(char *exp, int *last, int end);

void	exit_error(char *ex, t_parsed *parsed, t_minish *minish);
int		amb_redir(char *src, char *expanded, t_parsed *parsed);
int		always_a_dir(char *exp, int end, t_parsed *parsed);
int		bad_redir_gd_file(char *exp, t_parsed *parsed, struct stat sb);
int		path_error_ex(int end, char *exp, t_parsed *parsed);
void	check_path_init(int *end, char *exp, t_check_path *cp);
void	at_last_dir(int *first, char *exp);
void	end_of_dir(char *exp, int *last);
int		wrong_data_type(t_check_path *cp, t_parsed *parsed, char *exp, int end);
int		not_writable(t_check_path *cp, t_parsed *parsed, char *exp, int end);

void	parsing(t_parsed *parsed, char *line, t_minish *minish, int init);
char	*build_substring(char *line, unsigned int end, char **dst);
void	add_str(char ***src, char *new, int *size);
char	**fisrt_add(char *new, int *size);
int		delim(char *line, int strt, t_parsed *parsed, int *lim_size);
int		entry(char *line, int strt, t_parsed *parsed, t_minish *minish);
int		ext(char *line, int strt, t_parsed *parsed, t_minish *minish);
void	dequote_parsed(t_parsed *parsed);

void	expand(char **line, t_minish *minish);
void	new_limit(char *line, char *var_value, int *i, int *limit);
void	key_to_value(char *var_value, char **line, int key_len, int to_dol);
void	erase_var(char *line, int *i, int to_dol, int *limit);

void	opened_quotes(char *str, int times, char *to_free);
int		pipe_first(char *line, t_parsed *parsed);
void	opened_pipe(char *str);
void	syntax_error(char *line, t_parsed *parsed);
void	before_pipe(t_parsed *parsed, char *line, int i);
void	before_entry(t_parsed *parsed, char *line, int i);
void	before_exit(t_parsed *parsed, char *line, int i);
void	before_ampersand(t_parsed *parsed, char *line, int i);
void	syntax_err_msg(t_parsed *parsed, char first, char scnd, char third);

void	lounch_processes(t_minish *minish, int nbr_pipes);
void	multi_commands(t_minish *minish, int fork_nbr);
void	calling_cmds(int i, t_minish *minish, t_pipes *pipes, pid_t	*pids);
char	**find_env_paths(char *envp[]);
char	**is_executable(char **args, char **env_paths, char **envp);
void	cmd_path(char *expanded, t_parsed *parsed);
void	cmd_execution(int i, t_minish *minish, t_pipes *pipes, pid_t *pids);
int		entry_redirs(int i, t_minish *minish, t_pipes *pipes, pid_t *pids);
int		exit_redirs(int i, t_minish *minish, t_pipes *pipes, pid_t *pids);
void	get_pid_status(int last, t_minish *minish);

void	dup_error(int fd);
void	pids_alloc_error(t_pipes *p, int nbr_commands);
void	fork_error(t_pipes *p, int nbr_commands);
void	print_err(char *error);
void	failed_execve(char **args, t_minish *minish);

void	free_split(char **strs);
void	close_all_pipes(t_pipes *p, int nbr_commands);
void	close_fd(int *fd);
void	free_split(char **strs);
void	close_fds_and_exit(t_fd input_fd, t_fd output_fd, int ret_code);

bool	isbuiltin(const char *command);
int		exec_builtin(char **argv, t_fd input_fd, t_fd output_fd, char ***envp);
int		request_limiters(t_parsed *p, int nb_cmds);

//builtins.h
int		ft_unset(char **arguments, t_fd input_fd, t_fd output_fd, char ***envp);
int		ft_echo(char **arguments, t_fd input_fd, t_fd output_fd, char ***envp);
int		ft_export(char **arguments, t_fd input_fd, t_fd output_fd,
			char ***envp);
int		ft_env(char **arguments, t_fd input_fd, t_fd output_fd, char ***envp);
int		ft_exit(char **arguments, t_fd input_fd, t_fd output_fd, char ***envp);
int		ft_cd(char **arguments, t_fd input_fd, t_fd output_fd, char ***envp);
int		ft_pwd(char **arguments, t_fd input_fd, t_fd output_fd, char ***envp);

//utils.h
char	*ft_getenv(const char **envp, const char *name);
int		ft_setenv(char ***envp, const char *name, const char *value,
			int overwrite);
int		ft_unsetenv(char **envp, const char *name);
void	write_error(const char *header, const char *error_message);

#endif

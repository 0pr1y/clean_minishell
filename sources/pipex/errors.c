#include "../../includes/minishell.h" 

void	failed_execve(char **args, t_minish *minish)
{
	char	*msg;
	char	*empty;
	char	*to_print;
	char	*cpy;

	empty = "''";
	cpy = ft_strdup(args[0]);
	failed_malloc(cpy);
	if (cpy[0] == '\0')
		to_print = empty;
	else
		to_print = cpy;
	if (ft_strchr(to_print, '/') == NULL)
	{
		msg = ft_strjoin(to_print, ": command not found");
		(failed_malloc(msg), print_err(msg));
	}
	else
	{
		msg = ft_strjoin(to_print, ": No such file or directory");
		(failed_malloc(msg), print_err(msg));
	}
	(free(msg), free(cpy));
	minish->ex_code = 127;
	return ;
}

void	dup_error(int fd)
{
	if (fd >= 0)
		close_fd(&fd);
	perror("dup2()");
	exit(EXIT_FAILURE);
}

void	fork_error(t_pipes *p, int nbr_commands)
{
	perror("fork()");
	close_all_pipes(p, nbr_commands);
	free(p);
	exit(EXIT_FAILURE);
}

void	pids_alloc_error(t_pipes *p, int nbr_commands)
{
	perror("malloc()");
	close_all_pipes(p, nbr_commands);
	free(p);
	exit(EXIT_FAILURE);
}

void	print_err(char *error)
{
	char	*msg;

	if (error == NULL)
		return ;
	msg = ft_strjoin("minishell: ", error);
	failed_malloc(msg);
	if (msg == NULL)
		exit(EXIT_FAILURE);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	free(msg);
}

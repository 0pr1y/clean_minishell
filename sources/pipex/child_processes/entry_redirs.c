#include "../../../includes/minishell.h"

void	print_lim_data(int i, t_minish *minish, t_pipes *pipes, pid_t	*pids)
{
	t_pipes	a_pipe;
	pid_t	a_pid;

	if (pipe(a_pipe.pipefd) == -1)
		(perror("pipe()"), exit(EXIT_FAILURE));
	a_pid = fork();
	if (a_pid == 0)
	{
		close_fd(&a_pipe.pipefd[0]);
		if (dup2(a_pipe.pipefd[1], STDOUT_FILENO) == -1)
			dup_error(a_pipe.pipefd[1]);
		close_fd(&a_pipe.pipefd[1]);
		write(1, minish->all_parsed[i].lim_data,
			ft_strlen(minish->all_parsed[i].lim_data));
		close_all_pipes(pipes, (minish->nb_cmds - 1));
		free(pipes);
		free(pids);
		free_split(minish->envp);
		exit(EXIT_SUCCESS);
	}
	close_fd(&a_pipe.pipefd[1]);
	if (dup2(a_pipe.pipefd[0], STDIN_FILENO) == -1)
		dup_error(a_pipe.pipefd[0]);
	close_fd(&a_pipe.pipefd[0]);
	wait(NULL);
}

void	default_entry(int *fd_in, char *entry)
{
	int	dup_res;

	*fd_in = open(entry, O_RDONLY);
	if (*fd_in == -1)
		print_err("Open entry redirection error");
	dup_res = dup2(*fd_in, STDIN_FILENO);
	if (dup_res == -1)
		dup_error(*fd_in);
	close_fd(fd_in);
}

void	prev_pipe_entry(int i, t_minish *minish, t_pipes *pipes, pid_t	*pids)
{
	int	d_res;

	d_res = dup2(minish->pipes[i - 1].pipefd[0], STDIN_FILENO);
	if (d_res == -1)
	{
		perror("dup2()");
		close_all_pipes(pipes, (minish->nb_cmds - 1));
		free(pipes);
		free(pids);
		free_split(minish->envp);
		exit(EXIT_FAILURE);
	}
	close_fd(&minish->pipes[i - 1].pipefd[0]);
}

int	entry_redirs(int i, t_minish *minish, t_pipes *pipes, pid_t *pids)
{
	int	j;
	int	fd_in;

	fd_in = STDIN_FILENO;
	if (minish->all_parsed[i].lim_data != NULL
		|| minish->all_parsed[i].entry != NULL)
	{
		if (minish->all_parsed[i].lim_data != NULL)
			print_lim_data(i, minish, pipes, pids);
		else if (minish->all_parsed[i].entry != NULL)
			default_entry(&fd_in, minish->all_parsed[i].entry);
	}
	else
		if (i > 0)
			prev_pipe_entry(i, minish, pipes, pids);
	j = 0;
	while (j < minish->nb_cmds - 1)
	{
		if (j != (i - 1))
			close_fd(&minish->pipes[j].pipefd[0]);
		j++;
	}
	return (fd_in);
}

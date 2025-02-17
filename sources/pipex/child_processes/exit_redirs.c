#include "../../../includes/minishell.h"

void	next_pipe_exit(t_minish *minish, int i, t_pipes *pipes, pid_t *pids)
{
	int	d_res;

	d_res = dup2(minish->pipes[i].pipefd[1], STDOUT_FILENO);
	if (d_res == -1)
	{
		perror("dup2()");
		close_all_pipes(pipes, (minish->nb_cmds - 1));
		free(pipes);
		free(pids);
		free_split(minish->envp);
		exit(EXIT_FAILURE);
	}
	close_fd(&minish->pipes[i].pipefd[1]);
}

void	file_exit(t_minish *minish, int i, int *fd_out)
{
	if (minish->all_parsed[i].ex_append == 1)
		*fd_out = open(minish->all_parsed[i].exit,
				O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		*fd_out = open(minish->all_parsed[i].exit,
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if ((*fd_out) == -1)
		print_err("Open exit redirection error");
	if (dup2(*fd_out, STDOUT_FILENO) == -1)
		dup_error(*fd_out);
}

int	exit_redirs(int i, t_minish *minish, t_pipes *pipes, pid_t *pids)
{
	int	j;
	int	fd_out;

	j = 0;
	fd_out = STDOUT_FILENO;
	if (minish->all_parsed[i].exit == NULL)
	{
		if (i < minish->nb_cmds - 1)
			next_pipe_exit(minish, i, pipes, pids);
	}
	else
		file_exit(minish, i, &fd_out);
	while (j < minish->nb_cmds - 1)
	{
		close_fd(&minish->pipes[j].pipefd[1]);
		j++;
	}
	return (fd_out);
}

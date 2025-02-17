#include "../../includes/minishell.h" 

void	free_split(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i] != NULL)
		free(strs[i]);
	free(strs);
}

void	close_all_pipes(t_pipes *p, int nbr_commands)
{
	int	i;

	i = 0;
	while (i < nbr_commands)
	{
		if (p[i].pipefd[0] != -1)
		{
			close_fd(&p[i].pipefd[0]);
			p[i].pipefd[0] = -1;
		}
		if (p[i].pipefd[1] != -1)
		{
			close_fd(&p[i].pipefd[1]);
			p[i].pipefd[1] = -1;
		}
		i++;
	}
}

void	get_pid_status(int last, t_minish *minish)
{
	int	i;
	int	status;

	i = minish->nb_cmds - 1;
	waitpid((minish->pids[last]), &status, 0);
	minish->ex_code = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		minish->ex_code = 130;
		printf("\r\033[2K");
	}
	while (i >= 0)
	{
		wait(&status);
		if (WIFSIGNALED(status))
			printf("\r\033[2K");
		i--;
	}
}

void	close_fd(int *fd)
{
	if (*fd != -1)
		close(*fd);
	*fd = -1;
}

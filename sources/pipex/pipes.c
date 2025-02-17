#include "../../includes/minishell.h"

void	pipes_creation(t_pipes *p, int nbr_pipes)
{
	int	i;

	i = 0;
	while (i < nbr_pipes)
	{
		if (pipe(p[i].pipefd) == -1)
		{
			perror("pipe()");
			free(p);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	lounch_processes(t_minish *minish, int nbr_pipes)
{
	int	fork_nbr;

	fork_nbr = minish->nb_cmds;
	if (nbr_pipes > MAX_NB_CMDS - 2)
	{
		nbr_pipes = MAX_NB_CMDS - 2;
		fork_nbr = MAX_NB_CMDS - 1;
	}
	minish->pipes = (t_pipes *)malloc(sizeof(t_pipes) * (nbr_pipes));
	if (minish->pipes == NULL)
	{
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		exit(EXIT_FAILURE);
	}
	pipes_creation(minish->pipes, nbr_pipes);
	minish->pids = (pid_t *)malloc(sizeof(pid_t) * (fork_nbr));
	if (minish->pids == NULL)
		pids_alloc_error(minish->pipes, fork_nbr);
	multi_commands(minish, fork_nbr);
	free(minish->pids);
}

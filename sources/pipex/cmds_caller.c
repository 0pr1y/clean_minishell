#include "../../includes/minishell.h"

void	one_builtin(t_minish *minish, int *one_built)
{
	int	fd_out;

	fd_out = STDOUT_FILENO;
	if (minish->all_parsed[0].exit != NULL)
	{
		if (minish->all_parsed[0].ex_append == 1)
			fd_out = open(minish->all_parsed[0].exit,
					O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			fd_out = open(minish->all_parsed[0].exit,
					O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd_out == -1)
			(print_err("Open error for the only builtin\n"));
	}
	minish->ex_code = exec_builtin(minish->all_parsed[0].cmd,
			-1, fd_out, &minish->envp);
	if (fd_out > STDERR_FILENO)
		close_fd(&fd_out);
	*one_built = 1;
}

void	a_synt_error(t_minish *minish)
{
	close_all_pipes(minish->pipes, (minish->nb_cmds - 1));
	free(minish->pipes);
	free(minish->pids);
	free_split(minish->envp);
	free_all_parsed(minish->all_parsed, minish->nb_cmds);
	exit(2);
}

void	quit(t_minish *minish, int fork_nbr, int exit_code, int i)
{
	close_all_pipes(minish->pipes, (fork_nbr - 1));
	free(minish->pipes);
	free(minish->pids);
	free_split(minish->envp);
	print_err(minish->all_parsed[i].err_msg);
	free_all_parsed(minish->all_parsed, minish->nb_cmds);
	exit(exit_code);
}

int	one_valid_cmd(t_minish *minish)
{
	if (minish->all_parsed[0].cmd != NULL
		&& minish->all_parsed[0].err_code == 0
		&& minish->nb_cmds == 1)
		return (1);
	return (0);
}

void	multi_commands(t_minish *minish, int fork_nbr)
{
	int			i;
	int			one_built;

	i = fork_nbr;
	one_built = 0;
	if (one_valid_cmd(minish) && isbuiltin(minish->all_parsed[0].cmd[0]))
		one_builtin(minish, &one_built);
	while (--i > -1)
	{
		minish->pids[i] = fork();
		if (minish->pids[i] == -1)
			fork_error(minish->pipes, fork_nbr);
		else if (minish->pids[i] == 0)
		{
			if (minish->all_parsed[0].err_code == 2)
				a_synt_error(minish);
			if (one_built == 1)
				quit(minish, fork_nbr, minish->ex_code, i);
			calling_cmds(i, minish, minish->pipes, minish->pids);
		}
	}
	close_all_pipes(minish->pipes, (fork_nbr - 1));
	free(minish->pipes);
	get_pid_status((fork_nbr - 1), minish);
}

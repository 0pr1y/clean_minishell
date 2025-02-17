#include "../../../includes/minishell.h"

void	cmd_execution(int i, t_minish *minish, t_pipes *pipes, pid_t *pids)
{
	char	**args;
	char	**env_paths;

	env_paths = NULL;
	args = minish->all_parsed[i].cmd;
	if (args[0][0] != '\0')
		args = is_executable(minish->all_parsed[i].cmd,
				env_paths, minish->envp);
	if (args == NULL)
	{
		perror("env paths");
		close_all_pipes(pipes, (minish->nb_cmds - 1));
		free(pipes);
		free(pids);
		free_split(minish->envp);
		minish->ex_code = EXIT_FAILURE;
		return ;
	}
	execve(args[0], args, minish->envp);
	failed_execve(args, minish);
}

void	cmd_error(int i, t_minish *minish, int *fd_out, int *fd_in)
{
	int	exit_code;

	exit_code = minish->all_parsed[i].err_code;
	close_all_pipes(minish->pipes, (minish->nb_cmds - 1));
	free(minish->pipes);
	free(minish->pids);
	free_split(minish->envp);
	print_err(minish->all_parsed[i].err_msg);
	free_all_parsed(minish->all_parsed, minish->nb_cmds);
	if ((*fd_out) > STDERR_FILENO)
		close_fd(fd_out);
	if ((*fd_in) > STDIN_FILENO)
		close_fd(fd_in);
	exit(exit_code);
}

int	cmd_null(int i, t_minish *minish)
{
	if (minish->all_parsed[i].cmd == NULL
		&& minish->all_parsed[i].err_code == 0)
		return (1);
	return (0);
}

void	end_of_process(t_minish *minish, t_pipes *pipes, pid_t	*pids)
{
	int	exit_code;

	close_all_pipes(pipes, (minish->nb_cmds - 1));
	free(pipes);
	free(pids);
	free_split(minish->envp);
	exit_code = minish->ex_code;
	free_all_parsed(minish->all_parsed, minish->nb_cmds);
	exit(exit_code);
}

void	calling_cmds(int i, t_minish *minish, t_pipes *pipes, pid_t	*pids)
{
	int	fd_in;
	int	fd_out;

	fd_in = entry_redirs(i, minish, pipes, pids);
	fd_out = exit_redirs(i, minish, pipes, pids);
	if (cmd_null(i, minish))
		close_fds_and_exit(fd_in, fd_out, EXIT_SUCCESS);
	if (minish->all_parsed[i].cmd != NULL)
		cmd_path(minish->all_parsed[i].cmd[0], &minish->all_parsed[i]);
	if (minish->all_parsed[i].err_code != 0)
		cmd_error(i, minish, &fd_out, &fd_in);
	else
	{
		if (isbuiltin(minish->all_parsed[i].cmd[0]))
			close_fds_and_exit(fd_in, fd_out,
				exec_builtin(minish->all_parsed[i].cmd,
					-1, fd_out, &minish->envp));
		else
			cmd_execution(i, minish, pipes, pids);
	}
	if (fd_out > STDERR_FILENO)
		close_fd(&fd_out);
	if (fd_in > STDIN_FILENO)
		close_fd(&fd_in);
	end_of_process(minish, pipes, pids);
}

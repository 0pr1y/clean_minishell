#include "../includes/minishell.h"

bool	isbuiltin(const char *command)
{
	const char	*builtins[] = \
	{
		"cd",
		"echo",
		"env",
		"exit",
		"export",
		"pwd",
		"unset",
	};
	size_t		nb_builtins;
	size_t		i;

	nb_builtins = sizeof(builtins) / sizeof(*builtins);
	i = 0;
	while (i < nb_builtins)
	{
		if (0 == ft_strcmp(command, builtins[i]))
			return (true);
		i++;
	}
	return (false);
}

int	exec_builtin(char **argv, t_fd input_fd, t_fd output_fd, char ***envp)
{
	int	ret_code;

	ret_code = 0;
	errno = 0;
	if (0 == ft_strcmp(argv[0], "echo"))
		ret_code = ft_echo(argv + 1, input_fd, output_fd, envp);
	else if (0 == ft_strcmp(argv[0], "export"))
		ret_code = ft_export(argv + 1, input_fd, output_fd, envp);
	else if (0 == ft_strcmp(argv[0], "exit"))
		ret_code = ft_exit(argv + 1, input_fd, output_fd, envp);
	else if (0 == ft_strcmp(argv[0], "env"))
		ret_code = ft_env(argv + 1, input_fd, output_fd, envp);
	else if (0 == ft_strcmp(argv[0], "unset"))
		ret_code = ft_unset(argv + 1, input_fd, output_fd, envp);
	else if (0 == ft_strcmp(argv[0], "cd"))
		ret_code = ft_cd(argv + 1, input_fd, output_fd, envp);
	else if (0 == ft_strcmp(argv[0], "pwd"))
		ret_code = ft_pwd(argv + 1, input_fd, output_fd, envp);
	return (ret_code);
}

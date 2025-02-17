#include "../../includes/minishell.h"

void	cd_write_error(const char *s1, const char *s2, const char *s3)
{
	write(STDERR_FILENO, s1, ft_strlen(s1));
	write(STDERR_FILENO, s2, ft_strlen(s2));
	write(STDERR_FILENO, s3, ft_strlen(s3));
	write(STDERR_FILENO, "\n", 1);
}

static bool	is_valid_fd_to_close(int fd)
{
	return (fd > 1
		&& fd != STDIN_FILENO
		&& fd != STDOUT_FILENO
		&& fd != STDERR_FILENO);
}

static bool	is_atoiable(const char *str)
{
	int	i;

	if (str[0] != '+' && str[0] != '-' && ft_isdigit(str[0]) != 1)
		return (false);
	i = 1;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (false);
		i++;
	}
	return (true);
}

void	close_fds_and_exit(t_fd input_fd, t_fd output_fd, int ret_code)
{
	if (is_valid_fd_to_close(input_fd))
		close(input_fd);
	if (is_valid_fd_to_close(output_fd))
		close(output_fd);
	exit(ret_code);
}

int	ft_exit(char **arguments, t_fd input_fd, t_fd output_fd, char ***envp)
{
	int	nb_args;

	(void)envp;
	nb_args = 0;
	while (arguments[nb_args] != NULL)
		nb_args++;
	if (1 == isatty(output_fd))
		write(output_fd, "exit\n", 5);
	if (nb_args == 0)
		close_fds_and_exit(input_fd, output_fd, EXIT_SUCCESS);
	if (true == is_atoiable(arguments[0]))
	{
		if (nb_args > 1)
		{
			write(STDERR_FILENO, "minishell: exit: too many arguments\n", 36);
			return (1);
		}
		close_fds_and_exit(input_fd, output_fd, ft_atoi(arguments[0]));
	}
	else
		(cd_write_error("minishell: exit: ",
				arguments[0], ": numeric argument required"),
			close_fds_and_exit(input_fd, output_fd, 2));
	close_fds_and_exit(input_fd, output_fd, EXIT_SUCCESS);
	return (0);
}

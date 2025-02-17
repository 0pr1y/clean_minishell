#include "../../includes/minishell.h"

int	ft_echo(char **arguments, t_fd input_fd, t_fd output_fd, char ***envp)
{
	bool	has_carriage_return;

	(void)input_fd;
	(void)envp;
	has_carriage_return = true;
	if (*arguments != NULL && 0 == ft_strncmp(*arguments, "-n", 3))
	{
		has_carriage_return = false;
		arguments++;
	}
	while (*arguments != NULL)
	{
		write(output_fd, *arguments, ft_strlen(*arguments));
		if (*(arguments + 1) != NULL)
			write(output_fd, " ", 1);
		arguments++;
	}
	if (has_carriage_return == true)
		write(output_fd, "\n", 1);
	if (errno != 0)
	{
		write_error("minishell: echo: write error: ", strerror(errno));
		return (1);
	}
	return (0);
}

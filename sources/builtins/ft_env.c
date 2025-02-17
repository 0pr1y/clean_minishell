#include "../../includes/minishell.h"

int	ft_env(char **arguments, t_fd input_fd, t_fd output_fd, char ***envp)
{
	int	i;

	(void)arguments;
	(void)input_fd;
	i = 0;
	while ((*envp)[i] != NULL)
	{
		write(output_fd, (*envp)[i], ft_strlen((*envp)[i]));
		write(output_fd, "\n", 1);
		i++;
	}
	if (errno != 0)
	{
		write_error("minishell: env: write error: ", strerror(errno));
		return (125);
	}
	return (0);
}

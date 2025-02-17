#include "../../includes/minishell.h"

int	ft_unset(char **arguments, t_fd input_fd, t_fd output_fd, char ***envp)
{
	(void)input_fd;
	(void)output_fd;
	while (*arguments != NULL)
	{
		if (-(*arguments)[0] != '\0' && 1 == ft_unsetenv(*envp, *arguments))
		{
			write_error("minishell: unset: ", strerror(errno));
			return (1);
		}
		arguments++;
	}
	return (0);
}

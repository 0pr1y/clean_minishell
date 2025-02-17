#include "../../includes/minishell.h"

int	ft_pwd(char **arguments, t_fd input_fd, t_fd output_fd, char ***envp)
{
	char	pwd[PATH_MAX];

	(void)arguments;
	(void)input_fd;
	(void)envp;
	if (NULL == getcwd(pwd, sizeof(pwd)))
	{
		write_error("minishell: pwd: ", strerror(errno));
		return (1);
	}
	write(output_fd, pwd, ft_strlen(pwd));
	write(output_fd, "\n", 1);
	return (0);
}

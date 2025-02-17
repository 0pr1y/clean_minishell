#include "../../includes/minishell.h"

static void	cd_write_error(const char *s1, const char *s2, const char *s3)
{
	write(STDERR_FILENO, s1, ft_strlen(s1));
	write(STDERR_FILENO, s2, ft_strlen(s2));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, s3, ft_strlen(s3));
	write(STDERR_FILENO, "\n", 1);
}

static int	go_home(const char **envp)
{
	char	*home;

	home = ft_getenv(envp, "HOME");
	if (home == NULL)
	{
		write(STDERR_FILENO, "minishell: cd: HOME not set\n", 28);
		return (1);
	}
	if (-1 == chdir(home))
	{
		cd_write_error("minishell: cd: ", strerror(errno), home);
		return (1);
	}
	return (0);
}

static int	go_to_dir(const char *path)
{
	if (-1 == chdir(path))
	{
		cd_write_error("minishell: cd: ", path, strerror(errno));
		return (1);
	}
	return (0);
}

static int	set_env_pwd(char ***envp)
{
	char	pwd[PATH_MAX];

	if (NULL != ft_getenv(*(const char ***)envp, "PWD"))
	{
		if (NULL == getcwd(pwd, sizeof(pwd)))
		{
			write_error("minishell: cd: ", strerror(errno));
			return (1);
		}
		if (-1 == ft_setenv(envp, "PWD", pwd, 1))
		{
			write_error("minishell: cd: ", strerror(errno));
			return (1);
		}
	}
	return (0);
}

int	ft_cd(char **arguments, t_fd input_fd, t_fd output_fd, char ***envp)
{
	int		nb_args;
	int		ret;

	(void)input_fd;
	(void)output_fd;
	ret = 0;
	nb_args = 0;
	while (arguments[nb_args] != NULL)
		nb_args++;
	if (nb_args == 0)
		ret = go_home(*(const char ***)envp);
	else if (nb_args == 1)
		ret = go_to_dir(*arguments);
	else
	{
		write(STDERR_FILENO, "minishell: cd: too many arguments\n", 34);
		return (1);
	}
	if (ret != 0)
		return (ret);
	return (set_env_pwd(envp));
}

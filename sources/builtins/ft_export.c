#include "../../includes/minishell.h"

void	export_write_error(const char *s1, const char *s2, const char *s3)
{
	write(STDERR_FILENO, s1, ft_strlen(s1));
	write(STDERR_FILENO, "`", 1);
	write(STDERR_FILENO, s2, ft_strlen(s2));
	write(STDERR_FILENO, "'", 1);
	write(STDERR_FILENO, s3, ft_strlen(s3));
	write(STDERR_FILENO, "\n", 1);
}

bool	isenvkey(char *envvar)
{
	int	i;

	i = 0;
	if (ft_isdigit(envvar[0]) || (ft_isalpha(envvar[0]) == 0
			&& envvar[0] != '_'))
		return (false);
	while (envvar[i] != '\0')
	{
		if (ft_isalnum(envvar[i]) == 0 && envvar[i] != '_')
			return (false);
		i++;
	}
	return (true);
}

static int	export_print_envp(char **envp, t_fd output_fd)
{
	int	key_len;
	int	value_len;
	int	ret_code;

	ret_code = 0;
	while (*envp)
	{
		key_len = ft_strchr(*envp, '=') - *envp;
		value_len = *envp + ft_strlen(*envp) - (ft_strchr(*envp, '=') + 1);
		write(output_fd, "declare -x ", 11);
		write(output_fd, *envp, key_len);
		write(output_fd, "=\"", 2);
		write(output_fd, *envp + key_len + 1, value_len);
		write(output_fd, "\"\n", 2);
		if (errno != 0)
		{
			write_error("minishell: export: write error: ", strerror(errno));
			ret_code = 1;
			break ;
		}
		envp++;
	}
	return (ret_code);
}

int	add_to_env(char **args, char ***envp)
{
	int	ret_code;

	ret_code = 0;
	(*args)[ft_strchr(*args, '=') - *args] = '\0';
	if (isenvkey(*args) == true)
	{
		if (-1 == ft_setenv(envp, *args,
				*args + ft_strlen(*args) + 1, 1))
		{
			(*args)[ft_strlen(*args)] = '=';
			return (write_error("minishell: export: ", strerror(errno)), 1);
		}
	}
	else
		(export_write_error("minishell: export: ",
				*args, ": not a valid identifier"), ret_code = 1);
	(*args)[ft_strlen(*args)] = '=';
	return (ret_code);
}

int	ft_export(char **args, t_fd input_fd, t_fd output_fd, char ***envp)
{
	int	ret_code;

	(void)input_fd;
	ret_code = 0;
	if (*args == NULL)
		return (export_print_envp(*envp, output_fd));
	while (*args != NULL)
	{
		if (NULL != ft_strchr(*args, '=') && (*args)[0] != '=')
			ret_code = add_to_env(args, envp);
		else if (isenvkey(*args) == false)
		{
			export_write_error("minishell: export: ",
				*args, ": not a valid identifier");
			ret_code = 1;
		}
		args++;
	}
	return (ret_code);
}

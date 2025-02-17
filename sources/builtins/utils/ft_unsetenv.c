#include "../../../includes/minishell.h"

int	ft_unsetenv(char **envp, const char *name)
{
	size_t	key_len;
	int		i;

	if (name == NULL || name[0] == '\0' || ft_strchr(name, '='))
	{
		errno = EINVAL;
		return (-1);
	}
	i = -1;
	while (envp[++i] != NULL)
	{
		key_len = ft_strchr(envp[i], '=') - envp[i];
		if (0 == ft_strncmp(envp[i], name, key_len)
			&& ft_strlen(name) == key_len)
			break ;
	}
	if (envp[i] != NULL)
	{
		free(envp[i--]);
		while (envp[++i] != NULL)
			envp[i] = envp[i + 1];
	}
	return (0);
}

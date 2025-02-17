#include "../../../includes/minishell.h"

static int	insert_new_keyvalue(char ***envp, const char *name,
	const char *value)
{
	char	**new_envp;
	int		i;
	size_t	keyvalue_len;

	i = 0;
	while ((*envp)[i] != NULL)
		i++;
	new_envp = (char **)malloc(sizeof(char *) * (i + 2));
	if (new_envp == NULL)
		return (-1);
	(ft_memcpy(new_envp, *envp, sizeof(char *) * i), new_envp[i + 1] = NULL);
	keyvalue_len = ft_strlen(name) + 1 + ft_strlen(value);
	new_envp[i] = (char *)malloc(sizeof(char) * (keyvalue_len + 1));
	if (new_envp[i] == NULL)
	{
		free(new_envp);
		return (-1);
	}
	ft_memcpy(new_envp[i], name, sizeof(char) * ft_strlen(name));
	ft_memcpy(new_envp[i] + ft_strlen(name), "=", sizeof(char) * 1);
	ft_memcpy(new_envp[i] + ft_strlen(name) + 1, value, sizeof(char)
		* ft_strlen(value));
	new_envp[i][keyvalue_len] = '\0';
	(free(*envp), *envp = new_envp);
	return (0);
}

int	ft_setenv(char ***envp, const char *name, const char *value, int overwrite)
{
	size_t	key_len;
	int		i;

	i = -1;
	while ((*envp)[++i] != NULL)
	{
		key_len = ft_strchr((*envp)[i], '=') - (*envp)[i];
		if (0 == ft_strncmp((*envp)[i], name, key_len)
				&& ft_strlen(name) == key_len)
			break ;
	}
	if (overwrite != 0)
		ft_unsetenv(*envp, name);
	if (overwrite == 1 || (*envp)[i] == NULL)
	{
		if (-1 == insert_new_keyvalue(envp, name, value))
		{
			errno = ENOMEM;
			return (-1);
		}
	}
	return (0);
}

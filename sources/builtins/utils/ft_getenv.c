#include "../../../includes/minishell.h"

char	*ft_getenv(const char **envp, const char *name)
{
	int		i;
	size_t	key_len;

	if (name == NULL || name[0] == '\0')
		return (NULL);
	i = 0;
	while (envp[i] != NULL)
	{
		key_len = ft_strchr(envp[i], '=') - envp[i];
		if (0 == ft_strncmp(envp[i], name, key_len)
			&& ft_strlen(name) == key_len)
			return (ft_strchr(envp[i], '=') + 1);
		i++;
	}
	return (NULL);
}

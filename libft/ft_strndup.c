

#include "libft.h"

// copies n chars from a char* and adds a '\0'

char	*ft_strndup(const char *s, int n)
{
	char	*cpy;
	int		i;

	i = 0;
	if (n < 0)
		return (NULL);
	cpy = malloc(sizeof(char) * (n + 1));
	if (cpy == NULL)
		return (NULL);
	while (i < n)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

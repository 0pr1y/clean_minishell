

#include "libft.h"

char	*after_verification_substr(char const *s,
									unsigned int start, size_t len)
{
	char	*resu;
	size_t	i;

	i = 0;
	if (start > ft_strlen(s))
	{
		resu = (char *)malloc(sizeof(char) * 1);
		if (resu == NULL)
			return (NULL);
		resu[0] = '\0';
		return (resu);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	resu = (char *)malloc(sizeof(char) * (len + 1));
	if (resu == NULL)
		return (NULL);
	while (i < len && s[start])
	{
		resu[i] = s[start];
		i++;
		start++;
	}
	resu[i] = '\0';
	return (resu);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	if (!s)
		return (NULL);
	else
		return (after_verification_substr(s, start, len));
}

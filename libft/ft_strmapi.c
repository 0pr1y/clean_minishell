

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*cpy;
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	cpy = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	while (*s)
	{
		cpy[i] = (*f)(i, *s);
		s++;
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
// int main(void)
// {
//     printf("%s\n", ft_strmapi("ouiii", &f));
//     return (0);
// }

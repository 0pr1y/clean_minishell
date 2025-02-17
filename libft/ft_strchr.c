

#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
// int main(void)
// {
//     char *res = ft_strchr("bAnjour", '\0');
//     if(res == NULL)
//         printf("%s\n", "NULL");
//     else
//         printf("%s\n", res);
//     return (0);
// }

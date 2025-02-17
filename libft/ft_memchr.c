

// #include <string.h>
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*cpy;
	size_t	i;

	cpy = (char *)s;
	i = 0;
	while (i < n)
	{
		if (cpy[i] == (char)c)
			return ((char *)cpy + i);
		i++;
	}
	return (NULL);
}
// int main(void)
// {
//     char *res = memchr("AzzzzA", 'A', 1);
//     if(res == NULL)
//         printf("%s\n", "NULL");
//     else
//         printf("%s\n", res);
//     return(0);
// }

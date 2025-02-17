

//#include <stdio.h>
#include <stdlib.h>

void	*ft_memset(void *str, int c, size_t n)
{
	char	*cpy;
	size_t	i;

	cpy = (char *)str;
	i = n;
	while (n != 0)
	{
		*cpy = (char) c;
		n--;
		cpy++;
	}
	return (cpy - i);
}
// int main(void)
// {
//     char str[50];
//     strcpy(str,"This is string.h library function");
//     printf("%s\n", (char*)ft_memset(str, 38, 0));
//     printf("%s\n", (char*)memset(str, 38, 0));
//     return (0);
// }

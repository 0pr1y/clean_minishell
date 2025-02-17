

#include <stdlib.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*cpy;

	cpy = (char *)s;
	while (n != 0)
	{
		*cpy = 0;
		n--;
		cpy++;
	}
}
// int main(void)
// {
//     char str[50];

//     strcpy(str,"This is string.h library function");

//     ft_bzero(str, 2);
//     printf("%s\n", str);

//     return (0);
// }

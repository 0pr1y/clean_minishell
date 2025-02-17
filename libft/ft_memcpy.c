

//#include <stdio.h>
//#include <string.h>
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*cpy_dest;
	char	*cpy_src;

	if (src == NULL && dest == NULL)
		return (NULL);
	cpy_dest = (char *)dest;
	cpy_src = (char *)src;
	while (n != 0)
	{
		*cpy_dest = *cpy_src;
		n--;
		cpy_dest++;
		cpy_src++;
	}
	return (dest);
}
// int main(void)
// {
//     // const char src[50] = "Heloooo!!";
//     char dest[7];
//     char *src = dest + 2;
//     strcpy(dest,"abcdef");
//     printf("Before memcpy src = %s\n", src);
//     printf("Before memcpy dest = %s\n", dest);
//     memcpy(dest, src, 4);
//     printf("After memcpy src = %s\n", src);
//     printf("After memcpy dest = %s\n", dest);
//     return(0);
// }

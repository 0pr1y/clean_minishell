

// #include <stdio.h>
// #include <string.h>
#include "libft.h"

// void *ft_memcpy(void *dest, const void * src, size_t n)
// {
//   char *cpy_dest;
//   char *cpy_src;
//   cpy_dest = (char*)dest;
//   cpy_src = (char*)src;
//   while(n != 0)
//   {
//       *cpy_dest = *cpy_src;
//       n--;
//       cpy_dest++;
//       cpy_src++;
//   }
//   return(dest);
// }
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*cpy;
	char	*cpy_src;
	int		i;

	if (src > dest)
	{
		dest = ft_memcpy(dest, src, n);
	}
	else
	{
		cpy = (char *)dest;
		cpy_src = (char *)src;
		i = (int)n - 1;
		while (i >= 0)
		{
			cpy[i] = cpy_src[i];
			i--;
		}
	}
	return (dest);
}
// void print_elements(char *array, int size)
// {
//   int i;
//   printf ("Elements : ");
//   for (i = 0; i < size; i++) {
//     printf ("%c, ", array[i]);
//   }
//   printf (" ");
// }
// int main()
// {
// char sResult[] = {1, 2, 3, 4, 5, 6, 7};
//               // {1, 1, 2, 4, 5, 6, 7};
// ft_memmove(sResult + 1, sResult, 2);
// for (int i; i < 7;i++)
//     {
//         printf("%d", sResult[i]);
//         printf(" ");
//     }
//   char c_array[] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};
//   char c_array2[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
//   print_elements(c_array, sizeof(c_array));
//   printf("\n");
//   printf("After ft_memmove()\n");
//   ft_memmove((void *)&c_array[0], (void *)&c_array2[0], 9);
//   print_elements(c_array, sizeof(c_array));
//   printf("\nARRAY2 : \n");
//   print_elements(c_array2, sizeof(c_array2));
//   printf("\n");
// //  printf("After memmove()\n");
// //   memmove((void *)&c_array[0], (void *)&c_array2[0], 10);
// //   print_elements(c_array, sizeof(c_array));
// //   print_elements(c_array2, sizeof(c_array2));
// //   printf("\n");
// }

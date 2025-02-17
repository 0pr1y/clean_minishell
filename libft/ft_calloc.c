
#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (size != 0 && nmemb > (SIZE_MAX / 2) / size)
		return (NULL);
	result = malloc(nmemb * size);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, nmemb * size);
	return (result);
}
// int main(void)
// {
// 	 printf("La valeur maximale de size_t (SIZE_MAX) est : %zu\n", 
// 9223372036854775808);
// 	 printf("La valeur maximale de size_t (SIZE_MAX) est : %zu\n", 
// SIZE_MAX / 2);
// ft_calloc(18446744073709551615UL, 18446744073709551615UL);
// printf("%p", calloc(-5, -5));
// void *truc = ft_calloc(-2, -7);
// if(truc == NULL)
//     printf("%s\n", "NULL");
// else
//     printf("%ld\n", strlen(truc));
// size_t truc = 18446744073709551615;
// printf("unsigned %zu\n", truc);
// printf("signed %zd\n", truc);
//     return (0);
// }

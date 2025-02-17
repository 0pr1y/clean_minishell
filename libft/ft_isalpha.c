

// #include <stdio.h>
// #include <ctype.h>
#include "libft.h"

int	ft_isalpha(int character)
{
	if ((character >= 'A' && character <= 'Z')
		|| (character >= 'a' && character <= 'z'))
		return (1);
	return (0);
}
// int main(void)
// {
//     printf("F : %d\n",ft_isalpha('F'));
//     printf("%d\n",isalpha('F'));
//     printf("%d\n",ft_isalpha('a'));
//     printf("%d\n",isalpha('a'));
//     printf("%d\n",ft_isalpha(125));
//     printf("%d\n",isalpha(125));
//     return (0);
// }

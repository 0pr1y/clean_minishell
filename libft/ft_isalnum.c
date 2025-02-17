

// #include <stdio.h>
// #include <ctype.h>
#include "libft.h"

int	ft_isalnum(int argument)
{
	if ((argument >= 'A' && argument <= 'Z')
		|| (argument >= 'a' && argument <= 'z')
		|| (argument >= '0' && argument <= '9'))
		return (1);
	return (0);
}
// int main(void)
// {
//     printf("%d\n",ft_isalnum('Q'));
//     printf("%d\n",isalnum('Q'));
//     printf("%d\n",ft_isalnum('5'));
//     printf("%d\n",isalnum('5'));
//     printf("%d\n",ft_isalnum('y'));
//     printf("%d\n",isalnum('y'));
//     printf("%d\n",ft_isalnum('+'));
//     printf("%d\n",isalnum('+'));    
//     return (0);
// }

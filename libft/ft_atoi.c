

// #include <stdlib.h>
// #include <stdio.h>
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	is_negative;

	result = 0;
	is_negative = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			is_negative = -1;
		nptr++;
	}
	if (! (*nptr >= '0' && *nptr <= '9'))
		return (0);
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + *nptr - '0';
		nptr++;
		if (!(*nptr >= '0' && *nptr <= '9') || *nptr == '\0')
			return (result * is_negative);
	}
	return (0);
}
// int main(void)
// {
//     printf("%d\n", atoi(" \t\n\r\v\f-2147483649-9"));
//     return (0);
// }

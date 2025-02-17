

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	count_numbers(int n)
{
	int	counter;

	counter = 0;
	if (n < 0)
	{
		counter++;
		n *= -1;
	}
	while (n >= 0)
	{
		n /= 10;
		counter++;
		if (n == 0)
			break ;
	}
	return (counter);
}

char	*n_is_borderline(int n)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	return ((char *) NULL);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		counter;
	int		i;

	i = 1;
	if (n == -2147483648 || n == 0)
		return (n_is_borderline(n));
	counter = count_numbers(n);
	result = (char *)malloc(sizeof(char) * (counter + 1));
	if (result == NULL)
		return (NULL);
	result[counter] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		result[counter - i] = (n % 10) + 48;
		n /= 10;
		i++;
	}
	return (result);
}
// int main(void)
// {
// 	ft_itoa(000);
// 	return (0);
// }

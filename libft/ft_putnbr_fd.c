

// #include <stdio.h>
#include <unistd.h>
#include "libft.h"

int	number_of_digits(int n)
{
	int	result;

	result = 1;
	n = n / 10;
	while (n)
	{
		result *= 10;
		n /= 10;
	}
	return (result);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		times;
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	times = number_of_digits(n);
	while (times)
	{
		c = n / times + '0';
		write(fd, &c, 1);
		n %= times;
		times /= 10;
	}
	return ;
}
// int main(void)
// {
//     	ft_putnbr_fd(987, 1);
//     return (0);
// }

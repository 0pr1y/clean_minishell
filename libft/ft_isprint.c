

// #include <ctype.h>
// #include <stdio.h>

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
// int main(void)
// {
//     printf("%d\n", ft_isprint(-2));
//     printf("%d\n", isprint(-2));
//     printf("%d\n", ft_isprint(37));
//     printf("%d\n", isprint(37));

//     return (0);
// }

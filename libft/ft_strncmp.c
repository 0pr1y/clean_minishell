

#include <string.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (!s1[i] && !s2[i])
			return (0);
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
// void	ft_print_result(int n)
// {
// 	if (n > 0)
// 		write(1, "1", 1);
// 	else if (n < 0)
// 		write(1, "-1", 2);
// 	else
// 		write(1, "0", 1);
// }
// int main(void)
// {
// 		printf("ATTENDU : %d\n", -1);
// 		ft_print_result(ft_strncmp("", "test", 4));
// 		printf("\n???ATTENDU : %d\n", 0);
// 		ft_print_result(ft_strncmp("test\200", "test\0", 6));
// 		printf("\n");
//     printf("moya %d\n", ft_strncmp("obc", "abazz", 5));
//     printf("%d\n", strncmp("", "", 1));
// ft_strncmp("Tripouille", "Tripouill", 42)
//     return (0);
// }

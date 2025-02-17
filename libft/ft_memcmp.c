

#include <string.h>
// #include <unistd.h>
// #include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*p1;
	const char	*p2;

	p1 = (const char *) s1;
	p2 = (const char *) s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
		{
			if (p1[i] == '\0')
				return (-1);
			if (p2[i] == '\0')
				return (1);
			return ((int)((unsigned char)p1[i] - (unsigned char)p2[i]));
		}
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
// 	void *truc = NULL;
// 	printf("OFFICIEL :\n");
// 	ft_print_result(memcmp(truc, "\2", 2));
// 	printf("\n");
// 	printf("LE MIEN :\n");
// 	ft_print_result(ft_memcmp(truc, "\2", 2));
// 	printf("\n");
// const char*s1 = "aaaa";
// const char*s2 = "truc";
// char s2[] = {0, 0, 127, 0};
// char s[] = {-128, 0, 127, 0};
// printf("%d\n", ft_memcmp(s1, s2, 4));
// printf("%d\n", memcmp(s, s2, 1));
// printf("%d\n", memcmp(s2, s, 1));
//     return (0);
// }

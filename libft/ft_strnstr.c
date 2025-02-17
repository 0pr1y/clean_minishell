

//#include <bsd/string.h>
// #include <stdio.h>
// #include <unistd.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	neelen;

	i = 0;
	if (!*needle || haystack == needle)
		return ((char *)haystack);
	if (ft_strlen(needle) > ft_strlen(haystack) || len == 0)
		return (0);
	neelen = ft_strlen((char *)needle);
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			if (len - i >= ft_strlen(needle))
			{
				if (ft_strncmp(haystack + i, needle, neelen) == 0)
					return ((char *)haystack + i);
			}
		}
		i++;
	}
	return (0);
}
// void	ft_print_result(char const *s)
// {
// 	int		len;
// 	len = 0;
// 	while (s[len])
// 		len++;
// 	write(1, s, len);
// }
// int main(void)
// {
// 	const char *str;
// printf("ATTENDU : %s\n", "NULL");
// if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 30)))
// 		ft_print_result("NULL");
// 	else
// 		ft_print_result(str);
// printf("\n");
// printf("ATTENDU : %s\n", "NULL");
// if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "dolor", 17)))
// 		ft_print_result("NULL\n");
// 	else
// 		ft_print_result(str);
//     char haystack[30] = "aaabcabcd";
// 	char needle[10] = "aabc";
//     printf("%s\n", ft_strnstr(haystack, needle, 0));
// 
//     char *ret = ft_strnstr("test string", "string", 7);
//     // char *ret = strnstr("7tes_te_____test", "test", 20000000000000);
//     if (ret == NULL)
//         printf("NULL\n");
//     // else
//         // printf("%s\n", ret);
//     printf("1 %d\n", test("test", "t", 5));
//     printf("2 %d\n", test("test string", "string", 20));
//     printf("3 %d\n", test("test string", "string", 20000000));
//     printf("4 %d\n", test("test string", "", 20));
//     printf("5 %d\n", test("test string", "string", 4));
//     printf("6 %d\n", test("test string", "string", 7));
//     printf("7 %d\n", test("test string", "test", 0));
//     printf("8 %d\n", test("strinstring", "string", 6));
// const char* needle = NULL;
// const char* haystack = "truc";
// printf("%s\n", ft_strnstr(haystack, needle, 0));
//     return (0);
// }

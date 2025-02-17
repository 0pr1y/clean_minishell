

#include "libft.h"
// #include <bsd/string.h>
// #include <string.h>
// #include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && size > 1)
	{
		dst[i] = src[i];
		i++;
		size--;
	}
	if (size > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}
// int main(void)
// {
//     char src[] = "coucou";
// 	char dest[10]; memset(dest, 'A', 10);
//     // printf("DEBUT %s\n", dest);
// /* 1 */ strlcpy(dest, src, 0
// // printf("1 : %ld\n", strlcpy(dest, src, 0));
// printf("1 dest[0]: %d\n", dest[0]);
// // /* 1 */ ft_strlcpy(dest, src, 0);
// printf("ft 1 : %ld\n", ft_strlcpy(dest, src, 0));
// printf("ft 1 dest[0]: %d\n", dest[0]);
// // 	/* 2 */ strlcpy(dest, src, 1);
// //     printf("2 : %s\n", dest);
// 	/* 2 */ ft_strlcpy(dest, src, 1);
//     printf("ft 2 : %s\n", dest);
// // 	/* 3 */ strlcpy(dest, src, 2);
// //     printf("3 : %s\n", dest);
// 	/* 3 */ ft_strlcpy(dest, src, 2);
//     printf("ft 3 : %s\n", dest);
// // 	/* 4 */ strlcpy(dest, src, -1); memset(dest, 'A', 10);
// //     printf("4 : %s\n", dest);
// 	/* 4 */ ft_strlcpy(dest, src, -1); memset(dest, 'A', 10);
//     printf("ft 4 : %s\n", dest);
// // 	/* 5 */ strlcpy(dest, src, 6); memset(dest, 'A', 10);
// //     printf("5 : %s\n", dest);
// 	/* 5 */ ft_strlcpy(dest, src, 6); memset(dest, 'A', 10);
//     printf("ft 5 : %s\n", dest);
// // 	/* 6 */ strlcpy(dest, src, 7); memset(dest, 'A', 10);
// //     printf("6 : %s\n", dest);
// 	/* 6 */ ft_strlcpy(dest, src, 7); memset(dest, 'A', 10);
//     printf("ft 6 : %s\n", dest);
// // 	/* 7 */ strlcpy(dest, src, 8); memset(dest, 'A', 10);
// //     printf("7 : %s\n", dest);
//     /* 7 */ ft_strlcpy(dest, src, 8); memset(dest, 'A', 10);
//     printf("ft 7 : %s\n", dest);
// // 	/* 8 */ strlcpy(dest, "", 42); memset(dest, 'A', 10);
// //     printf("8 : %s\n", dest);
//     /* 8 */ ft_strlcpy(dest, "", 42); memset(dest, 'A', 10);
//     printf("ft 8 : %s\n", dest);
// // 	/* 9 */ strlcpy(dest, "1", 0); memset(dest, 'A', 10);
// //     printf("9 : %s\n", dest);
//     /* 9 */ ft_strlcpy(dest, "1", 0); memset(dest, 'A', 10);
//     printf("ft 9 : %s\n", dest);
//     return (0);
// }

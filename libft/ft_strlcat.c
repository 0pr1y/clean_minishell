

// #include <bsd/string.h>
// #include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((dst && ft_strlen(dst) > dstsize) || (dstsize == 0 && !dst))
		return (ft_strlen(src) + dstsize);
	len = ft_strlen(dst) + ft_strlen(src);
	while (dst[i])
	{
		dstsize--;
		i++;
	}
	while (src[j] && dstsize > 1)
	{
		dst[i++] = src[j++];
		dstsize--;
	}
	dst[i] = '\0';
	return (len);
}
// int main(void)
// {
//     char dst[20];
//     char dst1[20];
//     char *src = "abcd";
//     ft_strlcpy(dst,"UUU", 3);
//     ft_strlcpy(dst1,"UUU", 9);
//     printf("AFTER MINE : %ld\n", ft_strlen(dst1));
//     // printf("BEFORE TRUE : %ld\n", ft_strlen(dst));
//     // printf("BEFORE MINE : %ld\n", ft_strlen(dst1));
//     // printf("MINE : %ld\n", ft_strlcat(dst1, src, 6));
//     // printf("TRUE : %ld\n", strlcat(dst, src, 6));    
//     // strlcat(dst, src, 6);
//     // ft_strlcat(dst, src, -6);
//     // printf("AFTER TRUE : %s\n", dst);
//     ft_strlcat(dst1, src, -8);
//     printf("AFTER MINE : %ld\n", ft_strlcat(dst1, src, -8));
//     return (0);
// }
// size_t	dst_concat_src(char *cpy_src, char *dst, size_t length)
// {
// 	while (*cpy_src)
// 	{
// 		dst[length] = *cpy_src;
// 		length++;
// 		cpy_src++;
// 	}
// 	dst[ft_strlen(dst)+length] = '\0';
// 	return (ft_strlen(dst));
// }
// size_t	ft_strlcat(char *dst, const char *src, size_t size)
// {
// 	size_t	length;
// 	size_t	result;
// 	char	*cpy_src;
// 	length = 0;
// 	cpy_src = (char *)src;
// 	while (dst[length] != '\0')
// 		length++;
// 	if ((long long) size < 0)
// 		return (dst_concat_src(cpy_src, dst, length));
// 	if (size <= ft_strlen(dst))
// 		return (ft_strlen(src) + size);
// 	else
// 		result = ft_strlen(dst) + ft_strlen(src);
// 	while (length < size - 1)
// 	{
// 		dst[length] = *cpy_src;
// 		length++;
// 		cpy_src++;
// 	}
// 	dst[length] = '\0';
// 	return (result);
// }

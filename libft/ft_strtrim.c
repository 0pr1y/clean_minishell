

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	char	*result2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, s1[i]) != NULL && s1[i] != '\0')
		i++;
	result = (char *)s1 + i;
	i = ft_strlen(result) - 1;
	while (i >= 0 && ft_strchr(set, result[i]) != NULL)
		i--;
	result2 = (char *)malloc(sizeof(char) * (i + 2));
	if (result2 == NULL)
		return (NULL);
	result2[i + 1] = '\0';
	while (j <= i)
	{
		result2[j] = result[j];
		j++;
	}
	return (result2);
}
// int main(void)
// {
//     char * s = ft_strtrim("   xxx   xxx", " ");
//     int i = 0;
//     while(s[i])
//         printf("%c\n", s[i++]);
//     printf("%ld\n", 1);
//     // printf("%s\n", ft_strtrim("wqqwq", "q"));
//     free(s);
//     return (0);
// }



#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, ft_strlen(s1) + 1);
	ft_strlcat(result + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (result);
}
// int main(void)
// {
//     printf("%s\n", ft_strjoin("bonjour ", "bob"));
//     return (0);
// }

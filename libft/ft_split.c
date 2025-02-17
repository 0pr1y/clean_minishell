

#include "libft.h"

char	*ft_strcdup(char *s, char c)
{
	char	*cpy;
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	cpy = malloc(sizeof(char) * (i + 1));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (*s != c && *s)
	{
		cpy[i] = *s;
		s++;
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

int	assign_counter(int i, char *trimmed, int c_counter, char c)
{
	while (trimmed[i] != '\0')
	{
		while (trimmed[i] == c)
		{
			i++;
			if (trimmed[i] != c)
				c_counter++;
		}
		i++;
	}
	return (c_counter);
}

char	**find_result(char **result, char *trimmed, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (trimmed[j])
	{
		if (trimmed[j] != c)
		{
			result[i] = ft_strcdup(trimmed + j, c);
			j += ft_strlen(result[i]);
			i++;
			continue ;
		}
		j++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	char	*trimmed;
	char	c_to_trim[2];
	int		c_counter;
	int		i;

	c_to_trim[0] = c;
	c_to_trim[1] = '\0';
	c_counter = 0;
	i = 0;
	trimmed = ft_strtrim(s, c_to_trim);
	if (trimmed == NULL)
		return (NULL);
	if (trimmed[0])
		c_counter++;
	c_counter = assign_counter(i, trimmed, c_counter, c);
	result = (char **)malloc(sizeof(char *) * (c_counter + 1));
	if (result == NULL)
		return (NULL);
	result[c_counter] = NULL;
	result = find_result(result, trimmed, c);
	free(trimmed);
	return (result);
}
// int main(void)
// {
//     char **res = ft_split("  tripouille  42  YYY", ' ');
//     if (res)
//         for (int i = 0; res[i] != NULL; i++)
//             free(res[i]);
//     free(res);
//     //
//     // char *s = ft_strtrim("      ", " ");
//     // printf("%s\n", s);
//     // free(s);
//     //
//     // char const *s = "   v khb       ";
//     // char c =' ';
//     // char **truc = ft_split("tripouille", 0);
//     // if(strcmp(truc[0], "tripouille") == 0 && truc[1] == NULL)
//     //     printf("%s\n", "7 bon");
//     // else
//     //     printf("7 pas bon : %s\n ET %s\n", truc[0], truc[1]);
//     // truc = ft_split("     ", ' ');
//     // if(truc[0] == NULL)
//     //     printf("%s\n", "9 bon");
//     // else
//     //     printf("%s\n", "9 pas bon");
// 	// truc = ft_split("\0", 0);
//     // if(truc[0] == NULL)
//     //     printf("%s\n", "10 bon");
//     // else
//     //     printf("%s\n", "10 pas bon");
//     // int i = 0;
//     // while(truc[i] != 0)
//     // {
//     //     printf("%s\n", truc[i]);
//     //     i++;
//     // }
//     // char **res = ft_split("YaYbYYtY", 'i');
//     // // ft_split("YaYbYYY", 'Y');
//     // for(int i = 0; res[i] != NULL; i++)
//     //     printf("%s\n", res[i]);
//     return(0);
// }

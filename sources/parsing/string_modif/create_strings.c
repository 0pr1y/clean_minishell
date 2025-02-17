#include "../../../includes/minishell.h"

void	add_str(char ***src, char *new, int *size)
{
	int		i;
	char	**dst;

	i = 0;
	while ((*src) && (*src)[i] != NULL)
		i++;
	dst = malloc(sizeof(char *) * (i + 1 + 1));
	if (dst == NULL)
		exit(EXIT_FAILURE);
	ft_memcpy(dst, *src, sizeof(char *) * i);
	dst[i] = ft_strdup(new);
	if (dst[i] == NULL)
		exit(EXIT_FAILURE);
	dst[i + 1] = NULL;
	free(*src);
	*src = dst;
	(*size)++;
}

char	*build_substring(char *line, unsigned int end, char **dst)
{
	if (dst != NULL)
		free(*dst);
	*dst = NULL;
	*dst = ft_strndup(line, end + 1);
	failed_malloc(dst);
	return (*dst);
}

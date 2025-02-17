#include "../../../includes/minishell.h"

void	erase_var(char *line, int *i, int to_dol, int *limit)
{
	(*i)--;
	while (line[to_dol] != '\0')
	{
		line[*i] = line[to_dol];
		to_dol++;
		(*i)++;
	}
	line[*i] = '\0';
	(*limit) = *i;
}

void	new_limit(char *line, char *var_value, int *i, int *limit)
{
	int	var_len;

	if (var_value == NULL)
		return ;
	var_len = (int)ft_strlen(var_value);
	if (var_len <= (int)ft_strlen(line))
	{
		*limit = var_len;
		*i = var_len;
	}
	else
	{
		*limit = (int)ft_strlen(line);
		*i = (int)ft_strlen(line);
	}
}

void	key_to_value(char *var_value, char **line, int key_len, int to_dol)
{
	char	*tail;
	char	*head;

	if (var_value == NULL)
		return ;
	tail = ft_strjoin(var_value, (*line) + key_len);
	failed_malloc(tail);
	head = (char *)malloc(sizeof(char) * (to_dol));
	failed_malloc(head);
	ft_strlcpy(head, (*line), to_dol);
	free((*line));
	(*line) = ft_strjoin(head, tail);
	failed_malloc((*line));
	free(head);
	free(tail);
}

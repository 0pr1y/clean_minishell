#include "../../../includes/minishell.h"

char	*reduce_str(char *str, int strt, int end)
{
	while (str[strt] != '\0')
	{
		str[strt] = str[strt + 1];
		strt++;
	}
	while (str[end] != '\0')
	{
		str[end] = str[end + 1];
		end++;
	}
	return (str);
}

char	*no_quotes(char *str)
{
	int		i;
	int		j;
	char	quote;

	j = 0;
	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		if ((str[i] && str[i] == '\'')
			|| (str[i] && str[i] == '"'))
		{
			quote = str[i];
			j = i;
			i++;
			while (str[i] && str[i] != quote)
				i++;
			str = reduce_str(str, j, i - 1);
			i -= 1;
		}
		else
			i++;
	}
	return (str);
}

void	dequote_parsed(t_parsed *parsed)
{
	int	i;

	i = -1;
	if (parsed->cmd != NULL)
		while (parsed->cmd[++i] != NULL)
			parsed->cmd[i] = no_quotes(parsed->cmd[i]);
	i = -1;
	if (parsed->lim && parsed->lim != NULL)
	{
		while (parsed->lim[++i] != NULL)
			parsed->lim[i] = no_quotes(parsed->lim[i]);
	}
	parsed->exit = no_quotes(parsed->exit);
	parsed->entry = no_quotes(parsed->entry);
}

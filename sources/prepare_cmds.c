#include "../includes/minishell.h"

int	count_chars(char *str, char c)
{
	int		i;
	int		counter;
	char	quote;

	i = 0;
	counter = 0;
	if (str == NULL || str[0] == '\0')
		return (0);
	while (i < (int)ft_strlen(str))
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			quote = str[i];
			i++;
			while (str[i] && str[i] != quote)
				i++;
		}
		if (str[i] && str[i] == c)
			counter++;
		i++;
	}
	return (counter);
}

void	parsed_init(t_minish *minish, char *line)
{
	minish->nb_cmds = count_chars(line, '|');
	minish->nb_cmds++;
	if (minish->nb_cmds > MAX_NB_CMDS)
		minish->nb_cmds = MAX_NB_CMDS;
	minish->all_parsed = (t_parsed *)malloc(sizeof(t_parsed)
			* (minish->nb_cmds));
	if (minish->all_parsed == NULL)
		exit(EXIT_FAILURE);
	ft_memset(minish->all_parsed, 0, sizeof(t_parsed)
		* (minish->nb_cmds));
}

void	one_cmd_end(int *j, char *line)
{
	while (line[*j] != '\0' && line[*j] != '|')
	{
		if (line[*j] == '\'' || line[*j] == '"')
			quote_to_quote(j, line, line[*j]);
		(*j)++;
	}
}

void	no_synt_error(t_minish *minish, char *line)
{
	char	*sub_line;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (minish->all_parsed[0].lim != NULL)
		words_free(minish->all_parsed[0].lim);
	while (i < minish->nb_cmds)
	{
		one_cmd_end(&j, line);
		sub_line = ft_strndup(line + k, j - k);
		failed_malloc(sub_line);
		parsing(&minish->all_parsed[i], sub_line, minish, 1);
		j++;
		k = j;
		i++;
		free(sub_line);
	}
}

void	obtain_cmds(char *line, t_minish *minish)
{
	opened_quotes(line, 1, line);
	parsed_init(minish, line);
	syntax_error(line, &minish->all_parsed[0]);
	if (minish->all_parsed[0].err_code == 2
		&& minish->all_parsed[0].err_msg != NULL)
		minish->nb_cmds = 1;
	else
		no_synt_error(minish, line);
}

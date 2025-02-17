#include "../../includes/minishell.h"

void	skip_spaces(int *i, char *line)
{
	while (line[(*i)] != '\0' && line[(*i)] == ' ')
		(*i)++;
}

void	quote_to_quote(int *j, char *line, char quote)
{
	int	strt;

	strt = *j + 1;
	while (line[strt] != '\0' && (line[strt] != quote))
		strt++;
	*j = strt;
}

void	another_end(char *line, int *j)
{
	while (line[*j] != '\0' && line[*j] != ' ')
	{
		if (line[*j] == '<' || line[*j] == '>' || line[*j] == '|')
		{
			(*j)--;
			break ;
		}
		if (line[*j] == '\'' || line[*j] == '"')
			quote_to_quote(j, line, line[*j]);
		(*j)++;
	}
}

int	end_of_word(int *i, char *line)
{
	int	strt;
	int	j;

	strt = *i;
	j = strt + 1;
	if (line[*i] == ' ' || line[*i] == '\0'
		|| line[*i] == '<' || line[*i] == '>' || line[*i] == '|')
		return (*i -= 1, 0);
	if (line[strt] == '\'' || line[strt] == '"')
	{
		j = strt;
		quote_to_quote(&j, line, line[strt]);
	}
	else
		another_end(line, &j);
	if (line[j] == '\0' || line[j] == ' ')
		j--;
	*i = j + 1;
	return (1);
}

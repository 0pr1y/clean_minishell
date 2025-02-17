#include "../../../includes/minishell.h"

char	*limiters(char *line, int *i, t_parsed *parsed)
{
	int		end;
	char	*buffer;

	buffer = NULL;
	(*i) += 2;
	skip_spaces(i, line);
	if (line[*i] == '|')
		before_pipe(parsed, line, *i);
	else if (line[*i] == '<')
		before_entry(parsed, line, *i);
	else if (line[*i] == '>')
		before_exit(parsed, line, *i);
	else if (line[*i] == '&')
		before_ampersand(parsed, line, *i);
	else if (line[*i] == '\0')
		syntax_err_msg(parsed, '\0', '\0', '\0');
	else
	{
		end = *i;
		while (end_of_word(&end, line) == 1)
			build_substring(line + (*i), end - (*i) - 1, &buffer);
		*i = end;
	}
	return (buffer);
}

void	add_lim(char *buffer, int *lim_size, t_parsed *parsed)
{
	if (buffer != NULL)
	{
		buffer = no_quotes(buffer);
		add_str(&parsed->lim, buffer, lim_size);
		free(buffer);
		buffer = NULL;
	}
}

void	entries_n_exits(char *line, int *i, t_parsed *parsed)
{
	int	end;

	if (line[*i] == '<' && line[(*i) + 1] == '>')
		(*i)++;
	else if (line[*i] == '>' && line[(*i) + 1] == '>')
		(*i)++;
	(*i)++;
	skip_spaces(i, line);
	end = (*i);
	if (line[*i] == '|')
		before_pipe(parsed, line, *i);
	else if (line[*i] == '<')
		before_entry(parsed, line, *i);
	else if (line[*i] == '>')
		before_exit(parsed, line, *i);
	else if (line[*i] == '&')
		before_ampersand(parsed, line, *i);
	else if (line[*i] == '\0')
		syntax_err_msg(parsed, '\0', '\0', '\0');
	else
	{
		while (end_of_word(&end, line) == 1)
			(*i) = end;
	}
}

void	pipes(char *line, int *i, t_parsed *parsed)
{
	(*i)++;
	skip_spaces(i, line);
	if (line[*i] == '|')
		before_pipe(parsed, line, *i);
	else if (line[*i] == '&')
		before_ampersand(parsed, line, *i);
	else if (line[*i] == '\0')
		syntax_err_msg(parsed, '\0', '\0', '\0');
	if (line[*i] == '<' || line[*i] == '>')
		(*i)--;
}

void	syntax_error(char *line, t_parsed *parsed)
{
	int	i;
	int	lim_size;

	i = 0;
	lim_size = 1;
	ft_memset(parsed, 0, sizeof(t_parsed));
	if (pipe_first(line, parsed))
		return ;
	while (i < (int)ft_strlen(line) && parsed->err_msg == NULL)
	{
		skip_spaces(&i, line);
		if (line[i] == '\'' || line[i] == '"')
			quote_to_quote(&i, line, line[i]);
		if (line[i] == '<' && line[i + 1] == '<')
			add_lim(limiters(line, &i, parsed), &lim_size, parsed);
		else if (line[i] == '<' || line[i] == '>')
			entries_n_exits(line, &i, parsed);
		else if (line[i] == '|')
			pipes(line, &i, parsed);
		i++;
	}
	return ;
}

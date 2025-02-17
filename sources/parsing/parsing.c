#include "../../includes/minishell.h"

char	*detec_signs(char *line, int *i, t_parsed *parsed)
{
	int		end;
	int		strt;
	char	*result;

	if (parsed->err_msg != NULL)
		return (NULL);
	result = NULL;
	strt = *i;
	end = strt;
	while (end_of_word(&end, line) == 1)
		build_substring(line + strt, end - strt - 1, &result);
	*i = end;
	return (result);
}

void	detec_redir(t_line_n_ind lni, int *lim_size,
					t_parsed *parsed, t_minish *minish)
{
	char	sign;
	int		strt;

	sign = lni.line[*lni.i];
	strt = *lni.i + 1;
	while (lni.line[strt] == ' ')
		strt++;
	if (lni.line[strt] == sign && sign == '<')
		*lni.i = delim(lni.line, strt, parsed, lim_size);
	if (parsed->err_msg == NULL)
	{
		if (lni.line[strt] != sign && sign == '<')
			*lni.i = entry(lni.line, strt, parsed, minish);
		else if (sign == '>')
			*lni.i = ext(lni.line, *lni.i + 1, parsed, minish);
	}
	return ;
}

void	add_cmd(t_line_n_ind lni, int *cmd_size,
				t_parsed *parsed, t_minish *minish)
{
	char		*buffer;

	buffer = detec_signs(lni.line, lni.i, parsed);
	expand(&buffer, minish);
	if (buffer != NULL)
		add_str(&parsed->cmd, buffer, cmd_size);
	free(buffer);
}

void	parsing(t_parsed *parsed, char *line, t_minish *minish, int init)
{
	t_line_n_ind	lni;
	int				cmd_size;
	int				lim_size;

	cmd_size = 1;
	lim_size = 1;
	lni.line = line;
	ft_memset(parsed, 0, sizeof(t_parsed));
	lni.i = &init;
	(*lni.i)--;
	while (*lni.i < (int)ft_strlen(line))
	{
		if (line[*lni.i] == '\'')
			add_cmd(lni, &cmd_size, parsed, minish);
		else if (line[*lni.i] == '"')
			add_cmd(lni, &cmd_size, parsed, minish);
		else if (line[*lni.i] != ' ' && line[*lni.i] != '<'
			&& line[*lni.i] != '>')
			add_cmd(lni, &cmd_size, parsed, minish);
		else if (line[*lni.i] == '<' || line[*lni.i] == '>')
			detec_redir(lni, &lim_size, parsed, minish);
		(*lni.i)++;
	}
	dequote_parsed(parsed);
	return ;
}

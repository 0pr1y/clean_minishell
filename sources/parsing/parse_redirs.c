#include "../../includes/minishell.h"

int	delim(char *line, int strt, t_parsed *parsed, int *lim_size)
{
	int		end;
	char	*limiter;

	limiter = NULL;
	strt++;
	skip_spaces(&strt, line);
	end = strt;
	while (end_of_word(&end, line) == 1)
		build_substring(line + strt, end - strt - 1, &limiter);
	if (limiter != NULL)
	{
		add_str(&parsed->lim, limiter, lim_size);
		if (parsed->entry != NULL)
		{
			free(parsed->entry);
			parsed->entry = NULL;
		}
		free(limiter);
	}
	return (end);
}

int	entry(char *line, int strt, t_parsed *parsed, t_minish *minish)
{
	int	end;

	end = strt;
	if (parsed->entry != NULL)
	{
		free(parsed->entry);
		parsed->entry = NULL;
	}
	while (end_of_word(&end, line) == 1)
		build_substring(line + strt, end - strt - 1, &parsed->entry);
	if (parsed->entry != NULL)
	{
		entry_error(parsed->entry, parsed, minish);
		expand(&(parsed->entry), minish);
	}
	return (end);
}

void	alloc_or_free(int on_sign, char *line, t_parsed *parsed,
					t_minish *minish)
{
	if (parsed->exit != NULL && parsed->exit[0] != '\0')
	{
		exit_error(parsed->exit, parsed, minish);
		if (on_sign - 1 >= 0 && line[on_sign - 1] == '<')
			(free(parsed->exit), parsed->exit = NULL);
		else
			expand(&(parsed->exit), minish);
	}
}

int	ext(char *line, int strt, t_parsed *parsed, t_minish *minish)
{
	int	end;
	int	on_sign;

	on_sign = strt - 1;
	parsed->ex_append = 0;
	if (line[strt] == '>')
	{
		strt++;
		skip_spaces(&strt, line);
		parsed->ex_append = 1;
	}
	skip_spaces(&strt, line);
	end = strt;
	if (parsed->exit != NULL)
		(free(parsed->exit), parsed->exit = NULL);
	while (end_of_word(&end, line) == 1)
		build_substring(line + strt, end - strt - 1, &parsed->exit);
	alloc_or_free(on_sign, line, parsed, minish);
	return (end);
}

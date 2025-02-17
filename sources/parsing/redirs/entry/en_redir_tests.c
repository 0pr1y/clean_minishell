#include "../../../../includes/minishell.h"

int	not_readable(char **exp, t_parsed *parsed)
{
	if (access(*exp, F_OK) == 0)
	{
		if (access(*exp, R_OK) == -1)
		{
			parsed->err_msg = ft_strjoin(*exp,
					": Permission denied");
			failed_malloc(parsed->err_msg);
			free(*exp);
			parsed->err_code = 1;
			free_redir(parsed);
			return (1);
		}
	}
	return (0);
}

int	a_file(int end, char *exp, t_parsed *parsed, t_check_path *cp)
{
	if (S_ISREG(cp->sb.st_mode))
		if (!last_wrd(cp->first, cp->last)
			|| (last_wrd(cp->first, cp->last) && exp[end] == '/'))
			return (found_error(parsed, exp, cp->dir_or_f,
					": Not a directory"), 1);
	return (0);
}

int	cannot_open(char *exp, t_parsed *parsed, t_check_path *cp)
{
	if (access(exp, F_OK) == 0)
		return (found_error(parsed, exp, cp->dir_or_f,
				": Permission denied"), 1);
	else
		return (found_error(parsed, exp, cp->dir_or_f,
				": No such file or directory"), 1);
	return (0);
}

int	path_error_en(char *exp, t_parsed *parsed)
{
	t_check_path	cp;
	int				end;

	end = (int)ft_strlen(exp) - 1;
	check_path_init(&end, exp, &cp);
	put_cursors(exp, end, &cp.first, &cp.last);
	while (cp.last < (int)ft_strlen(exp))
	{
		next_dir(exp, &cp.last, end);
		cp.dir_or_f = ft_substr(exp, 0, cp.last);
		failed_malloc(cp.dir_or_f);
		if (access(cp.dir_or_f, R_OK) == 0
			&& stat(cp.dir_or_f, &cp.sb) == 0)
		{
			if (a_file(end, exp, parsed, &cp))
				return (1);
		}
		else if (access(cp.dir_or_f, R_OK) != 0)
		{
			if (cannot_open(exp, parsed, &cp))
				return (1);
		}
		(free(cp.dir_or_f), cp.dir_or_f = NULL);
	}
	return (0);
}

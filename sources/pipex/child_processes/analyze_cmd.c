#include "../../../includes/minishell.h" 

void	cmd_path_error(const char *msg, char *expanded,
				t_parsed *parsed, int code)
{
	parsed->err_msg = ft_strjoin(expanded, msg);
	parsed->err_code = code;
	free_redir(parsed);
	return ;
}

int	couldnt_access(t_check_path *cp, char *expanded, t_parsed *parsed)
{
	if (access(cp->dir_or_f, F_OK) != 0)
		return (cmd_path_error(": No such file or directory",
				expanded, parsed, 127), 1);
	if (access(cp->dir_or_f, F_OK) == 0
		&& (access(cp->dir_or_f, R_OK) != 0
			|| access(cp->dir_or_f, X_OK) != 0))
		return (cmd_path_error(": Permission denied",
				expanded, parsed, 126), 1);
	return (0);
}

int	analyze_cmd(t_check_path *cp, char *expanded, t_parsed *parsed)
{
	if (access(cp->dir_or_f, F_OK) == 0
		&& stat(cp->dir_or_f, &cp->sb) == 0)
	{
		if (S_ISDIR(cp->sb.st_mode))
		{
			if (last_wrd(cp->first, cp->last))
				return (cmd_path_error(": Is a directory",
						expanded, parsed, 126), 1);
		}
		else if (S_ISREG(cp->sb.st_mode))
			if (!last_wrd(cp->first, cp->last)
				|| (last_wrd(cp->first, cp->last)
					&& expanded[cp->last] == '/'))
				return (cmd_path_error(": Not a directory",
						expanded, parsed, 126), 1);
	}
	return (couldnt_access(cp, expanded, parsed));
	return (0);
}

void	cmd_path(char *expanded, t_parsed *parsed)
{
	t_check_path	cp;
	int				ret_value;
	int				end;

	ret_value = 0;
	end = (int)ft_strlen(expanded);
	put_cursors(expanded, end, &cp.first, &cp.last);
	if (count_chars(expanded, '/') > 0)
	{
		while (cp.last <= end && expanded[cp.last]
			&& ret_value == 0)
		{
			next_dir(expanded, &cp.last, end);
			if (cp.last > end)
				cp.last = end;
			if (cp.last <= end)
			{
				cp.dir_or_f = ft_substr(expanded, 0, cp.last);
				failed_malloc(cp.dir_or_f);
				ret_value = analyze_cmd(&cp, expanded, parsed);
				free(cp.dir_or_f);
			}
		}
	}
}

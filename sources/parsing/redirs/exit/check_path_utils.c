#include "../../../../includes/minishell.h"

void	check_path_init(int *end, char *exp, t_check_path *cp)
{
	cp->counter = 0;
	cp->last = 0;
	while ((*end) - 1 >= 0 && exp[(*end) - 1] == '/')
		(*end)--;
	cp->first = (*end);
	at_last_dir(&cp->first, exp);
}

int	wrong_data_type(t_check_path *cp, t_parsed *parsed, char *exp, int end)
{
	if (S_ISDIR(cp->sb.st_mode))
		if (last_wrd(cp->first, cp->last) && exp[end] == '/')
			return (found_error(parsed, exp, cp->dir_or_f,
					": Is a directory"), 1);
	if (S_ISREG(cp->sb.st_mode) && !last_wrd(cp->first, cp->last))
		return (found_error(parsed, exp, cp->dir_or_f,
				": Not a directory"), 1);
	return (0);
}

int	not_writable(t_check_path *cp, t_parsed *parsed, char *exp, int end_of_file)
{
	if (access(cp->dir_or_f, W_OK) != 0
		&& access(cp->dir_or_f, F_OK) == 0)
		return (found_error(parsed, exp, cp->dir_or_f,
				": Permission denied"), 1);
	else if (access(cp->dir_or_f, F_OK) != 0
		&& cp->last <= cp->first)
		return (found_error(parsed, exp, cp->dir_or_f,
				": No such file or directory"), 1);
	if (last_wrd(cp->first, cp->last) && exp[end_of_file] == '/')
		return (found_error(parsed, exp, cp->dir_or_f,
				": Is a directory"), 1);
	return (0);
}

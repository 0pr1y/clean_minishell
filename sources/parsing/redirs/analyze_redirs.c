#include "../../../includes/minishell.h"

void	entry_error(char *entry, t_parsed *parsed, t_minish *minish)
{
	char	*expanded;

	expanded = NULL;
	define_exp(&expanded, entry, minish);
	if (entry[0] == '$'
		&& !ft_strchr(entry, '\'') && !ft_strchr(entry, '"'))
		if (amb_redir(entry, expanded, parsed))
			return ;
	expanded = no_quotes(expanded);
	if (not_readable(&expanded, parsed))
		return ;
	if (count_chars(expanded, '/') > 0)
		if (path_error_en(expanded, parsed))
			return ;
	if (access(expanded, F_OK) == -1)
		return (found_error(parsed, expanded, NULL,
				": No such file or directory"));
	return (free(expanded));
}

void	open_file(char *exp, t_parsed *parsed)
{
	int		fd;

	if (parsed->ex_append == 1)
		fd = open(exp, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(exp, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		(print_err("Open error"), exit(EXIT_FAILURE));
	close(fd);
}

void	exit_error(char *ex, t_parsed *parsed, t_minish *minish)
{
	char		*exp;
	struct stat	sb;

	define_exp(&exp, ex, minish);
	if (ex[0] == '$' && !ft_strchr(ex, '\'') && !ft_strchr(ex, '"'))
		if (amb_redir(ex, exp, parsed))
			return ;
	exp = no_quotes(exp);
	if (!exp || always_a_dir(exp, ft_strlen(exp) - 1, parsed))
		return ;
	if (access(exp, W_OK) == 0 && stat(exp, &sb) == 0)
		if (bad_redir_gd_file(exp, parsed, sb))
			return ;
	if (count_chars(exp, '/') > 0)
		if (path_error_ex((int)ft_strlen(exp) - 1, exp, parsed))
			return ;
	if (access(exp, W_OK) != 0 && access(exp, F_OK) == 0)
		return (found_error(parsed, exp, NULL, ": Permission denied"));
	if (!exp[0])
		return (found_error(parsed, exp, NULL, ": No such file or directory"));
	open_file(exp, parsed);
	return (free(exp));
}

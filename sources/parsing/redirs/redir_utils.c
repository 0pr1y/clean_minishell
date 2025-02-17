#include "../../../includes/minishell.h"

void	free_redir(t_parsed *parsed)
{
	if (parsed->entry != NULL)
		(free(parsed->entry), parsed->entry = NULL);
	if (parsed->exit != NULL)
		(free(parsed->exit), parsed->exit = NULL);
}

void	define_exp(char **dst, char *src, t_minish *minish)
{
	(*dst) = ft_strdup(src);
	failed_malloc(*dst);
	expand(dst, minish);
}

void	found_error(t_parsed *parsed, char *exp,
		char *dir_or_f, const char *msg)
{
	parsed->err_msg = ft_strjoin(exp, msg);
	failed_malloc(parsed->err_msg);
	parsed->err_code = 1;
	free_redir(parsed);
	if (exp != NULL)
		free(exp);
	if (dir_or_f != NULL)
		free(dir_or_f);
}

int	last_wrd(int first, int last)
{
	if (last > first)
		return (1);
	return (0);
}

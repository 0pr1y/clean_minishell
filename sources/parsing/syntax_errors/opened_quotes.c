#include "../../../includes/minishell.h"

void	find_quotes(char *str, char to_find, char *to_free)
{
	char	*found;

	found = ft_strchr(str, to_find);
	if (found == NULL)
		(free(to_free), exit(EXIT_FAILURE));
	opened_quotes(found + 1, 1, to_free);
	return ;
}

void	opened_quotes(char *str, int times, char *to_free)
{
	char	*found;
	char	*d_found;

	found = NULL;
	d_found = NULL;
	if (str == NULL && times == 1)
		(free(to_free), exit(EXIT_FAILURE));
	d_found = ft_strchr(str, '"');
	found = ft_strchr(str, '\'');
	if ((d_found != NULL && found == NULL)
		|| (d_found < found && (d_found && found)))
		(find_quotes(d_found + 1, '"', to_free));
	else if ((d_found == NULL && found != NULL)
		|| (d_found > found && (d_found && found)))
		(find_quotes(found + 1, '\'', to_free));
	return ;
}

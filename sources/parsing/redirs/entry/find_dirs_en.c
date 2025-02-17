#include "../../../../includes/minishell.h"

void	put_cursors(char *exp, int end, int *first, int *last)
{
	*first = end - 1;
	while (*first - 1 >= 0 && exp[*first] != '/')
		(*first)--;
	*last = 0;
}

void	next_dir(char *exp, int *last, int end)
{
	while (exp[*last] == '/')
		(*last)++;
	if (exp[*last])
		(*last)++;
	while (*last <= end && exp[*last] != '/' )
		(*last)++;
}

#include "../../../../includes/minishell.h"

void	at_last_dir(int *first, char *exp)
{
	int	cpy;

	cpy = *first;
	while (((cpy - 1) >= 0 && exp[cpy - 1] == '/'))
		cpy--;
	cpy--;
	while ((cpy - 1) >= 0 && exp[cpy] && exp[cpy] != '/')
		cpy--;
	*first = cpy;
}

void	end_of_dir(char *exp, int *last)
{
	if (*last == (int)ft_strlen(exp))
	{
		(*last)++;
		return ;
	}
	while (exp[(*last) + 1] && exp[*last] == '/')
		(*last)++;
	if (exp[(*last) + 1] && exp[*last])
		(*last)++;
	while (exp[*last] != '/' && exp[*last] != '\0')
		(*last)++;
	if (*last >= (int)ft_strlen(exp))
		*last = (int)ft_strlen(exp);
}

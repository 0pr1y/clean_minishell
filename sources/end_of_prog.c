#include "../includes/minishell.h"

void	failed_malloc(void *str)
{
	if (str == NULL)
	{
		print_err("Failed malloc");
		exit(EXIT_FAILURE);
	}
}

void	words_free(char **list)
{
	int	j;

	j = -1;
	if (list == NULL)
		return ;
	while (list[++j])
		free(list[j]);
	free(list);
}

void	free_all_parsed(t_parsed *all_parsed, int nb_cmds)
{
	int	i;

	i = 0;
	while (i < nb_cmds)
	{
		if (all_parsed[i].lim != NULL)
			words_free(all_parsed[i].lim);
		if (all_parsed[i].cmd != NULL)
			words_free(all_parsed[i].cmd);
		free(all_parsed[i].lim_data);
		free(all_parsed[i].err_msg);
		free(all_parsed[i].entry);
		free(all_parsed[i].exit);
		i++;
	}
	free(all_parsed);
}

#include "../../../includes/minishell.h"

int	pipe_first(char *line, t_parsed *parsed)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	if (line[i] == '|')
	{
		parsed->err_msg = ft_strjoin("",
				"syntax error near unexpected token `|'");
		parsed->err_code = 2;
		return (1);
	}
	return (0);
}

void	opened_pipe(char *str)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	while (str[i] == ' ')
		i--;
	if (str[i] == '|' )
		(free(str), exit(EXIT_FAILURE));
}

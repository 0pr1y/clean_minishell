#include "../../../includes/minishell.h"

void	also_first(char frst, char *msg, t_parsed *parsed)
{
	char	*letters;

	letters = (char *)malloc(sizeof(char) * 3);
	failed_malloc(letters);
	letters[0] = frst;
	letters[1] = '\'';
	letters[2] = '\0';
	parsed->err_msg = ft_strjoin(msg, letters);
	free(letters);
}

void	also_frst_n_scnd(char frst, char scnd, char *msg, t_parsed *parsed)
{
	char	*letters;

	letters = (char *)malloc(sizeof(char) * 4);
	failed_malloc(letters);
	letters[0] = frst;
	letters[1] = scnd;
	letters[2] = '\'';
	letters[3] = '\0';
	parsed->err_msg = ft_strjoin(msg, letters);
	free(letters);
}

char	*put_all_letters(char frst, char scnd, char thrd)
{
	char	*letters;

	letters = (char *)malloc(sizeof(char) * 5);
	failed_malloc(letters);
	letters[0] = frst;
	letters[1] = scnd;
	letters[2] = thrd;
	letters[3] = '\'';
	letters[4] = '\0';
	return (letters);
}

void	syntax_err_msg(t_parsed *parsed, char first, char scnd, char third)
{
	char	*msg;
	char	*letters;

	msg = ft_strdup("syntax error near unexpected token `");
	failed_malloc(msg);
	if (first == '\0')
	{
		parsed->err_msg = ft_strjoin(msg, "newline\'");
		failed_malloc(msg);
	}
	else if (first != '\0' && scnd == '\0')
		also_first(first, msg, parsed);
	else if (first != '\0' && scnd != '\0' && third == '\0')
		also_frst_n_scnd(first, scnd, msg, parsed);
	else if (first != '\0' && scnd != '\0' && third != '\0')
	{
		letters = put_all_letters(first, scnd, third);
		parsed->err_msg = ft_strjoin(msg, letters);
		free(letters);
	}
	free(msg);
	parsed->err_code = 2;
}

#include "../../../includes/minishell.h"

void	before_pipe(t_parsed *parsed, char *line, int i)
{
	char	frst;
	char	scnd;
	char	thrd;

	frst = '\0';
	scnd = '\0';
	thrd = '\0';
	frst = line[i];
	if (line[i + 1] == '&' || line[i + 1] == '|')
		scnd = line[i + 1];
	syntax_err_msg(parsed, frst, scnd, thrd);
}

void	before_entry(t_parsed *parsed, char *line, int i)
{
	char	frst;
	char	scnd;
	char	thrd;

	frst = '\0';
	scnd = '\0';
	thrd = '\0';
	frst = line[i];
	if (line[i + 1] == '&' || line[i + 1] == '>' || line[i + 1] == '<')
		scnd = line[i + 1];
	if (line[i + 1] == '<' && line[i + 2] == '<')
		thrd = line[i + 2];
	syntax_err_msg(parsed, frst, scnd, thrd);
}

void	before_exit(t_parsed *parsed, char *line, int i)
{
	char	frst;
	char	scnd;
	char	thrd;

	frst = '\0';
	scnd = '\0';
	thrd = '\0';
	frst = line[i];
	if (line[i + 1] == '&' || line[i + 1] == '|' || line[i + 1] == '>')
		scnd = line[i + 1];
	syntax_err_msg(parsed, frst, scnd, thrd);
}

void	before_ampersand(t_parsed *parsed, char *line, int i)
{
	char	frst;
	char	scnd;
	char	thrd;

	frst = '\0';
	scnd = '\0';
	thrd = '\0';
	frst = line[i];
	if (line[i + 1] == '&')
		scnd = line[i + 1];
	syntax_err_msg(parsed, frst, scnd, thrd);
}

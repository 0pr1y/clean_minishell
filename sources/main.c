#include "../includes/minishell.h"

int	ft_isempty(char *str)
{
	int	i;
	int	counter;

	i = -1;
	counter = 0;
	if (str == NULL)
		return (1);
	while (str[++i] != '\0')
		if (!(str[i] >= 9 && str[i] <= 13) && str[i] != ' ')
			counter++;
	if (counter == 0)
		return (1);
	return (0);
}

void	prompt(t_minish *minish)
{
	char	*line;

	while (true)
	{
		line = readline("DarkShell ");
		if (line == NULL)
			return ;
		else if (line[0] == '\0' || ft_isempty(line))
		{
			free(line);
			continue ;
		}
		else if (ft_strlen(line) > 0)
		{
			obtain_cmds(line, minish);
			if (minish->all_parsed[0].err_code == 2)
				print_err(minish->all_parsed[0].err_msg);
			(add_history(line), free(line));
			if (0 != request_limiters(minish->all_parsed, minish->nb_cmds))
				continue ;
			lounch_processes(minish, minish->nb_cmds - 1);
			free_all_parsed(minish->all_parsed, minish->nb_cmds);
		}
	}
	rl_clear_history();
}

static char	**duplicate_envp(char **envp)
{
	char	**dup_envp;
	int		count;
	int		i;

	count = 0;
	while (envp[count] != NULL)
		count++;
	dup_envp = (char **)malloc(sizeof(char *) * (count + 1));
	if (dup_envp == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		dup_envp[i] = ft_strdup(envp[i]);
		failed_malloc(dup_envp[i]);
		i++;
	}
	dup_envp[count] = NULL;
	return (dup_envp);
}

void	handle_sigint(int sig)
{
	(void)sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

int	main(int argc, char **argv, char **envp)
{
	t_minish			minish;
	struct sigaction	sa;
	struct sigaction	saq;

	(void)argv;
	if (argc != 1)
		(printf("No arguments needed\n"), exit(EXIT_FAILURE));
	sa.sa_handler = &handle_sigint;
	sa.sa_flags = SA_RESTART;
	(sigemptyset(&sa.sa_mask), sigaddset(&sa.sa_mask, CNTRL_C));
	sigaction(CNTRL_C, &sa, NULL);
	saq.sa_handler = SIG_IGN;
	saq.sa_flags = SA_RESTART;
	(sigemptyset(&saq.sa_mask), sigaddset(&saq.sa_mask, CNTRL_B_SLASH));
	sigaction(CNTRL_B_SLASH, &saq, NULL);
	minish.envp = duplicate_envp(envp);
	if (minish.envp == NULL)
		return (EXIT_FAILURE);
	minish.ex_code = 0;
	prompt(&minish);
	free_split(minish.envp);
	return (EXIT_SUCCESS);
}

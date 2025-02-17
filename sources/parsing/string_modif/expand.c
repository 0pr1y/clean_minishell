#include "../../../includes/minishell.h"

void	expand_nbr(char **line, t_extremes ex, int *limit, t_minish *minish)
{
	char	*var_value;

	var_value = NULL;
	(*ex.j)++;
	var_value = ft_itoa(minish->ex_code);
	key_to_value(var_value, line, *ex.j, *ex.i);
	new_limit((*line), var_value, ex.i, limit);
	free(var_value);
	var_value = NULL;
}

void	expand_word(char **line, t_extremes ex, int *limit, t_minish *minish)
{
	char	*var_name;
	char	*var_value;

	(*ex.j)++;
	while (ft_isalpha((*line)[*ex.j]) || ft_isdigit((*line)[*ex.j])
			|| (*line)[*ex.j] == '_')
		(*ex.j)++;
	var_name = ft_strndup((*line) + *ex.i, *ex.j - *ex.i);
	var_value = ft_strdup(ft_getenv((const char **)minish->envp, var_name));
	free(var_name);
	if (var_value != NULL)
	{
		key_to_value(var_value, line, *ex.j, *ex.i);
		new_limit(*line, var_value, ex.i, limit);
	}
	else if (var_value == NULL)
		erase_var(*line, ex.i, *ex.j, limit);
	free(var_value);
}

void	search_var(char **line, int *limit, int *strt, t_minish *minish)
{
	t_extremes	ex;
	int			zero;

	zero = 0;
	ex.j = &zero;
	ex.i = strt;
	while ((*line)[*ex.i] && *ex.i <= *limit)
	{
		if ((*line)[*ex.i] == '$')
		{
			(*ex.i)++;
			*ex.j = *ex.i;
			if ((*line)[*ex.j] == '?')
				expand_nbr(line, ex, limit, minish);
			else if (ft_isalpha((*line)[*ex.j]) || (*line)[*ex.j] == '_')
				expand_word(line, ex, limit, minish);
		}
		else
			(*ex.i)++;
	}
}

void	expand(char **line, t_minish *minish)
{
	int	i;
	int	limit;

	i = 0;
	limit = 0;
	while ((*line) && i < (int)ft_strlen((*line)))
	{
		if ((*line)[i] && (*line)[i] == '\'')
			quote_to_quote(&i, (*line), '\'');
		else if ((*line)[i] && (*line)[i] != '\'')
		{
			if ((*line)[i] == '"')
			{
				limit = i;
				i++;
				quote_to_quote(&limit, (*line), '"');
			}
			else
				limit = i;
			search_var(&(*line), &limit, &i, minish);
		}
	}
	if ((*line) != NULL && ft_isempty((*line)))
		(free((*line)), (*line) = NULL);
}

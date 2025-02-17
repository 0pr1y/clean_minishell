#include "../../includes/minishell.h" 

char	**find_env_paths(char **envp)
{
	char	**paths;
	int		i;

	i = -1;
	while (envp[++i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
	}
	if (envp[i] == NULL)
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (paths == NULL)
		return (NULL);
	return (paths);
}

char	**matching_path(char **args, char **env_paths)
{
	int		i;
	char	*cmd;
	char	*cpy;

	i = -1;
	cmd = ft_strjoin("/", args[0]);
	failed_malloc(cmd);
	cpy = ft_strdup(args[0]);
	failed_malloc(cpy);
	while (env_paths[++i] != NULL)
	{
		free(args[0]);
		args[0] = ft_strjoin(env_paths[i], cmd);
		failed_malloc(args[0]);
		if (access(args[0], X_OK) == 0)
		{
			(free(cmd), free(cpy), free_split(env_paths));
			return (args);
		}
	}
	if (args[0])
		free(args[0]);
	args[0] = cpy;
	(free_split(env_paths), free(cmd));
	return (args);
}

char	**is_executable(char **args, char **env_paths, char **envp)
{
	if (ft_strchr(args[0], '/') == NULL)
	{
		env_paths = find_env_paths(envp);
		if (env_paths == NULL)
			return (args);
		args = matching_path(args, env_paths);
	}
	return (args);
}

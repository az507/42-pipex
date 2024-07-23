/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:21:26 by achak             #+#    #+#             */
/*   Updated: 2024/07/23 18:41:23 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**free_cmd_paths(char **arr_path, char **cmd_paths)
{
	free_array(arr_path);
	free_array(cmd_paths);
	return (NULL);
}

char	*find_path(char **env, char *path)
{
	int	i;
	int	j;

	i = -1;
	while (env[++i])
	{
		j = -1;
		while (env[i][++j])
		{
			if (env[i][j] != path[j] && path[j])
				break ;
			if (env[i][j] != path[j] && !path[j])
				return (env[i] + j);
		}
	}
	return (NULL);
}

char	*assign_cmd_path(char *cmd, char **arr_path)
{
	char	*cmd_path;
	int		i;

	i = -1;
	while (arr_path[++i])
	{
		cmd_path = ft_strjoin(arr_path[i], cmd);
		if (!access(cmd_path, F_OK | X_OK))
			return (cmd_path);
		free(cmd_path);
	}
	if (!access(cmd, F_OK | X_OK))
		return (cmd_path = ft_strcpy2(cmd));
	ft_dprintf(2, "command not found: %s\n", cmd);
	return (NULL);
}

char	**parse_cmds2(char **arr_path, char **cmd_paths, t_pipex **ptr)
{
	int	j;

	j = -1;
	cmd_paths[2] = NULL;
	while (++j < 2)
	{
		cmd_paths[j] = assign_cmd_path((*ptr)->cmd_args[j][0], arr_path);
		if (!cmd_paths[j])
			return (free_cmd_paths(arr_path, cmd_paths));
	}
	free_array(arr_path);
	return (cmd_paths);
}

char	**ft_parse_cmds(char **env, t_pipex **ptr)
{
	char	**arr_path;
	char	**cmd_paths;
	int		j;

	j = -1;
	arr_path = ft_split2(find_path(env, "PATH="), ':');
	cmd_paths = (char **)malloc(sizeof(char *) * 3);
	if (cmd_paths)
		cmd_paths = parse_cmds2(arr_path, cmd_paths, ptr);
	return (cmd_paths);
}

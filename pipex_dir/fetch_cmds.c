/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:39:00 by achak             #+#    #+#             */
/*   Updated: 2024/02/22 12:48:38 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	***free_cmd_args(char ***cmd_args, int j)
{
	while (j >= 0)
		free_array(cmd_args[j--]);
	free(cmd_args);
	return (NULL);
}

void	exit_cmd_args(t_pipex **ptr)
{
	wrapper(close((*ptr)->infile));
	wrapper(close((*ptr)->outfile));
	free(*ptr);
	print_error("invalid command");
}

char	***ft_parse_args(char **av)
{
	char	***cmd_args;
	int		j;
	int		i;

	j = -1;
	i = 2;
	cmd_args = (char ***)malloc(sizeof(char **) * 3);
	if (cmd_args)
	{
		cmd_args[2] = NULL;
		while (++j < 2)
		{
			cmd_args[j] = ft_split(av[i++], ' ');
			if (!cmd_args[j])
				return (free_cmd_args(cmd_args, --j));
			if (!cmd_args[j][0])
				return (free_cmd_args(cmd_args, j));
		}
	}
	return (cmd_args);
}

void	ft_fetch_cmds(char **av, char **env, t_pipex **ptr)
{
	(*ptr)->cmd_args = ft_parse_args(av);
	if (!(*ptr)->cmd_args)
		exit_cmd_args(ptr);
	(*ptr)->cmd_paths = ft_parse_cmds(env, ptr);
	if (!(*ptr)->cmd_paths)
		exit_cmd_paths(ptr);
}

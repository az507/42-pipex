/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_cmds_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:39:00 by achak             #+#    #+#             */
/*   Updated: 2024/02/22 13:35:03 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	***free_cmd_args(char ***cmd_args, int j)
{
	while (j >= 0)
		free_array(cmd_args[j--]);
	free(cmd_args);
	return (NULL);
}

void	exit_cmd_args(t_pipex **ptr)
{
	if ((*ptr)->here_doc)
		wrapper(unlink("here_doc"));
	wrapper(close((*ptr)->infile));
	wrapper(close((*ptr)->outfile));
	free(*ptr);
	print_error("invalid args");
}

char	***ft_parse_args(char **av, t_pipex **ptr)
{
	char	***cmd_args;
	int		j;
	int		i;

	j = -1;
	if ((*ptr)->here_doc)
		i = 3;
	else
		i = 2;
	cmd_args = (char ***)malloc(sizeof(char **) * ((*ptr)->cmd_count + 1));
	if (cmd_args)
	{
		cmd_args[(*ptr)->cmd_count] = NULL;
		while (++j < (*ptr)->cmd_count)
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

void	ft_fetch_cmds(int ac, char **av, char **env, t_pipex **ptr)
{
	(*ptr)->cmd_args = ft_parse_args(av, ptr);
	if (!(*ptr)->cmd_args)
		exit_cmd_args(ptr);
	(*ptr)->cmd_paths = ft_parse_cmds(ac, av, env, ptr);
	if (!(*ptr)->cmd_paths)
		exit_cmd_paths(ptr);
}

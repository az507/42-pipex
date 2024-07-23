/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:29:54 by achak             #+#    #+#             */
/*   Updated: 2024/02/21 12:44:03 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(const char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

void	free_array(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	exit_cmd_paths(t_pipex **ptr)
{
	int	j;

	j = -1;
	while (++j < 2)
		free_array((*ptr)->cmd_args[j]);
	free((*ptr)->cmd_args);
	wrapper(close((*ptr)->infile));
	wrapper(close((*ptr)->outfile));
	free(*ptr);
	exit(EXIT_FAILURE);
}

void	ft_cleanup(t_pipex **ptr)
{
	int	j;

	j = -1;
	while (++j < 2)
		free_array((*ptr)->cmd_args[j]);
	free((*ptr)->cmd_args);
	free_array((*ptr)->cmd_paths);
	free(*ptr);
}

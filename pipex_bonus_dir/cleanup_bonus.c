/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:29:54 by achak             #+#    #+#             */
/*   Updated: 2024/02/20 19:45:32 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	print_error(const char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

void	close_and_unlink(int fd)
{
	if (fd != -2)
	{
		wrapper(close(fd));
		wrapper(unlink("here_doc"));
	}
	print_error("struct ptr malloc");
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
	while (++j < ((*ptr)->cmd_count))
		free_array((*ptr)->cmd_args[j]);
	free((*ptr)->cmd_args);
	wrapper(close((*ptr)->infile));
	wrapper(close((*ptr)->outfile));
	if ((*ptr)->here_doc)
		wrapper(unlink("here_doc"));
	free(*ptr);
	exit(EXIT_FAILURE);
}

void	ft_cleanup(t_pipex **ptr)
{
	int	j;

	j = -1;
	while (++j < ((*ptr)->cmd_count))
		free_array((*ptr)->cmd_args[j]);
	free((*ptr)->cmd_args);
	free_array((*ptr)->cmd_paths);
	if ((*ptr)->here_doc)
		wrapper(unlink("here_doc"));
	free(*ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:43:44 by achak             #+#    #+#             */
/*   Updated: 2024/02/20 19:09:13 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wrapper(int func_rv)
{
	if (func_rv == -1)
		print_error("error in syscall");
}

void	child_process(t_pipex **ptr, int j, int new_fds[], int (*old_fds)[2])
{
	if (j == 0)
	{
		wrapper(dup2((*ptr)->infile, STDIN_FILENO));
		wrapper(close((*ptr)->infile));
	}
	if (j != 0)
	{
		wrapper(close((*old_fds)[1]));
		wrapper(dup2((*old_fds)[0], STDIN_FILENO));
		wrapper(close((*old_fds)[0]));
	}
	if (j == 1)
	{
		wrapper(dup2((*ptr)->outfile, STDOUT_FILENO));
		wrapper(close((*ptr)->outfile));
	}
	if (j != 1)
	{
		wrapper(close(new_fds[0]));
		wrapper(dup2(new_fds[1], STDOUT_FILENO));
		wrapper(close(new_fds[1]));
	}
	wrapper(execve((*ptr)->cmd_paths[j], (*ptr)->cmd_args[j], NULL));
}

void	parent_process(int j, int new_fds[], int (*old_fds)[2])
{
	if (j != 0)
	{
		wrapper(close((*old_fds)[0]));
		wrapper(close((*old_fds)[1]));
	}
	if (j != 1)
	{
		(*old_fds)[0] = new_fds[0];
		(*old_fds)[1] = new_fds[1];
	}
	wait(NULL);
}

void	ft_exec(t_pipex **ptr)
{
	pid_t	pids;
	int		new_fds[2];
	int		(*old_fds)[2];
	int		j;

	j = -1;
	old_fds = malloc(sizeof(int) * 2);
	if (!old_fds)
		print_error("old_fds malloc");
	(*old_fds)[0] = -1;
	(*old_fds)[1] = -1;
	while (++j < 2)
	{
		if (j < 1)
			wrapper(pipe(new_fds));
		wrapper(pids = fork());
		if (pids == 0)
			child_process(ptr, j, new_fds, old_fds);
		else
			parent_process(j, new_fds, old_fds);
	}
	free(old_fds);
}

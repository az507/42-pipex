/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:25:34 by achak             #+#    #+#             */
/*   Updated: 2024/02/22 14:30:41 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_open(char *filename, int flag)
{
	int	fd;

	if (!*filename || !filename)
		return (-1);
	if (flag == 0)
		fd = open(filename, O_RDONLY);
	else if (flag == 1)
		fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	else
		fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0777);
	return (fd);
}

void	ft_init_pipex(int ac, char **av, int fd, t_pipex **ptr)
{
	*ptr = (t_pipex *)malloc(sizeof(t_pipex));
	if (!(*ptr))
		close_and_unlink(fd);
	(*ptr)->cmd_args = &av;
	(*ptr)->cmd_paths = av;
	if (ft_strcmp("here_doc", av[1]))
	{
		(*ptr)->cmd_count = ac - 4;
		(*ptr)->infile = fd;
		(*ptr)->outfile = ft_open(av[ac - 1], 2);
		(*ptr)->here_doc = 1;
	}
	else
	{
		(*ptr)->cmd_count = ac - 3;
		(*ptr)->infile = ft_open(av[1], 0);
		(*ptr)->outfile = ft_open(av[ac - 1], 1);
		(*ptr)->here_doc = 0;
	}
	if ((*ptr)->infile == -1 || (*ptr)->outfile == -1)
	{
		free(*ptr);
		print_error("open call");
	}
}

void	ft_check_args(int ac, char **av, t_pipex **ptr)
{
	int	fd;

	fd = -2;
	if (ac < 5)
		print_error("Too few args");
	if (ft_strcmp("here_doc", av[1]))
	{
		fd = ft_heredoc(av[2]);
		if (ac < 6)
		{
			wrapper(close(fd));
			wrapper(unlink("here_doc"));
			print_error("Too few args");
		}
	}
	ft_init_pipex(ac, av, fd, ptr);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	*ptr;

	ft_check_args(ac, av, &ptr);
	ft_fetch_cmds(ac, av, env, &ptr);
	ft_exec(&ptr);
	ft_cleanup(&ptr);
}

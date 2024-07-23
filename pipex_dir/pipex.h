/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:58:37 by achak             #+#    #+#             */
/*   Updated: 2024/02/22 12:43:11 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	char	***cmd_args;
	char	**cmd_paths;
}	t_pipex;

void	ft_init_pipex(int ac, char **av, t_pipex **ptr);
char	*ft_strcpy2(char *str);

void	ft_fetch_cmds(char **av, char **env, t_pipex **ptr);
char	***ft_parse_args(char **av);
void	exit_cmd_args(t_pipex **ptr);
char	***free_cmd_args(char ***cmd_args, int j);

char	**ft_parse_cmds(char **env, t_pipex **ptr);
char	**parse_cmds2(char **arr_path, char **cmd_paths, t_pipex **ptr);
char	*assign_cmd_path(char *cmd, char **arr_path);
char	*find_path(char **env, char *path);
char	**free_cmd_paths(char **arr_path, char **cmd_paths);

void	ft_exec(t_pipex **ptr);
void	parent_process(int j, int new_fds[], int (*old_fds)[2]);
void	child_process(t_pipex **ptr, int j, int new_fds[], int (*old_fds)[2]);
void	wrapper(int func_rv);

void	ft_cleanup(t_pipex **ptr);
void	exit_cmd_paths(t_pipex **ptr);
void	free_array(char **arr);
void	print_error(const char *s);

#endif

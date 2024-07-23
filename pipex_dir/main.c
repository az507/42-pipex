/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:32:49 by achak             #+#    #+#             */
/*   Updated: 2024/02/22 13:12:22 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strcpy2(char *str)
{
	char	*buffer;
	int		buf_len;
	int		i;

	i = -1;
	buf_len = ft_strlen(str);
	buffer = (char *)malloc(sizeof(char) * (buf_len + 1));
	if (!buffer)
		return (NULL);
	buffer[buf_len] = '\0';
	while (++i < buf_len)
		buffer[i] = str[i];
	return (buffer);
}

void	ft_init_pipex(int ac, char **av, t_pipex **ptr)
{
	if (ac != 5)
		print_error("Doesnt take 4 args");
	*ptr = malloc(sizeof(t_pipex));
	if (!(*ptr))
		print_error("struct ptr malloc");
	(*ptr)->infile = open(av[1], O_RDONLY);
	(*ptr)->outfile = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if ((*ptr)->infile == -1 || (*ptr)->outfile == -1)
	{
		free(*ptr);
		print_error("open call");
	}
	(*ptr)->cmd_args = &av;
	(*ptr)->cmd_paths = av;
}

int	main(int ac, char **av, char **env)
{
	t_pipex	*ptr;

	ft_init_pipex(ac, av, &ptr);
	ft_fetch_cmds(av, env, &ptr);
	ft_exec(&ptr);
	ft_cleanup(&ptr);
}

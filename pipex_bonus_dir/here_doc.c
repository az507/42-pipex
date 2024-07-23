/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:01:35 by achak             #+#    #+#             */
/*   Updated: 2024/02/22 12:55:54 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

int	ft_strcmp2(char *delimiter, char *str)
{
	int	flag;

	flag = 0;
	while (*str && *delimiter)
	{
		if (*str++ != *delimiter++)
		{
			flag = 1;
			break ;
		}
	}
	if (!flag && *str == '\n')
		return (1);
	return (0);
}

int	ft_heredoc(char *delimiter)
{
	char	*str;
	int		fd1;
	int		fd2;

	fd1 = ft_open("here_doc", 2);
	fd2 = -1;
	str = get_next_line(STDIN_FILENO);
	while (str)
	{
		if (ft_strcmp2(delimiter, str))
		{
			free(str);
			fd2 = ft_open("here_doc", 0);
			close(fd1);
			return (fd2);
		}
		write(fd1, str, ft_strlen(str));
		free(str);
		str = get_next_line(STDIN_FILENO);
	}
	close(fd1);
	return (-1);
}

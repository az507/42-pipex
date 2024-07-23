/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:32:16 by achak             #+#    #+#             */
/*   Updated: 2024/02/16 12:47:05 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *s, char sep)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != sep && (*(s + 1) == sep || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

static int	word_len(char *s, char sep)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == sep)
			break ;
		else if (*s++ == '"')
			continue ;
		count++;
	}
	return (count);
}

static void	free_arr(char **arr, int j)
{
	while (j--)
		free(arr[j]);
	free(arr);
}

static void	split_words(char **arr, char *str, char sep)
{
	int	i;
	int	j;

	j = 0;
	while (*str)
	{
		i = 0;
		if (*str == sep)
			str++;
		else
		{
			arr[j] = malloc(sizeof(char) * (word_len(str, sep) + 2));
			if (arr[j] == NULL)
			{
				free_arr(arr, j);
				return ;
			}
			while (*str != sep && *str)
				arr[j][i++] = *str++;
			arr[j][i++] = '/';
			arr[j++][i] = '\0';
		}
	}
}

char	**ft_split2(char *str, char sep)
{
	char	**arr;
	int		words;

	words = count_words(str, sep);
	arr = malloc(sizeof(char *) * (words + 1));
	if (arr == NULL)
		return (NULL);
	arr[words] = NULL;
	split_words(arr, str, sep);
	return (arr);
}

/*
int	main(void)
{
	char	**arr;
	int		i;
	
	i = 0;
	arr = ft_split("3 486 48 64 8 69 97 886 13 78", ' ');
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
	free_arr(arr, i);
}
*/

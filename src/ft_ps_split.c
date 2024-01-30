/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:15:25 by otodd             #+#    #+#             */
/*   Updated: 2024/01/30 16:30:34 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static size_t	ft_ps_count_words(char *str, char c)
{
	size_t	counter;
	bool	in_word;

	counter = 0;
	while (*str)
	{
		in_word = false;
		while (*str && *str == c)
			str++;
		while (*str && *str != c)
		{
			if (!in_word)
			{
				counter++;
				in_word = true;
			}
			str++;
		}
	}
	return (counter);
}

static char	*ft_ps_next_word(char *str, char c)
{
	static int	pos = 0;
	char		*next;
	size_t		len;
	size_t		index;

	len = 0;
	index = 0;
	while (str[pos] == c)
		pos++;
	while ((str[pos + len] != c) && str[pos + len])
		len++;
	next = malloc((len + 1) * sizeof(char));
	if (!next)
		return (NULL);
	while ((str[pos] != c) && str[pos])
		next[index++] = str[pos++];
	next[index] = '\0';
	return (next);
}

char	**ft_ps_split(char *str, char c)
{
	int		counter;
	char	**res;
	size_t	index;

	index = 0;
	counter = ft_ps_count_words(str, c);
	if (!counter)
		exit(EXIT_FAILURE);
	res = malloc(sizeof(char *) * (counter + 2));
	if (!res)
		return (NULL);
	while (counter-- >= 0)
	{
		if (index == 0)
		{
			res[index] = malloc(sizeof(char));
			if (!res[index])
				return (NULL);
			res[index++][0] = '\0';
			continue ;
		}
		res[index++] = ft_ps_next_word(str, c);
	}
	res[index] = NULL;
	return (res);
}

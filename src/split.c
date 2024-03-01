/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:04:17 by oleg              #+#    #+#             */
/*   Updated: 2024/02/03 11:02:49 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	count_words(char *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == c)
			++s;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				count++;
				inside_word = true;
			}
			s++;
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c)
{
	static int	cursor = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while(s[cursor] == c)
		++cursor;
	while ((s[cursor + len] != c) && s[cursor + len])
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

char	**split(char *s, char c)
{
	int		words_count;
	char 	**result_arr;
	int		i;

	i = 0;
	words_count = count_words(s, c);
	if (!words_count)
		exit (1);
	result_arr = malloc(sizeof(char *) * (size_t)(words_count + 2));
	if (!result_arr)
		return (NULL);
	while (words_count-- >= 0)
	{
		if (i == 0)
		{
			result_arr[i] = malloc(sizeof(char));
			if (!result_arr[i])
				return (NULL);
			result_arr[i++][0] = '\0';
			continue ;
		}
		result_arr[i++] = get_next_word(s, c);
	}
	result_arr[i] = NULL;
	return (result_arr);
}

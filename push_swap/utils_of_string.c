/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_of_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 14:41:33 by yakong            #+#    #+#             */
/*   Updated: 2026/10/27 14:41:34 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char const *s)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == ' ')
			in_word = 0;
		else if (!in_word)
		{
			count++;
			in_word = 1;
		}
		s++;
	}
	return (count);
}

static char	*word_copy(char const **s)
{
	char	*word;
	char	*start;
	int		len;

	while (**s == ' ')
		(*s)++;
	len = 0;
	while ((*s)[len] && (*s)[len] != ' ')
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	start = word;
	while (len--)
		*word++ = *(*s)++;
	*word = '\0';
	return (start);
}

char	**split_arg(char const *s)
{
	char	**result;
	char	**start;
	int		n;

	if (!s)
		return (NULL);
	n = count_words(s);
	result = malloc(sizeof(char *) * (n + 1));
	if (!result)
		return (NULL);
	start = result;
	while (n--)
	{
		*result = word_copy(&s);
		if (!*result)
		{
			while (result > start)
				free(*--result);
			return (free(start), NULL);
		}
		result++;
	}
	*result = NULL;
	return (start);
}

void	free_split(char **split)
{
	char	**start;

	start = split;
	if (!split)
		return ;
	while (*split)
		free(*(split++));
	free(start);
}

int	ps_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

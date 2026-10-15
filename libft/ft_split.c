/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 10:49:07 by yakong            #+#    #+#             */
/*   Updated: 2026/10/12 17:56:17 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	is_delim;
	int	count;

	is_delim = 1;
	count = 0;
	while (*s)
	{
		if (*s == c)
			is_delim = 1;
		else if (is_delim)
		{
			count++;
			is_delim = 0;
		}
		s++;
	}
	return (count);
}

static int	count_wordlen(char const *s, char c)
{
	char const	*start;

	start = s;
	while (*s && *s != c)
		s++;
	return (s - start);
}

static char	*word_copy(char const **s_ptr, char c)
{
	int		len;
	char	*copy;
	char	*start;

	while (**s_ptr && **s_ptr == c)
		(*s_ptr)++;
	len = count_wordlen(*s_ptr, c);
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	start = copy;
	while (len--)
		*copy++ = *(*s_ptr)++;
	*copy = '\0';
	return (start);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	char	**start;
	int		n;

	n = count_words(s, c);
	dst = malloc((sizeof(char *) * (n + 1)));
	if (!dst)
		return (NULL);
	start = dst;
	while (n--)
	{
		*dst = word_copy(&s, c);
		if (!*dst)
		{
			while (dst > start)
				free(*--dst);
			return (free(start), NULL);
		}
		dst++;
	}
	*dst = NULL;
	return (start);
}

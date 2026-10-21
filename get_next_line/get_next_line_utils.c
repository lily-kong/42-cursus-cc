/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 16:23:42 by yakong            #+#    #+#             */
/*   Updated: 2026/10/20 16:16:52 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Calculate the length of the string.
int	ft_strlen(char *s)
{
	char	*start;

	if (!s)
		return (-1);
	start = s;
	while (*s)
		s++;
	return (s - start);
}

// Find the first newline character '\n' in the string.
char	*ft_strchr(char *s, char c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (c == 0)
		return (s);
	return (NULL);
}

// Return an empty string if start is out of range in ft_substr().
static char	*empty_dst(void)
{
	char	*dst;

	dst = malloc(1);
	if (!dst)
		return (NULL);
	*dst = '\0';
	return (dst);
}

// Extract the first line and the remaining stash.
char	*ft_substr(char *s, int start, int len)
{
	int		s_len;
	char	*dst;
	char	*p;

	if (!s || start < 0 || len < 0)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (empty_dst());
	if (len >= s_len - start)
		len = s_len - start;
	dst = malloc(len + 1);
	if (!dst)
		return (NULL);
	p = dst;
	while (len--)
		*p++ = s[start++];
	*p = '\0';
	return (dst);
}

// Concatenate the remaining stash with the newly read buffer.
char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*dst;
	char	*p;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	len = ft_strlen(s1) + ft_strlen(s2);
	dst = malloc(len + 1);
	if (!dst)
		return (NULL);
	p = dst;
	while (*s1)
		*p++ = *s1++;
	while (*s2)
		*p++ = *s2++;
	*p = '\0';
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 12:05:47 by yakong            #+#    #+#             */
/*   Updated: 2026/10/12 17:56:34 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		dlen;
	size_t		slen;

	d = dst;
	s = src;
	while (*d && size > 0)
	{
		d++;
		size--;
	}
	while (*s)
		s++;
	dlen = d - dst;
	slen = s - src;
	while (*src && size > 1)
	{
		*d++ = *src++;
		size--;
	}
	if (size >= 1)
		*d = '\0';
	return (dlen + slen);
}

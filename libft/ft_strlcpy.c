/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 13:23:02 by yakong            #+#    #+#             */
/*   Updated: 2026/10/13 17:34:34 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The strlcpy(3) man page specifies that, unlike memcpy, strlcpy copies a 
null-terminated string and ensures that the destination is null-terminated 
when size > 0. */

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char	*s;

	s = src;
	while (*s && size > 1)
	{
		*dst++ = *s++;
		size--;
	}
	if (size >= 1)
		*dst = '\0';
	while (*s)
		s++;
	return ((size_t)(s - src));
}

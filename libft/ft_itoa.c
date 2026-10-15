/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 17:08:42 by yakong            #+#    #+#             */
/*   Updated: 2026/10/12 17:55:34 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_nbrlen(int n)
{
	long	l;
	int		len;

	l = n;
	len = 0;
	if (l <= 0)
	{
		l = -l;
		len++;
	}
	while (l > 0)
	{
		l /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*dst;
	int		len;
	long	l;

	l = n;
	len = count_nbrlen(n);
	dst = malloc(len + 1);
	if (!dst)
		return (NULL);
	dst[len] = '\0';
	if (l == 0)
		dst[0] = '0';
	if (l < 0)
	{
		l = -l;
		dst[0] = '-';
	}
	while (l > 0)
	{
		dst[--len] = l % 10 + '0';
		l /= 10;
	}
	return (dst);
}

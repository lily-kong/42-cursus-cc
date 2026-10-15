/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 15:34:26 by yakong            #+#    #+#             */
/*   Updated: 2026/10/12 17:56:53 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;

	p = s;
	while (*p)
		p++;
	if ((char)*p == (char)c)
		return ((char *)p);
	while (p > s)
	{
		p--;
		if ((char)*p == (char)c)
			return ((char *)p);
	}
	return (NULL);
}

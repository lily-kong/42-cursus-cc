/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 14:59:43 by yakong            #+#    #+#             */
/*   Updated: 2026/10/12 17:56:50 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*b;
	const char	*l;
	size_t		i;

	if (!*little)
		return ((char *)big);
	while (*big && len > 0)
	{
		b = big;
		l = little;
		i = 0;
		while (i < len && *b && *l && *b == *l)
		{
			b++;
			l++;
			i++;
		}
		if (!*l)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 12:05:39 by yakong            #+#    #+#             */
/*   Updated: 2026/10/13 17:26:38 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Check for size_t multiplication overflow before calculating nmemb * size.
nmemb > (size_t)-1 / size means that the product would exceed the representable
range of size_t. */

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dst;

	if (size && nmemb > (size_t)-1 / size)
		return (NULL);
	dst = malloc(nmemb * size);
	if (dst)
		ft_bzero(dst, nmemb * size);
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_of_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 14:33:52 by yakong            #+#    #+#             */
/*   Updated: 2026/10/27 14:33:53 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	putstr_err(char *s)
{
	while (*s)
		write(2, s++, 1);
}

void	putnbr_err(int n)
{
	long	l;
	char	c;

	l = n;
	if (l < 0)
	{
		write(2, "-", 1);
		l = -l;
	}
	if (l >= 10)
		putnbr_err(l / 10);
	c = l % 10 + '0';
	write(2, &c, 1);
}

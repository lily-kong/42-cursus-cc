/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:44:35 by yakong            #+#    #+#             */
/*   Updated: 2026/10/16 11:55:50 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Handles %c and %% conversions.
int	print_char(char c)
{
	return (write(1, &c, 1));
}

// Handles %s conversions.
int	print_string(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (*s)
	{
		write(1, s++, 1);
		len++;
	}
	return (len);
}

// Handles %d and %i conversions.
int	print_number(int n)
{
	long	ln;
	char	c;
	int		len;

	ln = n;
	len = 0;
	if (ln < 0)
	{
		write(1, "-", 1);
		len++;
		ln = -ln;
	}
	if (ln >= 10)
		len += print_number(ln / 10);
	c = ln % 10 + '0';
	write(1, &c, 1);
	len++;
	return (len);
}

// Handles %u conversions.
int	print_uint_number(unsigned int u)
{
	char	c;
	int		len;

	len = 0;
	if (u >= 10)
		len += print_uint_number(u / 10);
	c = u % 10 + '0';
	write(1, &c, 1);
	len++;
	return (len);
}

// Handles %x conversions.
int	print_hex_number(unsigned int x)
{
	const char	*hex;
	int			len;

	len = 0;
	hex = "0123456789abcdef";
	if (x >= 16)
		len += print_hex_number(x / 16);
	write(1, &hex[x % 16], 1);
	len++;
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_expanded.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 09:53:09 by yakong            #+#    #+#             */
/*   Updated: 2026/10/16 12:04:26 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex_number_pointer(uintptr_t	p)
{
	const char	*hex;
	int			len;

	len = 0;
	hex = "0123456789abcdef";
	if (p >= 16)
		len += print_hex_number_pointer(p / 16);
	write(1, &hex[p % 16], 1);
	len++;
	return (len);
}

// Handles %p conversions.
int	print_pointer(void *p)
{
	int	len;

	if (!p)
		return (print_string("(nil)"));
	len = 2;
	write(1, "0x", 2);
	len += print_hex_number_pointer((uintptr_t)p);
	return (len);
}

// Handles %X conversions.
int	print_hex_number_upper(unsigned int x)
{
	const char	*hex;
	int			len;

	len = 0;
	hex = "0123456789ABCDEF";
	if (x >= 16)
		len += print_hex_number_upper(x / 16);
	write(1, &hex[x % 16], 1);
	len++;
	return (len);
}

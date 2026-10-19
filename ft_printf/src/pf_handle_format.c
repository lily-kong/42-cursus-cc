/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:44:48 by yakong            #+#    #+#             */
/*   Updated: 2026/10/17 12:09:42 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isformat(char c)
{
	const char	*str;

	str = "cspdiuxX%";
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	handle_format(char c, va_list ap)
{
	if (c == 'c')
		return (print_char(va_arg(ap, int)));
	else if (c == 's')
		return (print_string(va_arg(ap, char *)));
	else if (c == 'p')
		return (print_pointer(va_arg(ap, void *)));
	else if (c == 'd' || c == 'i')
		return (print_number(va_arg(ap, int)));
	else if (c == 'u')
		return (print_uint_number(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (print_hex_number(va_arg(ap, unsigned int)));
	else if (c == 'X')
		return (print_hex_number_upper(va_arg(ap, unsigned int)));
	else if (c == '%')
		return (print_char('%'));
	return (0);
}

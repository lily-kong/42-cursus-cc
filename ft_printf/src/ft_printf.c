/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:35:26 by yakong            #+#    #+#             */
/*   Updated: 2026/10/16 15:28:51 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		len;
	char	f_next;
	va_list	ap;

	len = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	while (*format)
	{
		f_next = *(format + 1);
		if (*format == '%' && ft_isformat(f_next))
		{
			len += handle_format(f_next, ap);
			format += 2;
		}
		else
		{
			print_char(*format);
			len++;
			format++;
		}
	}
	va_end(ap);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:35:35 by yakong            #+#    #+#             */
/*   Updated: 2026/10/16 15:06:56 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

// Function prototype
int	ft_printf(const char *format, ...);

// Function to print the formatted output
int	print_char(char c);
int	print_string(char *s);
int	print_pointer(void *p);
int	print_number(int n);
int	print_uint_number(unsigned int u);
int	print_hex_number(unsigned int x);
int	print_hex_number_upper(unsigned int x);

// Function to handle format specifiers
int	ft_isformat(char c);
int	handle_format(char c, va_list ap);

#endif
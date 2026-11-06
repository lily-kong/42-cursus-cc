/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 11:31:48 by yakong            #+#    #+#             */
/*   Updated: 2026/10/27 14:44:01 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_integer(char *s)
{
	if (!s || !*s)
		return (0);
	if (*s == '+' || *s == '-')
		s++;
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

static int	parse_integer(char *s, int *result)
{
	long	ln;
	int		sign;

	if (!s || !result || !is_valid_integer(s))
		return (0);
	sign = 1;
	ln = 0;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -sign;
		s++;
	}
	while (*s)
	{
		ln = ln * 10 + (*s - '0');
		if (sign == 1 && ln > INT_MAX)
			return (0);
		if (sign == -1 && ln > -(long)INT_MIN)
			return (0);
		s++;
	}
	*result = (int)(ln * sign);
	return (1);
}

static int	no_duplicates(t_stack *a, int n)
{
	while (a)
	{
		if (a->value == n)
			return (0);
		a = a->next;
	}
	return (1);
}

static int	process_argument(char *arg, t_stack **a)
{
	char	**split;
	int		i;
	int		n;
	t_stack	*new;

	split = split_arg(arg);
	if (!split)
		return (0);
	i = 0;
	while (split[i])
	{
		if (!parse_integer(split[i], &n) || !no_duplicates(*a, n))
			return (free_split(split), 0);
		new = stack_new(n);
		if (!new)
			return (free_split(split), 0);
		stack_add_back(a, new);
		i++;
	}
	free_split(split);
	return (i > 0);
}

int	check_input(int argc, char **argv, int start, t_stack **a)
{
	int	i;

	i = start;
	while (i < argc)
	{
		if (!process_argument(argv[i], a))
			return (free_stack(a), 0);
		i++;
	}
	return (i > start);
}

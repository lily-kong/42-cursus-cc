/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_strategy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 11:31:54 by yakong            #+#    #+#             */
/*   Updated: 2026/11/01 14:18:06 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_strategy(char *arg, t_config *config)
{
	if (!ps_strcmp(arg, "--simple"))
		config->strategy = SIMPLE;
	else if (!ps_strcmp(arg, "--medium"))
		config->strategy = MEDIUM;
	else if (!ps_strcmp(arg, "--complex"))
		config->strategy = COMPLEX;
	else if (!ps_strcmp(arg, "--adaptive"))
		config->strategy = ADAPTIVE;
	else
		return (0);
	return (1);
}

static int	handle_flag(char *arg, t_config *config, int *b_flag, int *s_flag)
{
	if (!ps_strcmp(arg, "--bench"))
	{
		if (*b_flag)
			return (0);
		*b_flag = 1;
		config->bench = 1;
		return (1);
	}
	if (get_strategy(arg, config))
	{
		if (*s_flag)
			return (0);
		*s_flag = 1;
		return (1);
	}
	return (-1);
}

static t_strategy	adaptive_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	double		disorder;
	t_strategy	strategy;
	size_t		size;

	size = stack_size(*a);
	disorder = compute_disorder(*a);
	if (size <= 10 || disorder < 0.2)
	{
		strategy = SIMPLE;
		simple_sort(a, b, bench);
	}
	else if (disorder < 0.5)
	{
		strategy = MEDIUM;
		medium_sort(a, b, bench);
	}
	else
	{
		strategy = COMPLEX;
		complex_sort(a, b, bench);
	}
	return (strategy);
}

int	parse_strategy(int argc, char **argv, t_config *config, int *start)
{
	int	i;
	int	b_flag;
	int	s_flag;
	int	status;

	i = 1;
	b_flag = 0;
	config->bench = 0;
	s_flag = 0;
	config->strategy = ADAPTIVE;
	while (i < argc)
	{
		status = handle_flag(argv[i], config, &b_flag, &s_flag);
		if (!status)
			return (0);
		if (status == -1)
			break ;
		i++;
	}
	*start = i;
	return (1);
}

void	choose_strategy(t_stack **a, t_stack **b, t_config config)
{
	t_bench	bench;
	t_bench	*ptr;
	int		is_adaptive;

	ptr = NULL;
	is_adaptive = (config.strategy == ADAPTIVE);
	if (config.bench)
	{
		bench = (t_bench){0};
		bench.disorder = compute_disorder(*a);
		ptr = &bench;
	}
	stack_index(*a);
	if (is_adaptive)
		config.strategy = adaptive_sort(a, b, ptr);
	else if (config.strategy == SIMPLE)
		simple_sort(a, b, ptr);
	else if (config.strategy == MEDIUM)
		medium_sort(a, b, ptr);
	else if (config.strategy == COMPLEX)
		complex_sort(a, b, ptr);
	if (ptr)
		bench_print(&bench, config.strategy, is_adaptive);
}

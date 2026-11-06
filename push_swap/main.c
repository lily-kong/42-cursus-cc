/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 12:52:20 by yakong            #+#    #+#             */
/*   Updated: 2026/11/01 13:04:41 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *a, t_config config)
{
	t_bench	bench;

	if (config.bench)
	{
		bench = (t_bench){0};
		bench.disorder = compute_disorder(a);
	}
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	if (config.bench)
		bench_print(&bench, config.strategy,
			config.strategy == ADAPTIVE);
	return (1);
}

int	main(int argc, char **argv)
{
	t_config	config;
	t_stack		*a;
	t_stack		*b;
	int			start;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (!parse_strategy(argc, argv, &config, &start))
		return (putstr_err("Error\n"), -1);
	if (!check_input(argc, argv, start, &a))
		return (putstr_err("Error\n"), -1);
	if (is_sorted(a, config))
		return (free_stack(&a), free_stack(&b), 0);
	choose_strategy(&a, &b, config);
	return (free_stack(&a), free_stack(&b), 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:24:50 by yakong            #+#    #+#             */
/*   Updated: 2026/11/01 13:49:15 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

// Swap the first two elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	do_sa(t_stack **a, t_bench *bench)
{
	if (!a || !*a || !(*a)->next)
		return ;
	do_swap(a);
	write(1, "sa\n", 3);
	bench_count(bench, "sa");
}

// Swap the first two elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	do_sb(t_stack **b, t_bench *bench)
{
	if (!b || !*b || !(*b)->next)
		return ;
	do_swap(b);
	write(1, "sb\n", 3);
	bench_count(bench, "sb");
}

// sa and sb at the same time.
void	do_ss(t_stack **a, t_stack **b, t_bench *bench)
{
	if ((!a || !*a || !(*a)->next) && (!b || !*b || !(*b)->next))
		return ;
	do_swap(a);
	do_swap(b);
	write(1, "ss\n", 3);
	bench_count(bench, "ss");
}

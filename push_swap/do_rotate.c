/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:24:40 by yakong            #+#    #+#             */
/*   Updated: 2026/10/27 09:50:31 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
}

// Shift up all elements of stack a by one.
// The first element becomes the last one.
void	do_ra(t_stack **a, t_bench *bench)
{
	if (!a || !*a || !(*a)->next)
		return ;
	do_rotate(a);
	write(1, "ra\n", 3);
	bench_count(bench, "ra");
}

// Shift up all elements of stack b by one.
// The first element becomes the last one.
void	do_rb(t_stack **b, t_bench *bench)
{
	if (!b || !*b || !(*b)->next)
		return ;
	do_rotate(b);
	write(1, "rb\n", 3);
	bench_count(bench, "rb");
}

// ra and rb at the same time.
void	do_rr(t_stack **a, t_stack **b, t_bench *bench)
{
	if ((!a || !*a || !(*a)->next) && (!b || !*b || !(*b)->next))
		return ;
	do_rotate(a);
	do_rotate(b);
	write(1, "rr\n", 3);
	bench_count(bench, "rr");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:24:45 by yakong            #+#    #+#             */
/*   Updated: 2026/10/27 09:51:15 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rrotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *stack;
	*stack = tmp->next;
	tmp->next = NULL;
}

// Shift down all elements of stack a by one.
// The last element becomes the first one.
void	do_rra(t_stack **a, t_bench *bench)
{
	if (!a || !*a || !(*a)->next)
		return ;
	do_rrotate(a);
	write(1, "rra\n", 4);
	bench_count(bench, "rra");
}

// Shift down all elements of stack b by one.
// The last element becomes the first one.
void	do_rrb(t_stack **b, t_bench *bench)
{
	if (!b || !*b || !(*b)->next)
		return ;
	do_rrotate(b);
	write(1, "rrb\n", 4);
	bench_count(bench, "rrb");
}

// rra and rrb at the same time.
void	do_rrr(t_stack **a, t_stack **b, t_bench *bench)
{
	if ((!a || !*a || !(*a)->next) && (!b || !*b || !(*b)->next))
		return ;
	do_rrotate(a);
	do_rrotate(b);
	write(1, "rrr\n", 4);
	bench_count(bench, "rrr");
}

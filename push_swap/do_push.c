/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:24:25 by yakong            #+#    #+#             */
/*   Updated: 2026/10/27 09:49:30 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_push(t_stack **from, t_stack **to)
{
	t_stack	*tmp;

	if (!from || !to || !*from)
		return ;
	tmp = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = tmp;
}

// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	do_pa(t_stack **a, t_stack **b, t_bench *bench)
{
	if (!a || !b || !*b)
		return ;
	do_push(b, a);
	write(1, "pa\n", 3);
	bench_count(bench, "pa");
}

// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	do_pb(t_stack **a, t_stack **b, t_bench *bench)
{
	if (!a || !b || !*a)
		return ;
	do_push(a, b);
	write(1, "pb\n", 3);
	bench_count(bench, "pb");
}

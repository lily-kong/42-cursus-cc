/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_of_complex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 11:30:09 by yakong            #+#    #+#             */
/*   Updated: 2026/10/31 11:56:45 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	get_max_bits(t_stack *a)
{
	size_t	max_index;
	size_t	bits;

	max_index = 0;
	bits = 0;
	while (a)
	{
		if (a->index > max_index)
			max_index = a->index;
		a = a->next;
	}
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}

static void	sort_bit(t_stack **a, t_stack **b, size_t bit, t_bench *bench)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = stack_size(*a);
	while (i < size)
	{
		if ((((*a)->index >> bit) & 1) == 0)
			do_pb(a, b, bench);
		else
			do_ra(a, bench);
		i++;
	}
	while (*b)
		do_pa(a, b, bench);
}

void	complex_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	size_t	max_bits;
	size_t	bit;

	if (!a || !b || !*a || !(*a)->next)
		return ;
	bit = 0;
	max_bits = get_max_bits(*a);
	while (bit < max_bits)
	{
		sort_bit(a, b, bit, bench);
		bit++;
	}
}

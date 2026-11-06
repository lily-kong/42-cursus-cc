/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_of_medium.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 16:27:55 by yakong            #+#    #+#             */
/*   Updated: 2026/10/27 15:15:22 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	find_max_position(t_stack *b)
{
	t_stack	*current;
	size_t	max_index;
	size_t	pos;
	size_t	max_pos;

	current = b;
	max_index = current->index;
	pos = 0;
	max_pos = 0;
	while (current)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
			max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (max_pos);
}

static void	rotate_max_to_top(t_stack **b, size_t max_pos, t_bench *bench)
{
	size_t	size;
	size_t	i;

	size = stack_size(*b);
	i = 0;
	if (max_pos <= size / 2)
	{
		while (i < max_pos)
		{
			do_rb(b, bench);
			i++;
		}
	}
	else
	{
		while (i < size - max_pos)
		{
			do_rrb(b, bench);
			i++;
		}
	}
}

static void	push_one_chunk(t_stack **a, t_stack **b, t_bench *bench, t_chunk c)
{
	size_t	remain;
	size_t	middle;

	remain = stack_size(*a);
	middle = c.start + (c.end - c.start) / 2;
	while (remain > 0 && *a)
	{
		if ((*a)->index >= c.start && (*a)->index < c.end)
		{
			do_pb(a, b, bench);
			if ((*b)->index < middle)
				do_rb(b, bench);
		}
		else
			do_ra(a, bench);
		remain--;
	}
}

static void	push_chunks(t_stack **a, t_stack **b, t_bench *bench)
{
	size_t	size;
	size_t	chunk_size;
	t_chunk	chunk;

	size = stack_size(*a);
	chunk_size = 1;
	while (chunk_size * chunk_size < size)
		chunk_size++;
	chunk.start = 0;
	while (chunk.start < size)
	{
		chunk.end = chunk.start + chunk_size;
		if (chunk.end > size)
			chunk.end = size;
		push_one_chunk(a, b, bench, chunk);
		chunk.start = chunk.end;
	}
}

void	medium_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	size_t	max_pos;

	if (!a || !b || !*a || !(*a)->next)
		return ;
	push_chunks(a, b, bench);
	while (*b)
	{
		max_pos = find_max_position(*b);
		rotate_max_to_top(b, max_pos, bench);
		do_pa(a, b, bench);
	}
}

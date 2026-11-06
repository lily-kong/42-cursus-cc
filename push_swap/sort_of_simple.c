/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_of_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 17:37:51 by yakong            #+#    #+#             */
/*   Updated: 2026/11/01 13:41:30 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	find_min_position(t_stack *a)
{
	t_stack	*current;
	int		min_value;
	size_t	pos;
	size_t	min_pos;

	current = a;
	min_value = current->value;
	pos = 0;
	min_pos = 0;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

static void	rotate_min_to_top(t_stack **a, size_t min_pos, t_bench *bench)
{
	size_t	size;
	size_t	i;

	size = stack_size(*a);
	i = 0;
	if (min_pos <= size / 2)
	{
		while (i < min_pos)
		{
			do_ra(a, bench);
			i++;
		}
	}
	else
	{
		while (i < size - min_pos)
		{
			do_rra(a, bench);
			i++;
		}
	}
}

static void	sort_three(t_stack **a, t_bench *bench)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		do_sa(a, bench);
	else if (first > second && second > third)
	{
		do_sa(a, bench);
		do_rra(a, bench);
	}
	else if (first > second && second < third && first > third)
		do_ra(a, bench);
	else if (first < second && second > third && first < third)
	{
		do_sa(a, bench);
		do_ra(a, bench);
	}
	else if (first < second && second > third && first > third)
		do_rra(a, bench);
}

void	simple_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	size_t	size;
	size_t	min_pos;

	if (!a || !b || !*a || !(*a)->next)
		return ;
	size = stack_size(*a);
	if (size <= 3)
	{
		if (size == 2 && (*a)->value > (*a)->next->value)
			do_sa(a, bench);
		else if (size == 3)
			sort_three(a, bench);
		return ;
	}
	while (size > 3)
	{
		min_pos = find_min_position(*a);
		rotate_min_to_top(a, min_pos, bench);
		do_pb(a, b, bench);
		size--;
	}
	sort_three(a, bench);
	while (*b)
		do_pa(a, b, bench);
}

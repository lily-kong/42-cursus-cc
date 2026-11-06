/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_disorder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 14:56:44 by yakong            #+#    #+#             */
/*   Updated: 2026/10/27 14:56:45 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_pairs(t_stack *a)
{
	size_t	count;

	if (!a)
		return (0);
	count = stack_size(a);
	return (count * (count - 1) / 2);
}

static size_t	count_mistakes(t_stack *a)
{
	t_stack	*current;
	t_stack	*next;
	size_t	mistakes;

	current = a;
	mistakes = 0;
	while (current)
	{
		next = current->next;
		while (next)
		{
			if (current->value > next->value)
				mistakes++;
			next = next->next;
		}
		current = current->next;
	}
	return (mistakes);
}

double	compute_disorder(t_stack *a)
{
	size_t	total_pairs;
	size_t	mistakes;
	double	disorder;

	total_pairs = count_pairs(a);
	if (!total_pairs)
		return (0.0);
	mistakes = count_mistakes(a);
	disorder = (double)mistakes / total_pairs;
	return (disorder);
}

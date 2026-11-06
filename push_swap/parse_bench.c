/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 16:55:03 by yakong            #+#    #+#             */
/*   Updated: 2026/11/01 14:25:52 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench_count(t_bench *b, char *op)
{
	if (!b)
		return ;
	b->total_ops++;
	if (!ps_strcmp(op, "pa"))
		b->pa++;
	else if (!ps_strcmp(op, "pb"))
		b->pb++;
	else if (!ps_strcmp(op, "sa"))
		b->sa++;
	else if (!ps_strcmp(op, "sb"))
		b->sb++;
	else if (!ps_strcmp(op, "ss"))
		b->ss++;
	else if (!ps_strcmp(op, "ra"))
		b->ra++;
	else if (!ps_strcmp(op, "rb"))
		b->rb++;
	else if (!ps_strcmp(op, "rr"))
		b->rr++;
	else if (!ps_strcmp(op, "rra"))
		b->rra++;
	else if (!ps_strcmp(op, "rrb"))
		b->rrb++;
	else if (!ps_strcmp(op, "rrr"))
		b->rrr++;
}

static void	put_metric(char *operation, int times)
{
	putstr_err(operation);
	putnbr_err(times);
}

static void	put_disorder(double disorder)
{
	int	value;

	value = (int)(disorder * 10000 + 0.5);
	putstr_err("[bench] disorder:   ");
	putnbr_err(value / 100);
	putstr_err(".");
	if (value % 100 < 10)
		putstr_err("0");
	putnbr_err(value % 100);
	putstr_err("%\n");
}

static void	put_strategy(t_bench *bench, t_strategy strat, int is_adaptive)
{
	if (is_adaptive)
		putstr_err("[bench] strat:      Adaptive");
	else if (strat == SIMPLE)
		putstr_err("[bench] strat:      Simple");
	else if (strat == MEDIUM)
		putstr_err("[bench] strat:      Medium");
	else if (strat == COMPLEX)
		putstr_err("[bench] strat:      Complex");
	if (bench->disorder < 0.2)
		putstr_err(" / O(n^2)");
	else if (bench->disorder < 0.5)
		putstr_err(" / O(n√n)");
	else
		putstr_err(" / O(n log n)");
}

void	bench_print(t_bench *bench, t_strategy strat, int is_adaptive)
{
	put_disorder(bench->disorder);
	put_strategy(bench, strat, is_adaptive);
	put_metric("\n[bench] total_ops:  ", bench->total_ops);
	put_metric("\n[bench] sa:  ", bench->sa);
	put_metric(" sb:  ", bench->sb);
	put_metric(" ss:  ", bench->ss);
	put_metric(" pa:  ", bench->pa);
	put_metric(" pb:  ", bench->pb);
	put_metric("\n[bench] ra:  ", bench->ra);
	put_metric(" rb:  ", bench->rb);
	put_metric(" rr:  ", bench->rr);
	put_metric(" rra: ", bench->rra);
	put_metric(" rrb: ", bench->rrb);
	put_metric(" rrr: ", bench->rrr);
	putstr_err("\n");
}

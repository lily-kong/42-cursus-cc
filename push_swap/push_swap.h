/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 10:38:36 by yakong            #+#    #+#             */
/*   Updated: 2026/11/01 15:19:43 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	size_t			index;
	struct s_stack	*next;
}	t_stack;

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef struct s_config
{
	t_strategy	strategy;
	int			bench;
}	t_config;

typedef struct s_bench
{
	double	disorder;
	size_t	total_ops;
	size_t	pa;
	size_t	pb;
	size_t	sa;
	size_t	sb;
	size_t	ss;
	size_t	ra;
	size_t	rb;
	size_t	rr;
	size_t	rra;
	size_t	rrb;
	size_t	rrr;
}	t_bench;

typedef struct s_chunk
{
	size_t	start;
	size_t	end;
}	t_chunk;

void	do_pa(t_stack **a, t_stack **b, t_bench *bench);
void	do_pb(t_stack **a, t_stack **b, t_bench *bench);
void	do_sa(t_stack **a, t_bench *bench);
void	do_sb(t_stack **b, t_bench *bench);
void	do_ss(t_stack **a, t_stack **b, t_bench *bench);
void	do_ra(t_stack **a, t_bench *bench);
void	do_rb(t_stack **b, t_bench *bench);
void	do_rr(t_stack **a, t_stack **b, t_bench *bench);
void	do_rra(t_stack **a, t_bench *bench);
void	do_rrb(t_stack **b, t_bench *bench);
void	do_rrr(t_stack **a, t_stack **b, t_bench *bench);

void	simple_sort(t_stack **a, t_stack **b, t_bench *bench);
void	medium_sort(t_stack **a, t_stack **b, t_bench *bench);
void	complex_sort(t_stack **a, t_stack **b, t_bench *bench);

t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new);
void	free_stack(t_stack **a);
size_t	stack_size(t_stack *stack);
void	stack_index(t_stack *a);
char	**split_arg(char const *s);
void	free_split(char **split);
int		ps_strcmp(char *s1, char *s2);
void	putstr_err(char *s);
void	putnbr_err(int n);

double	compute_disorder(t_stack *a);
int		parse_strategy(int argc, char **argv, t_config *config, int *start);
void	choose_strategy(t_stack **a, t_stack **b, t_config config);
int		check_input(int argc, char **argv, int start, t_stack **a);
void	bench_count(t_bench *b, char *op);
void	bench_print(t_bench *bench, t_strategy strat, int is_adaptive);

#endif

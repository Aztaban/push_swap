/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 23:21:59 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/02 23:42:05 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

typedef struct s_move
{
	int	index;
	int	pos_a;
	int	pos_b;
	int	dir_a;
	int	dir_b;
	int	cost;
	int	count_a;
	int	count_b;
}	t_move;

// swap
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

// push
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

// rotate
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

// reverse rotate
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// parsing
bool	parse_args(int argc, char **argv, t_stack *a);
void	index_compress(t_stack *a);

// stack 
void	init_stacks(t_stack **a, t_stack **b, int argc, char **argv);
void	push_back(t_stack *s, int value);
void	free_stack(t_stack *s);

// Cost helpers:
int		pos_in_stack(const t_stack *s, int index);
int		rot_cost(int len, int pos);
int		rot_dir(int len, int pos);
int		find_insert_pos_b(const t_stack *b, int a_index);
int		find_insert_pos_a(const t_stack *a, int b_index);

// move
t_move	find_best_move(const t_stack *a, const t_stack *b);

// sort
void	finalize_sort(t_stack *a, t_stack *b);
void	align_stack(t_stack *a);
void	seed_b_descending(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
bool	is_sorted(const t_stack *a);
int		get_max_index(const t_stack *s);
int		get_min_index(const t_stack *s);

// execute
void	execute_move(t_stack *a, t_stack *b, t_move move);
void	do_rr_both(t_stack *a, t_stack *b, int times);
void	do_rrr_both(t_stack *a, t_stack *b, int times);
void	do_rot_a(t_stack *a, int dir, int times);
void	do_rot_b(t_stack *b, int dir, int times);

#endif
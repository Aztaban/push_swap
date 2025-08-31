/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 23:21:59 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/01 01:00:36 by mjusta           ###   ########.fr       */
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
	int index;
	int pos_a;
	int pos_b;
	int dir_a;
	int dir_b;
	int cost;
}	t_move;

typedef struct s_alignment
{
	int len_a;
	int pos_a;
	int len_b;
	int pos_b;
}	t_alignment;

typedef struct s_directions
{
	int	dir_a;
	int	dir_b;
}	t_directions;

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

// helpers
t_stack	*create_stack(void);
void	push_front(t_stack *s, int value);
void	push_back(t_stack *s, int value);
void	print_stack(const char *name, t_stack *s);
void	free_stack(t_stack *s);

// Prototypes to add
bool	is_sorted(const t_stack *a);
void	index_compress(t_stack *a);           // assign index to each node (0..n-1)
void	sort_small(t_stack *a, t_stack *b);   // handle n<=5 quickly
void	sort_turk(t_stack *a, t_stack *b);    // main greedy loop

// Cost helpers:
int		pos_in_stack(const t_stack *s, int index); // position (0-based) of node with given index
int		rot_cost(int len, int pos);
int		rot_dir(int len, int pos);
int		find_insert_pos_b(const t_stack *b, int a_index);
void	compute_best_move(const t_stack *a, const t_stack *b, t_move *out);

#endif
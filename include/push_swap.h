/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 23:21:59 by mjusta            #+#    #+#             */
/*   Updated: 2025/08/29 01:43:38 by mjusta           ###   ########.fr       */
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

// Prototypes to add (names as you like):
bool    is_sorted(const t_stack *a);
void    index_compress(t_stack *a);           // assign index to each node (0..n-1)
void    sort_small(t_stack *a, t_stack *b);   // handle n<=5 quickly
void    sort_turk(t_stack *a, t_stack *b);    // main greedy loop

// Cost helpers:
int     size(const t_stack *s);               // or just use s->size
int     pos_of_value(const t_stack *s, int index); // position (0-based) of node with given index
int     rot_cost(int len, int pos);           // min cost to bring pos to top (ra vs rra)
int     find_insert_pos_b(const t_stack *b, int a_index);
void    exec_cheapest_move(t_stack *a, t_stack *b);

#endif
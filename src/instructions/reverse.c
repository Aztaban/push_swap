/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 01:01:01 by mjusta            #+#    #+#             */
/*   Updated: 2025/08/25 14:46:58 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	reverse_rotate(t_stack *s)
{
	t_node	*new_head;
	t_node	*new_tail;

	if (s->size < 2)
		return (false);
	new_head = s->tail;
	new_tail = s->head;
	while (new_tail->next && new_tail->next != s->tail)
		new_tail = new_tail->next;
	new_tail->next = NULL;
	new_head->next = s->head;
	s->head = new_head;
	s->tail = new_tail;
	return (true);
}

void	rra(t_stack *a)
{
	if (reverse_rotate(a))
		ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	if (reverse_rotate(b))
		ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	if (reverse_rotate(a) | reverse_rotate(b))
		ft_printf("rrr\n");
}

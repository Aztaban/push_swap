/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:58:48 by mjusta            #+#    #+#             */
/*   Updated: 2025/08/25 14:46:39 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	push(t_stack *dst, t_stack *src)
{
	t_node	*new_src_head;
	t_node	*new_dst_head;

	if (src->size < 1)
		return (false);
	new_src_head = src->head->next;
	new_dst_head = src->head;
	new_dst_head->next = dst->head;
	dst->head = new_dst_head;
	src->head = new_src_head;
	dst->size++;
	src->size--;
	return (true);
}

void	pa(t_stack *a, t_stack *b)
{
	if (push(a, b))
		ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (push(b, a))
		ft_printf("pa\n");
}

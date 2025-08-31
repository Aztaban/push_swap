/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 00:07:28 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/01 01:30:26 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_min_max_idx(t_stack *s, int *min, int *max)
{
	t_node	*current;

	if (!s || s->size == 0)
	{
		*min = -1;
		*max = -1;
		return ;
	}
	current = s->head;
	*min = current->index;
	*max = current->index;
	while (current)
	{
		if (current->index < min)
			min = current->index;
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
}

static int	find_between_nodes(const t_stack *b, int a_index)
{
	t_node	*current;
	t_node	*next;
	int		i;

	current = b->head;
	i = 0;
	while (current)
	{
		if (current->next)
			next = current->next;
		else
			next = b->head;
		if (current->index > a_index && a_index > next->index)
		{
			if (i + 1 == b->size)
				return (0);
			return (i + 1);
		}
		current = current->next;
		i++;
	}
	return (0);
}

int	find_insert_pos_b(const t_stack *b, int a_index)
{
	int	bmin;
	int	bmax;
	int	pos_max;

	if (!b || b->size == 0)
		return (0);
	get_min_max(b, &bmin, &bmax);
	if (a_index > bmax || a_index < bmin)
	{
		pos_max = pos_of_value(b, bmax);
		if (pos_max < 0 || (pos_max + 1) == b->size)
			return (0);
		return (pos_max + 1);
	}
	return (find_between_nodes(b, a_index));
}

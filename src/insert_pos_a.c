/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_pos_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 21:34:29 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/01 21:50:58 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_between_nodes_a(const t_stack *a, int b_index)
{
	t_node	*current;
	t_node	*next;
	int		i;

	current = a->head;
	i = 0;
	while (current)
	{
		if (current->next)
			next = current->next;
		else
			next = a->head;
		if (current->index < b_index && b_index < next->index)
		{
			if (i + 1 == a->size)
				return (0);
			return (i + 1);
		}
		current = current->next;
		i++;
	}
	return (0);
}

int find_insert_pos_a(const t_stack *a, int b_index)
{
    int amin;
    int amax;
    int pos_min;

    if (!a || a->size == 0)
        return (0);
    amin = get_min_index((t_stack *)a);
    amax = get_max_index((t_stack *)a);
    if (b_index < amin || b_index > amax)
    {
        // place before the current min (i.e., rotate min to top)
        pos_min = pos_in_stack(a, amin);
        return pos_min;
    }
    return find_between_nodes_a(a, b_index);
}
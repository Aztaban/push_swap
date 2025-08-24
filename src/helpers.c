/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 01:07:42 by mjusta            #+#    #+#             */
/*   Updated: 2025/08/24 02:36:39 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(void)
{
	t_stack *s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->head = NULL;
	s->tail = NULL;
	s->size = 0;
	return (s);
}

void	push_front(t_stack *s, int value)
{
	t_node *new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->value = value;
	new->next = s->head;
	s->head = new;
	if (s->size == 0)
		s->tail = new;
	s->size++;
}

void print_stack(const char *name, t_stack *s)
{
	ft_printf("%s: ", name);
	t_node *tmp = s->head;
	while (tmp)
	{
		ft_printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	free_stack(t_stack *s)
{
	t_node	*current;
	t_node	*next;

	current = s->head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(s);
}
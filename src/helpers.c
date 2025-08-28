/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 01:07:42 by mjusta            #+#    #+#             */
/*   Updated: 2025/08/29 01:06:34 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Allocates and initializes a new empty stack.
 */
t_stack	*create_stack(void)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->head = NULL;
	s->tail = NULL;
	s->size = 0;
	return (s);
}

/**
 * @brief Pushes a value to the front (head) of the stack.
 */
void	push_front(t_stack *s, int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->value = value;
	new->next = s->head;
	s->head = new;
	if (s->size == 0)
		s->tail = new;
	s->size++;
}

/**
 * @brief Pushes a value to the back (tail) of the stack.
 */
void	push_back(t_stack *s, int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->value = value;
	new->next = NULL;
	if (s->tail)
		s->tail->next = new;
	else
		s->head = new;
	s->tail = new;
	s->size++;
}

/**
 * @brief Frees all nodes in the stack and the stack struct itself.
 */
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

/**
 * @brief Prints all values in the stack from head to tail.
 */
void	print_stack(const char *name, t_stack *s)
{
	t_node	*tmp;

	ft_printf("%s: ", name);
	tmp = s->head;
	while (tmp)
	{
		ft_printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

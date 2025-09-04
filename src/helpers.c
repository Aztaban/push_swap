/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 01:07:42 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/05 00:24:58 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	new->index = -1;
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
}

void	stack_init(int argc, char **argv, t_stack *a, t_stack *b)
{
	if (argc < 2)
		exit(EXIT_SUCCESS);
	a->size = 0;
	a->head = NULL;
	a->tail = NULL;
	b->size = 0;
	b->head = NULL;
	b->tail = NULL;
	if (!parse_args(argc, argv, a))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		free_stack(a);
		exit(EXIT_FAILURE);
	}
	index_compress(a);
}

/**
 * @brief Prints all values in the stack from head to tail.
 */
/* void	print_stack(const char *name, t_stack *s)
{
	t_node	*tmp;

	ft_printf("%s:\n", name);
	tmp = s->head;
	while (tmp)
	{
		ft_printf("Node[%i]: %d\n", tmp->index, tmp->value);
		tmp = tmp->next;
	}
} */
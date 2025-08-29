/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 02:42:29 by mjusta            #+#    #+#             */
/*   Updated: 2025/08/29 03:17:55 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*to_array(const t_stack *s)
{
	int		*arr;
	t_node	*current;
	int		i;

	arr = (int *)malloc(sizeof(int) * s->size);
	if (!arr)
		return (NULL);
	current = s->head;
	i = 0;
	while (current)
	{
		arr[i] = current->value;
		current = current->next;
		i++;
	}
	return (arr);
}

static void	insert_sort(int *arr, int len)
{
	int	i;
	int	j;
	int	key;

	i = 0;
	while (i < len)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

static int	bsearch_int(const int *arr, int len, int target)
{
	int	low;
	int	high;
	int	mid;

	low = 0;
	high = len - 1;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (arr[mid] == target)
			return (mid);
		if (arr[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (-1);
}

void	index_compress(t_stack *s)
{
	int		*arr;
	t_node	*current;

	if (!s || s->size <= 0)
		return ;
	arr = to_array(s);
	if (!arr)
		return ;
	insert_sort(arr, s->size);
	current = s->head;
	while (current)
	{
		current->index = bsearch_int(arr, s->size, current->value);
		current = current->next;
	}
	free(arr);
}
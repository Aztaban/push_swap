/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 02:42:29 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/03 04:02:09 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Convert stack values to an array.
 * 
 * Used for index compression — this array will be sorted to assign normalized 
 * indices.
 * 
 * @param s The stack to convert.
 * @return int* Pointer to the newly allocated array, or NULL on error.
 */
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

/**
 * @brief Insertion sort for integer array.
 * 
 * Simple sorting algorithm.
 * 
 * @param arr The array to sort.
 * @param len Length of the array.
 */
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

/**
 * @brief Binary search for target value in sorted array.
 * 
 * Returns index position for the target — used to assign normalized index.
 * 
 * @param arr Sorted array.
 * @param len Array length.
 * @param target Value to find.
 * @return int Index in array or -1 if not found (shouldn’t 
 * happen in this usage).
 */
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

/**
 * @brief Compress the stack values into a normalized index range [0, N-1].
 * 
 * This avoids working with raw values and enables more efficient comparisons.
 * It transforms all values into their respective positions in a sorted array.
 * 
 * @param s Stack to normalize.
 */
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

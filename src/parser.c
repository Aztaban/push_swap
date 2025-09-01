/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 02:55:17 by mjusta            #+#    #+#             */
/*   Updated: 2025/09/02 00:40:21 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Check if a string is a valid integer representation.
 *
 * Accepts optional '+' or '-' sign followed by digits.
 *
 * @param s The string to validate.
 * @return true if the string is a valid number, false otherwise.
 */
static bool	is_valid_number(const char *s)
{
	if (!s || !*s)
		return (false);
	if (*s == '-' || *s == '+')
		s++;
	if (!*s)
		return (false);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (false);
		s++;
	}
	return (true);
}

/**
 * @brief Safely convert a string to int with overflow protection.
 *
 * Uses long during conversion and flags error if out of int range.
 *
 * @param str The string to convert.
 * @param err Pointer to a bool to store error flag.
 * @return The converted integer, or 0 if invalid.
 */
static int	ft_atoi_safe(const char *str, bool *err)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	*err = false;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign = -1;
	}
	if (*str == '\0')
		return (*err = true, 0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (*err = true, 0);
		result = result * 10 + (*str - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && (-result) < INT_MIN))
			return (*err = true, 0);
		str++;
	}
	return ((int)(sign * result));
}

/**
 * @brief Check for duplicate values in a stack.
 *
 * Scans all combinations of nodes in the stack.
 *
 * @param s The stack to check.
 * @return true if duplicates are found, false otherwise.
 */
static bool	check_duplicates(t_stack *s)
{
	t_node	*victim;
	t_node	*suspect;

	victim = s->head;
	while (victim)
	{
		suspect = victim->next;
		while (suspect)
		{
			if (victim->value == suspect->value)
				return (true);
			suspect = suspect->next;
		}
		victim = victim->next;
	}
	return (false);
}

/**
 * @brief Convert and validate an array of strings into stack values.
 *
 * Also checks for duplicates after insertion.
 *
 * @param nums Array of strings to convert.
 * @param a Pointer to the stack to populate.
 * @return true if all inputs are valid and unique, false otherwise.
 */
static bool	parse_numbers(char **nums, t_stack *a)
{
	int		i;
	int		parsed;
	int		value;
	bool	err;

	i = 0;
	parsed = 0;
	while (nums[i])
	{
		if (!is_valid_number(nums[i]))
			return (false);
		value = ft_atoi_safe(nums[i], &err);
		if (err)
			return (false);
		push_back(a, value);
		parsed++;
		i++;
	}
	if (parsed == 0)
		return (false);
	return (!check_duplicates(a));
}

/**
 * @brief Parse and validate input arguments for push_swap.
 *
 * Accepts either a single string of space-separated numbers or multiple
 * arguments where each is a valid number.
 *
 * @param argc Argument count.
 * @param argv Argument vector.
 * @param a Stack A to populate.
 * @return true if parsing and validation succeed, false otherwise.
 */
bool	parse_args(int argc, char **argv, t_stack *a)
{
	char	**nums;

	if (argc == 2)
	{
		nums = ft_split(argv[1], ' ');
		if (!nums)
			return (false);
		if (!parse_numbers(nums, a))
			return (free_char_arr(nums), false);
		free_char_arr(nums);
		return (true);
	}
	return (parse_numbers(argv + 1, a));
}

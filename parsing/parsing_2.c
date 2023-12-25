/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 01:51:26 by azainabi          #+#    #+#             */
/*   Updated: 2023/12/25 14:17:13 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	check_dup(t_stack **stack)
{
	t_stack *current;
	t_stack *next_node;

	current = *stack;
	next_node = (*stack) -> next;
	while (current -> next != NULL)
	{
		next_node = current -> next;
		while (next_node != NULL)
		{
			if (next_node -> value == current -> value)
				return (1);
			next_node = next_node -> next;
		}
		current = current -> next;
	}
	return (0);
}

int	is_nsorted(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current != NULL && current -> next != NULL)
	{
		if (current -> value > current -> next -> value)
			return (0);
		current = current -> next;
	}
	return (1);
}

int	get_size(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		i++;
		stack = stack ->next;
	}
	return (i);
}
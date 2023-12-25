/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 02:48:32 by azainabi          #+#    #+#             */
/*   Updated: 2023/12/25 14:00:39 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	index_stack(t_stack **stack, int size)
{
	t_stack	*current;
	t_stack	*next_node;
	int		i;

	if (!stack || (!(*stack)))
		return ;
	current = *stack;
	while (current)
	{
		i = 0;
		next_node = *stack;
		while (next_node)
		{
			if (next_node -> value > current -> value)
				i++;
			next_node = next_node -> next;
		}
		current -> index = size - i - 1;
		current = current -> next;
	}
}

int	get_max(t_stack *stack)
{
	t_stack	*current;
	int		i;

	if (!stack)
		return (0);
	current = stack;
	while (current != NULL && current -> next != NULL)
	{
		if (current -> index > current -> next -> index)
			i = current -> index;
		current = current -> next;
	}
	return (i);
}

int	get_min(t_stack *stack)
{
	t_stack	*current;
	int		i;

	if (!stack)
		return (0);
	current = stack;
	i = current -> index;
	while (current != NULL)
	{
		if (current -> index < i)
			i = current -> index;
		current = current -> next;
	}
	return (i);
}

int	get_bottom(t_stack *stack)
{
	t_stack	*current;
	int		i;

	if (!stack)
		return (0);
	current = stack;
	while (current -> next != NULL)
		current = current -> next;
	i = current -> index;
	return (i);
}
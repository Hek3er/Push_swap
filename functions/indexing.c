/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 02:48:32 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/08 14:43:59 by azainabi         ###   ########.fr       */
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
	int		max;

	if (!stack)
		return (-1);
	current = stack;
	max = current->index;
	while (current != NULL)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	return (max);
}

int	get_min(t_stack *stack)
{
	t_stack	*current;
	int		i;

	i = 0;
	if (!stack)
		return (-1);
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

	i = 0;
	if (!stack)
		return (-1);
	current = stack;
	while (current -> next != NULL)
		current = current -> next;
	i = current -> value;
	return (i);
}

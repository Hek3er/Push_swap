/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:07:40 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/09 15:44:28 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	check_dup(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next_node;

	current = *stack;
	next_node = (*stack)->next;
	while (current->next != NULL)
	{
		next_node = current->next;
		while (next_node != NULL)
		{
			if (next_node->value == current->value)
				return (1);
			next_node = next_node->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_nsorted(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current != NULL && current->next != NULL)
	{
		if (current -> value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	get_size(t_stack *stack)
{
	int	i;

	i = 0;
	if (is_stack_empty(&stack))
		return (0);
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	check_line(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(line, "sa", 2) || !ft_strncmp(line, "sb", 2) ||
		!ft_strncmp(line, "ss", 2))
		check_swap(line, stack_a, stack_b);
	else if (!ft_strncmp(line, "pa", 2) || !ft_strncmp(line, "pb", 2))
		check_push(line, stack_a, stack_b);
	else if (!ft_strncmp(line, "rra", 3) || !ft_strncmp(line, "rrb", 3)
		|| !ft_strncmp(line, "rrr", 3))
		check_rrotate(line, stack_a, stack_b);
	else if (!ft_strncmp(line, "ra", 2) || !ft_strncmp(line, "rb", 2)
		|| !ft_strncmp(line, "rr", 2))
		check_rotate(line, stack_a, stack_b);
	else
		free_exit(line, stack_a, stack_b);
}

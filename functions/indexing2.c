/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:54:09 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/08 14:44:03 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	get_position(t_stack *stack, int ind)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index == ind)
			return (i);
		i++;
		stack = stack->next;
	}
	return (i);
}

void	put_top(t_stack **stack_b)
{
	int	max;
	int	pos;
	int	size;

	while (1 && !is_stack_empty(stack_b))
	{
		size = get_size(*stack_b);
		max = get_max(*stack_b);
		pos = get_position(*stack_b, max);
		if (pos == 0)
			break ;
		else if (pos == 1)
			swap(stack_b, 2);
		else if (pos <= size / 2)
			rotate(stack_b, 2);
		else if (pos > size / 2)
			r_rotate(stack_b, 2);
	}
}

int	get_div(int size)
{
	int	div;

	if (size >= 6 && size <= 35)
		div = 2;
	else if (size <= 100)
		div = 12;
	else if (size <= 500)
		div = 19;
	else
		div = 30;
	return (div);
}

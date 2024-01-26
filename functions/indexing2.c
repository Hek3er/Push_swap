/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:54:09 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/10 01:42:34 by azainabi         ###   ########.fr       */
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
	return (-1);
}

void	put_top_a(t_stack **stack, int top)
{
	int	pos;
	int	mid;
	int	size;

	while (!is_stack_empty(stack) && get_size(*stack) >= 2)
	{
		size = get_size(*stack);
		mid = size / 2;
		pos = get_position(*stack, top - 1);
		if (pos == 0 || pos == -1)
			break ;
		else 
			r_rotate(stack, 1);
	}
}

void	put_top_b(t_stack **stack)
{
	int	top;
	int	mid;
	int	size;
	int	pos;

	while (!is_stack_empty(stack) && get_size(*stack) >= 2)
	{
		size = get_size(*stack);
		mid = size / 2;
		top = get_top(*stack);
		pos = get_position(*stack, top);
		if (pos == 0 || pos == -1)
			break ;
		else if (pos <= mid)
			rotate(stack, 2);
		else
			r_rotate(stack, 2);
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
		div = 17;
	else
		div = 30;
	return (div);
}

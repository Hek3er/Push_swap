/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:54:09 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/04 18:38:09 by azainabi         ###   ########.fr       */
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

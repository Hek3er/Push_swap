/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 03:08:03 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/09 05:13:22 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_stack **stack)
{
	int	top;
	int	bottom;
	int	middle;

	top = (*stack)->data;
	bottom = (*stack)->next->next->data;
	middle = (*stack)->next->data;
	if (top > middle && bottom > middle && bottom > top)
		sa(stack);
	else if (top > middle && middle > bottom)
	{
		sa(stack);
		rra(stack);
	}
	else if (top > middle && bottom > middle && top > bottom)
		ra(stack);
	else if (top < middle && bottom < middle && top < bottom)
	{
		sa(stack);
		ra(stack);
	}
	else if (top < middle && bottom < middle && top > bottom)
		rra(stack);
}

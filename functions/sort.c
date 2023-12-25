/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:02:00 by azainabi          #+#    #+#             */
/*   Updated: 2023/12/25 15:16:31 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	sort_two(t_stack **stack)
{
	int	top;
	int	bottom;

	top = (*stack) -> value;
	bottom = (*stack) -> next -> value;
	if (top > bottom)
		swap(stack, 1);
}

void	sort_three(t_stack **stack)
{
	int	top;
	int	bottom;
	int	middle;

	top = get_top(*stack);
	bottom = get_bottom(*stack);
	middle = (*stack) -> next -> value;
	if (top > middle && bottom > middle && bottom > top)
		swap(stack, 1);
	else if (top > middle && middle > bottom)
	{
		swap(stack, 1);
		r_rotate(stack, 1);
	}
	else if (top > middle && bottom > middle && top > bottom)
		rotate(stack, 1);
	else if (top < middle && bottom < middle && top < bottom)
	{
		swap(stack, 1);
		rotate(stack, 1);
	}
	else if (top < middle && bottom < middle && top > bottom)
		r_rotate(stack , 1);
}
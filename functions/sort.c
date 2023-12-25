/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:02:00 by azainabi          #+#    #+#             */
/*   Updated: 2023/12/25 14:23:44 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	sort_three(t_stack **stack)
{
	int	top;
	int	bottom;
	int	middle;

	top = (*stack) -> value;
	bottom = (*stack) -> next -> next -> value;
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
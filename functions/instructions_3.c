/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 01:08:18 by azainabi          #+#    #+#             */
/*   Updated: 2023/12/24 03:57:17 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a, 1);
	swap(stack_b, 2);
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a, 1);
	rotate(stack_b, 2);
}

void	rrotate_both(t_stack **stack_a, t_stack **stack_b)
{
	r_rotate(stack_a, 1);
	r_rotate(stack_b, 2);
}

int	get_top(t_stack *stack)
{
	if (!stack)
		return (0);
	return (stack -> value);
}
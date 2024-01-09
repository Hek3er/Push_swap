/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 01:08:18 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/09 14:40:09 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a, 3);
	swap(stack_b, 4);
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a, 3);
	rotate(stack_b, 4);
}

void	rrotate_both(t_stack **stack_a, t_stack **stack_b)
{
	r_rotate(stack_a, 3);
	r_rotate(stack_b, 4);
}

int	get_top(t_stack *stack)
{
	if (!stack)
		return (0);
	return (stack -> value);
}

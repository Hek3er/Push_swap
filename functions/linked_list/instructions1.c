/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:59:25 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/09 05:12:05 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_stack **stack_a)
{
	if (get_size(*stack_a) >= 2)
		rotate(stack_a, "ra");
}

void	rb(t_stack **stack_b)
{
	if (get_size(*stack_b) >= 2)
		rotate(stack_b, "rb");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (get_size(*stack_a) >= 2 && get_size(*stack_b) >= 2)
	{
		rotate(stack_a, "rr");
		rotate(stack_b, NULL);
	}
}

void	sa(t_stack **stack_a)
{
	if (get_size(*stack_a) >= 2)
		swap(stack_a, "sa");
}

void	sb(t_stack **stack_b)
{
	if (get_size(*stack_b) >= 2)
		swap(stack_b, "sb");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 00:03:41 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/09 05:14:44 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (get_size(*stack_a) >= 2 && get_size(*stack_b) >= 2)
	{
		swap(stack_a, "ss");
		swap(stack_b, NULL);
	}
}

void	rra(t_stack **stack_a)
{
	if (get_size(*stack_a) >= 2)
		rev_rotate(stack_a, "rra");
}

void	rrb(t_stack **stack_b)
{
	if (get_size(*stack_b) >= 2)
		rev_rotate(stack_b, "rrb");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (get_size(*stack_a) >= 2 && get_size(*stack_b) >= 2)
	{
		rev_rotate(stack_a, "rrr");
		rev_rotate(stack_b, NULL);
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_b || !(*stack_b))
		return ;
	push(stack_a, (*stack_b)->data, (*stack_b)->index, "pa");
	pop(stack_b);
}

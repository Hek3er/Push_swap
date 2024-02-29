/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:51:06 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/09 05:53:30 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push_rotate(t_stack **stack_a, t_stack **stack_b, int *flag)
{
	pa(stack_a, stack_b);
	ra(stack_a);
	*flag = 1;
}

static void	second_half(t_stack **stack_a, t_stack **stack_b, int *flag)
{
	while (((*stack_b)->index != (*stack_a)->index - 1) && get_size(*stack_b))
	{
		if (((*stack_b)->index > (get_last_ind(*stack_a))) || !flag)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
			*flag = 1;
		}
		else
			rrb(stack_b);
	}
	pa(stack_a, stack_b);
}

void	send_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	flag;

	flag = 0;
	while (get_size(*stack_b))
	{
		if (is_found(*stack_b, (*stack_a)->index - 1))
		{
			while (((*stack_b)->index != (*stack_a)->index - 1)
				&& get_size(*stack_b))
			{
				if (((*stack_b)->index > (get_last_ind(*stack_a))) || !flag)
					push_rotate(stack_a, stack_b, &flag);
				else
					rb(stack_b);
			}
			pa(stack_a, stack_b);
		}
		else
			second_half(stack_a, stack_b, &flag);
		while (get_last_ind(*stack_a) == (*stack_a)->index -1)
			rra(stack_a);
		if (get_max(*stack_a) == get_last_ind(*stack_a))
			flag = 0;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:39:21 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/09 06:15:46 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	send_min_to_b(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->index == 0)
		pb(stack_a, stack_b);
	else if ((*stack_a)->next->index == 0)
	{
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if ((*stack_a)->next->next->index == 0)
	{
		ra(stack_a);
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if ((*stack_a)->next->next->next->index == 0)
	{
		rra(stack_a);
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	send_min_to_b(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}

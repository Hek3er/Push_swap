/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 04:54:28 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/09 06:16:22 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = get_min(*stack_a);
	if ((*stack_a)->index == min)
		pb(stack_a, stack_b);
	else if ((*stack_a)->next->index == min)
	{
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if ((*stack_a)->next->next->index == min)
	{
		ra(stack_a);
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

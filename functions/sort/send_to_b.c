/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:02:41 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/09 22:40:57 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	init_piv(int *piv1, int *piv2, int *rem, t_stack *stack_a)
{
	*rem = *piv1;
	*piv2 = (get_size(stack_a) / 6) + (*piv1);
	*piv1 += (get_size(stack_a) / 3);
}

void	send_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	piv1;
	int	piv2;
	int	rem;

	piv2 = (get_size(*stack_a) / 6);
	piv1 = (get_size(*stack_a) / 3);
	rem = -1;
	while (get_size(*stack_a) > 3)
	{
		if (get_size(*stack_b) >= 2 && (*stack_a)->index > piv1
			&& (*stack_b)->index > rem && (*stack_b)->index < piv2)
			rr(stack_a, stack_b);
		else if (get_size(*stack_b) >= 2 && (*stack_b)->index > rem
			&& (*stack_b)->index < piv2)
			rb(stack_b);
		if ((*stack_a)->index < piv1)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		if (!is_in_stack(*stack_a, piv1))
			init_piv(&piv1, &piv2, &rem, *stack_a);
	}
	sort_three(stack_a);
}

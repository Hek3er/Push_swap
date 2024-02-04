/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:02:09 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/04 18:39:38 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static void	push_rotate(t_stack **stack_a, t_stack **stack_b, t_var *var)
{
	push_from_stack_b(stack_a, stack_b);
	rotate(stack_a, 1);
	var->size++;
}

static void	push_add(t_stack **stack_a, t_stack **stack_b, t_var *var)
{
	push_from_stack_b(stack_a, stack_b);
	var->size++;
}

int	put_top_b(t_stack **stack_a, t_stack **stack_b, t_var *var)
{
	var->pos = get_position(*stack_b, ((*stack_a)->index - 1));
	if (var->pos == 0 || var->pos == -1)
		return (0);
	else if (var->pos == 1)
		swap(stack_b, 2);
	else if (var->pos <= (get_size(*stack_b) / 2))
		rotate(stack_b, 2);
	else if (var->pos > (get_size(*stack_b) / 2))
		r_rotate(stack_b, 2);
	return (1);
}

void	fill_a(t_stack **stack_a, t_stack **stack_b, t_var *var)
{
	while (!is_stack_empty(stack_b))
	{
		if ((*stack_b)->index == (*stack_a)->index - 1)
			push_add(stack_a, stack_b, var);
		else if ((*stack_b)->index == (get_bottom(*stack_a) + 1))
			push_rotate(stack_a, stack_b, var);
		else if (get_bottom(*stack_a) == ((*stack_a)->index - 1)
			&& (get_bottom(*stack_b) == ((*stack_a)->index - 2)))
			rrotate_both(stack_a, stack_b);
		else if (get_bottom(*stack_a) == ((*stack_a)->index - 1))
			r_rotate(stack_a, 1);
		else if ((get_bottom(*stack_a) == get_max(*stack_a))
			&& ((*stack_b)->index != ((*stack_a)->index - 1))
			&& ((*stack_b)->index >= ((*stack_a)->index / 2)))
			push_rotate(stack_a, stack_b, var);
		else
		{
			if (put_top_b(stack_a, stack_b, var) == 0)
				continue ;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:25:20 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/04 18:13:02 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	found(t_stack **stack_a, int pivot)
{
	t_stack	*stack;
	int		i;

	i = 0;
	stack = *stack_a;
	while (stack)
	{
		if (stack->index < pivot)
			return (i);
		else
		{
			stack = stack->next;
			i++;
		}
	}
	return (-1);
}

void	init_sort(t_var *var)
{
	var->piv1 = var->size / 4;
	var->rem = -1;
	var->piv2 = var->size / 8;
}

int	is_in_stack(t_stack *stack, int pivot)
{
	while (stack)
	{
		if (stack->index < pivot)
			return (1);
		else
			stack = stack->next;
	}
	return (0);
}

void	fill_stack_b(t_stack **stack_a, t_stack **stack_b, t_var *var)
{
	int		top1;
	int		top2;

	while (is_in_stack(*stack_a, var->piv1))
	{
		top1 = get_top(*stack_a);
		top2 = get_top(*stack_b);
		if (top1 >= var->piv1 && top2 > var->rem && top2 < var->piv2)
			rotate_both(stack_a, stack_b);
		else if ((*stack_a)->index < var->piv1)
		{
			push_from_stack_a(stack_a, stack_b);
			if (get_size(*stack_b) >= 2)
			{
				if ((*stack_b)->index > var->rem
					&& (*stack_b)->index < var->piv2)
					rotate(stack_b, 2);
			}
			var->size--;
		}
		else if (found(stack_a, var->piv1) <= (var->size / 2))
			rotate(stack_a, 1);
		else
			r_rotate(stack_a, 1);
	}
}

void	large_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_var	var;

	var.size = get_size(*stack_a);
	var.i = 0;
	init_sort(&var);
	while (get_size(*stack_a) > 3)
	{
		fill_stack_b(stack_a, stack_b, &var);
		var.rem = var.piv1;
		var.piv1 += var.size / 4;
		var.piv2 = (var.size / 8) + var.rem;
	}
	sort_three(stack_a);
	fill_a(stack_a, stack_b, &var);
	while (!is_nsorted(stack_a))
	{
		if (get_bottom(*stack_a) == ((*stack_a)->index - 1))
			r_rotate(stack_a, 1);
	}
}

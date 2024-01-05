/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:02:00 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/05 20:18:04 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	sort_two(t_stack **stack)
{
	int	top;
	int	bottom;

	top = (*stack) -> value;
	bottom = (*stack) -> next -> value;
	if (top > bottom)
		swap(stack, 1);
}

void	sort_three(t_stack **stack)
{
	int	top;
	int	bottom;
	int	middle;

	top = get_top(*stack);
	bottom = get_bottom(*stack);
	middle = (*stack) -> next -> value;
	if (top > middle && bottom > middle && bottom > top)
		swap(stack, 1);
	else if (top > middle && middle > bottom)
	{
		swap(stack, 1);
		r_rotate(stack, 1);
	}
	else if (top > middle && bottom > middle && top > bottom)
		rotate(stack, 1);
	else if (top < middle && bottom < middle && top < bottom)
	{
		swap(stack, 1);
		rotate(stack, 1);
	}
	else if (top < middle && bottom < middle && top > bottom)
		r_rotate(stack , 1);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = get_min(*stack_a);
	if ((*stack_a)->index == min)
		push_from_stack_a(stack_a, stack_b);
	else if ((*stack_a)->next->index == min)
	{
		swap(stack_a, 1);
		push_from_stack_a(stack_a, stack_b);
	}
	else if ((*stack_a)->next->next->index == min)
	{
		rotate(stack_a, 1);
		rotate(stack_a ,1);
		push_from_stack_a(stack_a, stack_b);
	}
	else 
	{
		r_rotate(stack_a, 1);
		push_from_stack_a(stack_a, stack_b);
	}
	sort_three(stack_a);
	push_from_stack_b(stack_a, stack_b);
}

static void	sort_min(t_stack **stack_a, t_stack **stack_b, int min)
{
	if ((*stack_a)->index == min)
		push_from_stack_a(stack_a, stack_b);
	else if ((*stack_a)->next->index == min)
	{
		swap(stack_a, 1);
		push_from_stack_a(stack_a, stack_b);
	}
	else if ((*stack_a)->next->next->index == min)
	{
		rotate(stack_a, 1);
		rotate(stack_a ,1);
		push_from_stack_a(stack_a, stack_b);
	}
	else if ((*stack_a)->next->next->next->index == min)
	{
		r_rotate(stack_a, 1);
		r_rotate(stack_a, 1);
		push_from_stack_a(stack_a, stack_b);
	}
	else
	{
		r_rotate(stack_a, 1);
		push_from_stack_a(stack_a, stack_b);
	}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	bottom;

	min = get_min(*stack_a);
	sort_min(stack_a, stack_b, min);
	sort_four(stack_a, stack_b);
	push_from_stack_b(stack_a, stack_b);
}

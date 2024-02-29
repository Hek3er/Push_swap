/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exc_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 04:05:50 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/09 05:11:20 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_push(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (!ft_strncmp(line, "pa\n", 3))
	{
		push(stack_a, (*stack_b)->data, (*stack_b)->index, NULL);
		pop(stack_b);
	}
	else if (!ft_strncmp(line, "pb\n", 3))
	{
		push(stack_b, (*stack_a)->data, (*stack_a)->index, NULL);
		pop(stack_a);
	}
}

void	check_swap(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		swap(stack_a, NULL);
	else if (!ft_strncmp(line, "sb\n", 3))
		swap(stack_b, NULL);
	else if (!ft_strncmp(line, "ss\n", 3))
	{
		swap(stack_a, NULL);
		swap(stack_b, NULL);
	}
}

void	check_rotate(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (!ft_strncmp(line, "ra\n", 3))
		rotate(stack_a, NULL);
	else if (!ft_strncmp(line, "rb\n", 3))
		rotate(stack_b, NULL);
	else if (!ft_strncmp(line, "rr\n", 3))
	{
		rotate(stack_a, NULL);
		rotate(stack_b, NULL);
	}
}

void	check_rrotate(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (!ft_strncmp(line, "rra\n", 4))
		rev_rotate(stack_a, NULL);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rev_rotate(stack_b, NULL);
	else if (!ft_strncmp(line, "rrr\n", 4))
	{
		rev_rotate(stack_a, NULL);
		rev_rotate(stack_b, NULL);
	}
}

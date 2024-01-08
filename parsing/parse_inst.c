/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_inst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:07:22 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/08 11:07:26 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	check_swap(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(line, "sa", 2) == 0)
	{
		if (get_size(*stack_a) <= 1)
			free_exit(line, stack_a, stack_b);
		swap(stack_a, 4);
	}
	else if (ft_strncmp(line, "sb", 2) == 0)
	{
		if (get_size(*stack_b) <= 1)
			free_exit(line, stack_a, stack_b);
		swap(stack_b, 4);
	}
}

void	check_push(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(line, "pb", 2) == 0)
	{
		if (is_stack_empty(stack_a))
			free_exit(line, stack_a, stack_b);
		push_from_stack_a(stack_a, stack_b);
	}
	else if (ft_strncmp(line, "pa", 2) == 0)
	{
		if (is_stack_empty(stack_b))
			free_exit(line, stack_a, stack_b);
		push_from_stack_b(stack_a, stack_b);
	}
}

void	check_rotate(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(line, "ra", 2) == 0)
	{
		if (get_size(*stack_a) <= 1)
			free_exit(line, stack_a, stack_b);
		rotate(stack_a, 4);
	}
	else if (ft_strncmp(line, "rb", 2) == 0)
	{
		if (get_size(*stack_b) <= 1)
			free_exit(line, stack_a, stack_b);
		rotate(stack_b, 4);
	}
	else if (ft_strncmp(line, "rr", 2) == 0)
	{
		if (get_size(*stack_b) <= 1 || get_size(*stack_a) <= 1)
			free_exit(line, stack_a, stack_b);
		rotate(stack_b, 4);
		rotate(stack_a, 4);
	}
}

void	check_rrotate(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(line, "rra", 3) == 0)
	{
		if (get_size(*stack_a) <= 1)
			free_exit(line, stack_a, stack_b);
		r_rotate(stack_a, 4);
	}
	else if (ft_strncmp(line, "rrb", 3) == 0)
	{
		if (get_size(*stack_b) <= 1)
			free_exit(line, stack_a, stack_b);
		r_rotate(stack_b, 4);
	}
	else if (ft_strncmp(line, "rrr", 3) == 0)
	{
		if (get_size(*stack_b) <= 1 || get_size(*stack_a) <= 1)
			free_exit(line, stack_a, stack_b);
		r_rotate(stack_b, 4);
		r_rotate(stack_a, 4);
	}
}
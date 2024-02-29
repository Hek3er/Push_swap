/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 01:19:05 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/09 05:15:43 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	fill_stack(t_stack **stack, t_var *var)
{
	while (--var->i >= 0)
	{
		if (ft_atoi(var->arg[var->i]) < -2147483648
			|| ft_atoi(var->arg[var->i]) > 2147483647)
		{
			free_arr(var->arg);
			p_error("Error\n", 2);
		}
		push(stack, ft_atoi(var->arg[var->i]), 0, NULL);
		if (is_stack_empty(stack))
		{
			free_stack(stack);
			p_error("Error\n", 2);
		}
	}
}

t_stack	*create_stack(int i, char **arg)
{
	t_stack	*stack;
	t_var	var;

	stack = NULL;
	var.i = 0;
	var.arg = get_arg(i, arg);
	if (!var.arg)
		p_error("Error\n", 1);
	check_int(var.arg);
	while (var.arg[var.i])
		var.i++;
	var.size = var.i;
	fill_stack(&stack, &var);
	free_arr(var.arg);
	if (check_duplicate(stack))
	{
		free_stack(&stack);
		p_error("Error\n", 1);
	}
	if (var.size == 1 || is_sorted(&stack))
		exit(1);
	return (index_stack(&stack, var.size), stack);
}

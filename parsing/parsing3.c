/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:13:43 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/08 15:02:20 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static void	fill_stack(t_stack **stack, t_var *var)
{
	while (--var->i >= 0)
	{
		if (ft_atoi(var->valid[var->i]) < -2147483648
			|| ft_atoi(var->valid[var->i]) > 2147483647)
		{
			free_arr(var->valid);
			p_error("Error\n", 2);
		}
		push(ft_atoi(var->valid[var->i]), 0, stack, 4);
		if (is_stack_empty(stack))
		{
			free_stack(stack);
			p_error("Error\n", 2);
		}
	}
}

t_stack	*create_stack(int x, char **arg)
{
	t_var	var;
	t_stack	*stack;

	stack = NULL;
	var.i = 0;
	var.valid = get_arg(x, arg);
	if (!var.valid)
		p_error("Error\n", 2);
	check_int(var.valid);
	while (var.valid[var.i])
		var.i++;
	var.size = var.i;
	fill_stack(&stack, &var);
	free_arr(var.valid);
	if (var.size == 1 || is_nsorted(&stack))
		exit(1);
	if (check_dup(&stack))
	{
		free_stack(&stack);
		p_error("Error\n", 2);
	}
	return (index_stack(&stack, var.size), stack);
}

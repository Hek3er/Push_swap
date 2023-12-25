/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:21:34 by azainabi          #+#    #+#             */
/*   Updated: 2023/12/25 14:24:47 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pushswap.h"

t_stack	*create_stack(int x, char **arg)
{
	t_var	var;
	t_stack	*stack = NULL;
	
	var.i = 0;
	var.valid = get_arg(x, arg);
	check_int(var.valid);
	while (var.valid[var.i])
		var.i++;
	var.size = var.i;
	while (--var.i >= 0)
	{
		if (ft_atoi(var.valid[var.i]) < -2147483648 || ft_atoi(var.valid[var.i]) > 2147483647)
		{
			free_arr(var.valid);
			p_error("Error\n", 2);
		}
		push(ft_atoi(var.valid[var.i]), &stack, 4);
	}
	free_arr(var.valid);
	if (check_dup(&stack) || is_nsorted(&stack) || var.size == 1)
	{
		free_stack(&stack);
		p_error("Error\n", 2);
	}
	return (index_stack(&stack, var.size), stack);
}

// void f(void)
// {
// 	system("leaks push_swap");
// }

int main(int ac, char **av)
{
	//atexit(f);
	t_stack *stack_a;
	t_stack *curr = stack_a;
	int		size;

	stack_a = create_stack(ac, av);
	size = get_size(stack_a);
	sort_three(&stack_a);
	free_stack(&stack_a);
}
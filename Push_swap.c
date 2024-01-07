/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:21:34 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/06 23:26:53 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pushswap.h"

void	fill_stack(t_stack **stack, t_var *var)
{
	while (--var->i >= 0)
	{
		if (ft_atoi(var->valid[var->i]) < -2147483648 || ft_atoi(var->valid[var->i]) > 2147483647)
		{
			free_arr(var->valid);
			p_error("Error\n", 2);
		}
		push(ft_atoi(var->valid[var->i]), 0,stack, 4);
		if (is_stack_empty(stack))
		{
			free_stack(stack);
			p_error("Error\n", 2); // exit if stack 5awi
		}
	}
}

t_stack	*create_stack(int x, char **arg)
{
	t_var	var;
	t_stack	*stack = NULL;
	
	var.i = 0;
	var.valid = get_arg(x, arg);
	if (!var.valid)
		p_error("Error\n", 2); // check if null
	check_int(var.valid);
	while (var.valid[var.i])
		var.i++;
	var.size = var.i;
	fill_stack(&stack, &var);
	free_arr(var.valid);
	if (check_dup(&stack) || is_nsorted(&stack) || var.size == 1)
	{
		free_stack(&stack);
		p_error("Error\n", 2);
	}
	return (index_stack(&stack, var.size), stack);
}

void f(void)
{
	system("leaks push_swap");
}

int main(int ac, char **av)
{
	//atexit(f);
	t_stack *stack_a;
	t_stack	*stack_b = NULL;
	int		size;

	stack_a = create_stack(ac, av);
	size = get_size(stack_a);
	//ft_printf("size: %d\n", size);
	if (size ==3)
		sort_three(&stack_a);
	else if (size == 2)
		sort_two(&stack_a);
	else if (size == 4)
		sort_four(&stack_a, &stack_b);
	else if (size == 5)
		sort_five(&stack_a, &stack_b);
	else 
		large_sort(&stack_a, &stack_b, size);
	//ft_printf("\n++++++++++++++++stack_a++++++++++++\n");
	//print_s(&stack_a);
	//ft_printf("++++++++++++++++stack_b++++++++++++\n");
	//print_s(&stack_b);
	//ft_printf("is stack sorted: %d", is_nsorted(&stack_a));
	free_stack(&stack_a);
}

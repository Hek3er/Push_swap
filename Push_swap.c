/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:21:34 by azainabi          #+#    #+#             */
/*   Updated: 2023/12/23 03:03:33 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pushswap.h"

t_stack	*create_stack(int x, char **arg)
{
	int 	i;
	int 	size;
	t_stack	*stack = NULL;
	char	**valid;
	
	i = 0;
	valid = get_arg(x, arg);
	check_int(valid);
	while (valid[i])
		i++;
	size = i;
	while (--i >= 0)
		push(ft_atoi(valid[i]), &stack, 4);
	if (check_dup(&stack))
		p_error("Duplicate", 1);
	if (is_sorted(&stack))
		p_error("Stack is already sorted", 2);
	index_stack(&stack, size);
	return (stack);
}

int main(int ac, char **av)
{
	t_stack *stack_a;

	stack_a = create_stack(ac, av);

	t_stack *curr = stack_a;
	while (curr)
	{
		ft_printf("Value: %d --- Index: %d\n", curr -> value, curr->index);
		curr = curr -> next;	
	}
}

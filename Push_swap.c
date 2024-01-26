/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:08:00 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/11 21:16:22 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pushswap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	stack_b = NULL;
	stack_a = create_stack(ac, av);
	size = get_size(stack_a);
	if (size == 3)
		sort_three(&stack_a);
	else if (size == 2)
		sort_two(&stack_a);
	else if (size == 4)
		sort_four(&stack_a, &stack_b);
	else if (size == 5)
		sort_five(&stack_a, &stack_b);
	else
		large_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
}

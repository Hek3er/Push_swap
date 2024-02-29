/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:16:33 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/09 22:44:54 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	stack_b = NULL;
	stack_a = create_stack(ac, av);
	size = get_size(stack_a);
	if (size == 2)
		sort_two(&stack_a);
	else if (size == 3)
		sort_three(&stack_a);
	else if (size == 4)
		sort_four(&stack_a, &stack_b);
	else if (size == 5)
		sort_five(&stack_a, &stack_b);
	else if (size > 5)
	{
		send_to_b(&stack_a, &stack_b);
		send_to_a(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
}

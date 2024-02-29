/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 03:52:04 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/09 22:48:16 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	stack_b = NULL;
	stack_a = create_stack(ac, av);
	line = get_next_line(0);
	while (line)
	{
		check_line(&stack_a, &stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	if (line)
		free(line);
	if (is_sorted(&stack_a) && !get_size(stack_b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_stack(&stack_a);
	free_stack(&stack_b);
}

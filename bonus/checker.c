/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:15:59 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/08 14:42:54 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

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
		check_line(line, &stack_a, &stack_b);
		free(line);
		line = get_next_line(0);
	}
	if (line)
		free(line);
	if (is_nsorted(&stack_a) && is_stack_empty(&stack_b))
		ft_putstr_fd("OK\n", 2);
	else
		ft_putstr_fd("KO\n", 2);
	free_stack(&stack_a);
	free_stack(&stack_b);
}

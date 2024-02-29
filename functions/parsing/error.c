/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 01:07:58 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/09 05:12:42 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	p_error(char *s, int x)
{
	ft_putstr_fd(s, 2);
	exit(x);
}

void	free_exit(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (line)
		free(line);
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

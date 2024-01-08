/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:07:54 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/08 11:07:56 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	p_error(char *s, int x)
{
	ft_putstr_fd(s, 2);
	exit(x);
}

void	free_exit(char *line, t_stack **stack_a, t_stack **stack_b)
{
	free(line);
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	ft_putstr_fd("KO\n", 2);
	exit(1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 04:01:27 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/09 05:11:01 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_line(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (!ft_strncmp(line, "pa\n", 3) || !ft_strncmp(line, "pb\n", 3))
		check_push(stack_a, stack_b, line);
	else if (!ft_strncmp(line, "sa\n", 3) || !ft_strncmp(line, "sb\n", 3)
		|| !ft_strncmp(line, "ss\n", 3))
		check_swap(stack_a, stack_b, line);
	else if (!ft_strncmp(line, "rra\n", 4) || !ft_strncmp(line, "rrb\n", 4)
		|| !ft_strncmp(line, "rrr\n", 4))
		check_rrotate(stack_a, stack_b, line);
	else if (!ft_strncmp(line, "ra\n", 3) || !ft_strncmp(line, "rb\n", 3)
		|| !ft_strncmp(line, "rr\n", 3))
		check_rotate(stack_a, stack_b, line);
	else
		free_exit(line, stack_a, stack_b);
}

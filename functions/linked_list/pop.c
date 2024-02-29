/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:37:06 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/09 05:12:31 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pop(t_stack **stack)
{
	t_stack	*curr;

	if (!stack || !(*stack))
		return ;
	curr = (*stack)->next;
	free(*stack);
	(*stack) = curr;
}

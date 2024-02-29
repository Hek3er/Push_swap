/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 00:09:40 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/09 05:12:11 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !(*stack_a))
		return ;
	push(stack_b, (*stack_a)->data, (*stack_a)->index, "pb");
	pop(stack_a);
}

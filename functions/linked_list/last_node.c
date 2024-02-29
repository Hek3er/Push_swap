/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:38:49 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/09 05:12:26 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*last_node(t_stack *stack)
{
	t_stack	*last;

	if (!stack)
		return (NULL);
	while (stack)
	{
		last = stack;
		stack = stack->next;
	}
	return (last);
}

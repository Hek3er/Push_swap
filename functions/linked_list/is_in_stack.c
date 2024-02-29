/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:13:45 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/09 05:15:10 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_in_stack(t_stack *stack_a, int piv1)
{
	t_stack	*tmp;

	if (!stack_a)
		return (-1);
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->index < piv1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 04:58:57 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/09 05:11:49 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	index_stack(t_stack **stack, int size)
{
	t_stack	*curr;
	t_stack	*iterator;
	int		i;

	if (!stack || !(*stack))
		return ;
	curr = (*stack);
	while (curr)
	{
		i = 0;
		iterator = (*stack);
		while (iterator)
		{
			if (iterator->data > curr->data)
				i++;
			iterator = iterator->next;
		}
		curr->index = size - i - 1;
		curr = curr->next;
	}
}

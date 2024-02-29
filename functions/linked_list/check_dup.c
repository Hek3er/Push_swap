/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 01:32:07 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/09 05:13:55 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_duplicate(t_stack *stack)
{
	t_stack	*curr;
	t_stack	*iterator;

	curr = stack;
	while (curr)
	{
		iterator = curr->next;
		while (iterator)
		{
			if (curr->data == iterator->data)
				return (1);
			iterator = iterator->next;
		}
		curr = curr->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_ind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:56:49 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/09 05:11:39 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_last_ind(t_stack *stack_a)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp->index);
}

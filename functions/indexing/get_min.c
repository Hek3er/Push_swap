/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:31:19 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/09 05:11:46 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_min(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if (!stack)
		return (-1);
	i = stack->index;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index < i)
			i = tmp->index;
		tmp = tmp->next;
	}
	return (i);
}

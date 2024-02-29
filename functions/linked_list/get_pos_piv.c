/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos_piv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:19:15 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/09 05:11:56 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_pos_piv(t_stack *stack_a, int piv1)
{
	int		i;
	t_stack	*tmp;

	tmp = stack_a;
	i = 0;
	while (tmp)
	{
		if (tmp->index < piv1)
			return (i);
		tmp = tmp->next;
	}
	return (i);
}

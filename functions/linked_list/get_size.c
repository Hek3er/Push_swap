/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:30:11 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/09 05:11:59 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_size(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (i);
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

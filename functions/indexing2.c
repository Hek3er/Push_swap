/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:54:09 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/05 16:12:25 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	get_position(t_stack *stack, int ind)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index == ind)
			return (i);
		i++;
		stack = stack->next;
	}
	return (i);
}
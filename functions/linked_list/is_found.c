/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_found.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 01:16:51 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/09 05:12:14 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_found(t_stack *stack, int x)
{
	t_stack	*tmp;
	int		len;

	len = get_size(stack) / 2;
	tmp = stack;
	while (len)
	{
		if (tmp->index == x)
			return (1);
		len--;
		tmp = tmp->next;
	}
	return (0);
}

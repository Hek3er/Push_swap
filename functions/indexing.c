/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 02:48:32 by azainabi          #+#    #+#             */
/*   Updated: 2023/12/23 02:56:29 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	index_stack(t_stack **stack, int size)
{
	t_stack	*current;
	int		i;

	if (!stack || (!(*stack)))
		return ;
	i = 0;
	current = *stack;
	while (current && i < size)
	{
		current -> index = i;
		i++;
		current = current -> next;
	}
}
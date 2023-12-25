/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 04:11:14 by azainabi          #+#    #+#             */
/*   Updated: 2023/12/25 10:20:32 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*temp;
	
	current = *stack;
	while (current)
	{
		temp = current;	
		current = current -> next;
		free(temp);
	}
}

void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		i++;
	while (--i >= 0)
		free(arr[i]);
	free(arr);
}
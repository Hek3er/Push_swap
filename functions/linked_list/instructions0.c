/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:50:24 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/09 05:14:13 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push(t_stack **stack, int value, int index, char *s)
{
	t_stack	*node;

	node = new_node(value);
	if (!node)
		return ;
	node->data = value;
	node->index = index;
	node->next = (*stack);
	(*stack) = node;
	if (!s)
		return ;
	ft_putendl_fd(s, 1);
}

void	swap(t_stack **stack, char *s)
{
	int	value;
	int	tmp_ind;

	if (!stack || get_size(*stack) < 2)
		return ;
	value = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = value;
	tmp_ind = (*stack)->index;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->index = tmp_ind;
	if (!s)
		return ;
	ft_putendl_fd(s, 1);
}

void	rotate(t_stack **stack, char *s)
{
	t_stack	*last;

	if (!stack || get_size(*stack) < 2)
		return ;
	last = last_node(*stack);
	last->next = (*stack);
	(*stack) = (*stack)->next;
	last->next->next = NULL;
	if (!s)
		return ;
	ft_putendl_fd(s, 1);
}

void	rev_rotate(t_stack **stack, char *s)
{
	t_stack	*tmp;
	t_stack	*node;

	node = NULL;
	if (!stack || get_size(*stack) < 2)
		return ;
	tmp = (*stack);
	while (tmp->next != NULL)
	{
		if (tmp->next->next == NULL)
		{
			node = tmp->next;
			tmp->next = NULL;
			break ;
		}
		tmp = tmp->next;
	}
	node->next = (*stack);
	(*stack) = node;
	if (!s)
		return ;
	ft_putendl_fd(s, 1);
}

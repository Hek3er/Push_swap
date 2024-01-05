/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:21:24 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/05 16:34:13 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	push(int data, int index, t_stack **list, int c)
{
	t_stack	*top_s;

	top_s = malloc(sizeof(t_stack));
	if (!top_s)
	{
		free_stack(list);
		return ;
	}
	top_s -> value = data;
	top_s->index = index;
	top_s -> next = *list;
	*list = top_s;
	print_instructions("pa", "pb", "none", c);
}

void	pop(t_stack **list)
{
	t_stack	*current;

	if (!list || !(*list))
		return ;
	current = (*list) -> next;
	free(*list);
	*list = current;
}

void	swap(t_stack **list, int c)
{
	int	temp;
	int	temp_ind;

	if (!list || !(*list) || !(*list) -> next)
		return ;
	temp = (*list) -> value;
	temp_ind = (*list) -> index;
	(*list) -> value = (*list) -> next -> value;
	(*list) -> next -> value = temp;
	(*list) -> index = (*list) -> next -> index;
	(*list) ->next->index = temp_ind;
	print_instructions("sa", "sb", "ss", c);
}

void	print_s(t_stack **list)
{
	t_stack	*current;

	if (!list || !(*list))
		return ;
	current = *list;
	while (current != NULL)
	{
		ft_printf("%d\n", current -> value);
		current = current -> next;
	}
}

void	push_from_stack_a(t_stack **stack_a, t_stack **stack_b)
{
		if (is_stack_empty(stack_a) == 1)
			return ;
		push((*stack_a)->value,(*stack_a)->index ,stack_b,  2);
		pop(stack_a);
}

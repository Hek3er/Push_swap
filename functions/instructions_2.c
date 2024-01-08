/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:26:27 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/08 14:48:42 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*last;

	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		last = lst;
		lst = lst->next;
	}
	return (last);
}

int	is_stack_empty(t_stack **stack)
{
	if (!stack || !(*stack))
		return (1);
	return (0);
}

void	push_from_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	if (is_stack_empty(stack_b) == 1)
		return ;
	push((*stack_b)->value, (*stack_b)->index, stack_a, 1);
	pop(stack_b);
}

void	rotate(t_stack **stack, int c)
{
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
	print_instructions("ra", "rb", "rr", c);
}

void	r_rotate(t_stack **stack, int c)
{
	t_stack	*current;
	t_stack	*node;

	node = NULL;
	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	current = *stack;
	while (current->next != NULL)
	{
		if (current->next-> next == NULL)
		{
			node = current->next;
			current->next = NULL;
			break ;
		}
		current = current->next;
	}
	node -> next = *stack;
	*stack = node;
	print_instructions("rra", "rrb", "rrr", c);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:25:20 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/07 07:09:10 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	is_found(int *arr, int value, int start, int end)
{
	while (start <= end)
	{
		if (arr[start] == value)
			return (1);
		else
			start++;
	}
	return (0);
}

void	init_sort(t_var *var, int size, int *arr)
{
	var->mid = (size / 2) - 1;
	var->offset = size / 8;
	var->start = var->mid - var->offset;
	var->end = var->mid + var->offset;
	var->j = 0;
}

void	pri(int *arr, t_var *var) //delete
{
	for (int i = 0; i < 10; i++)
	{
		if (var->start == i)
			ft_printf("[ %d ]", arr[i]);
		else if (var->end == i)
			ft_printf("[ %d ]", arr[i]);
		else
			ft_printf(" %d ", arr[i]);
	}
	ft_printf("\n");
}

int	is_in_stack(t_stack *stack, int *arr, int min, int max)
{
    while (stack)
    {
        int i = min;
        while (i <= max)
        {
            if (stack->value == arr[i])
                return (1);
            i++;
        }
        stack = stack->next;
    }
    return (0);
}

void	fill_stack_b(t_stack **stack_a, t_stack **stack_b, t_var *var, int *arr)
{
	int	p;
	t_stack	*stack;

	stack = *stack_a;
	while (is_in_stack(*stack_a, arr, var->start, var->end))
	{
		p = var->size / 2;
		//ft_printf("******* Stack -******\n");
		//print_s(&stack);
		//ft_printf("******************** offset: %d, mid: %d, start: %d, end: %d, size : %d arr:", var->offset, var->mid, var->start, var->end, var->size);
		//pri(arr, var);
		if (is_found(arr, stack->value, var->start, var->end))
		{
			push_from_stack_a(stack_a, stack_b);
			if ((get_size(*stack_b) > 1) && stack->value < var->mid)
				rotate(stack_b, 2);
			var->size--;
		}
		else if (get_position(*stack_a, stack->index) < p)
			rotate(stack_a, 1);
		else 
			r_rotate(stack_a, 1);
		stack = *stack_a;
	}
}

void	put_top(t_stack **stack_b)
{
	int	max;
	int	pos;
	int	size;

	while (1 && !is_stack_empty(stack_b))
	{
		size = get_size(*stack_b);
		max = get_max(*stack_b);
		pos = get_position(*stack_b, max);
		if (pos == 0)
			break ;
		else if (pos == 1)
			swap(stack_b, 2);
		else if (pos <= size / 2)
			rotate(stack_b, 2);
		else if (pos > size / 2)
			r_rotate(stack_b, 2);
	}
}

void	large_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		*arr;
	int		i;
	t_var	var;

	var.size = size;
	arr = fill_arr(*stack_a);
	quick_sort(arr, size);
	init_sort(&var, size, arr);
	while (!is_stack_empty(stack_a))
	{
		fill_stack_b(stack_a, stack_b, &var, arr);
		var.start -= var.offset;
		if (var.start < 0)
			var.start = 0;
		var.end += var.offset;
		if (var.end > size)
			var.end = size;
	}
	//ft_printf("++++++++++++++++stack_a++++++++++++\n");
	//print_s(stack_a);
	//ft_printf("++++++++++++++++stack_b++++++++++++\n");
	//print_s(stack_b);
	//ft_printf("\n");
	t_stack	*tmp = *stack_b;
	while (!is_stack_empty(&tmp))
	{
		put_top(stack_b);
		push_from_stack_b(stack_a, stack_b);
		tmp = *stack_b;
	}
}


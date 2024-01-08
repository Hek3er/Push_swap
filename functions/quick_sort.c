/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:32:46 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/08 14:49:29 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	*fill_arr(t_stack *stack)
{
	int		*arr;
	int		size;
	int		i;

	i = 0;
	size = get_size(stack);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	while (stack)
	{
		arr[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (arr);
}

static void	change(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

static int	partition(int *arr, int low, int high)
{
	int	i;
	int	j;
	int	pivot;

	i = low;
	j = low;
	pivot = arr[high];
	while (j < high)
	{
		if (arr[j] <= pivot)
		{
			change(&arr[i], &arr[j]);
			i++;
		}
		j++;
	}
	change(&arr[i], &arr[high]);
	return (i);
}

static void	quick_sort_rec(int *arr, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(arr, low, high);
		quick_sort_rec(arr, low, pivot - 1);
		quick_sort_rec(arr, pivot + 1, high);
	}
}

void	quick_sort(int *arr, int len)
{
	quick_sort_rec(arr, 0, len - 1);
}

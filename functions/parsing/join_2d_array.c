/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_2d_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:36:45 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/09 05:13:05 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	fill_arr1(t_var *var, char **result)
{
	while (result && result[var->i])
	{
		var->arg[var->i] = ft_strdup(result[var->i]);
		if (!var->arg[var->i])
		{
			free_arr(var->arg);
			return ;
		}
		(var->i)++;
	}
}

char	**t_join(char **result, char **tmp, int wc)
{
	t_var	var;

	var.i = 0;
	var.j = 0;
	var.arg = malloc(sizeof(char *) * (wc + 1));
	if (!var.arg)
		return (NULL);
	fill_arr1(&var, result);
	if (!var.arg)
		return (free_arr(var.arg), NULL);
	while (tmp && tmp[var.j])
	{
		var.arg[var.i + var.j] = ft_strdup(tmp[var.j]);
		if (!var.arg[var.i + var.j])
			return (free_arr(var.arg), NULL);
		var.j++;
	}
	if (result)
		free_arr(result);
	if (tmp)
		free_arr(tmp);
	var.arg[var.i + var.j] = NULL;
	return (var.arg);
}

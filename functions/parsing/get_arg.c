/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 00:59:22 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/08 01:55:58 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	**get_arg(int i, char **arg)
{
	t_var	var;

	var.i = 0;
	var.wc = 0;
	var.arg = NULL;
	if (i <= 1)
		exit(1);
	while (var.i < i - 1)
	{
		var.tmp = ft_split(arg[var.i + 1], ' ');
		var.wc += count(arg[var.i + 1], ' ');
		if (!var.wc)
		{
			free_arr(var.tmp);
			p_error("Error\n", 1);
		}
		var.arg = t_join(var.arg, var.tmp, var.wc);
		if (!var.arg)
			return (free_arr(var.arg), NULL);
		var.i++;
	}
	return (var.arg);
}

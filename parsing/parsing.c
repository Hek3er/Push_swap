/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:21:32 by azainabi          #+#    #+#             */
/*   Updated: 2023/12/23 01:50:04 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static void	fill_arr1(t_var *var, char **arr1)
{
	while (arr1 && arr1[var->i])
	{
		var->result[var->i] = ft_strdup(arr1[var->i]);
		if (!var->result[var->i])
		{
			while (var->i > 0)
				free(var->result[--(var->i)]);
			free(var->result);
			return ;
		}
		(var->i)++;
	}
}

static char	**t_join(char **arr1, char **arr2, int wc)
{
	t_var	var;

	var.i = 0;
	var.j = 0;
	var.result = malloc(sizeof(char *) * (wc + 1));
	if (!var.result)
		return (NULL);
	fill_arr1(&var, arr1);
	if (var.i < wc && !var.result)
		return (free(var.result), NULL);
	while (arr2 && arr2[var.j])
	{
		var.result[var.i + var.j] = ft_strdup(arr2[var.j]);
		if (!var.result[var.i + var.j])
		{
			var.k = var.i + var.j;
			while (var.k > 0)
				free(var.result[--(var.k)]);
			return (free(var.result), NULL);
		}
		var.j++;
	}
	var.result[var.i + var.j] = NULL;
	return (var.result);
}

char	**get_arg(int x, char **arg)
{
	t_var	var;

	var.i = 0;
	var.wc = 0;
	var.result = NULL;
	if (x <= 1)
		p_error("Few Arguments", 1);
	while (var.i < x - 1)
	{
		var.j = 0;
		var.temp = ft_split(arg[var.i + 1], ' ');
		var.wc += count(arg[var.i + 1], ' ');
		if (var.wc == 0)
			p_error("Argument is not a number", 2);
		var.result = t_join(var.result, var.temp, var.wc);
		while (var.temp[var.j])
			free(var.temp[var.j++]);
		var.i++;
	}
	return (free(var.temp), var.result);
}

void	check_int(char **result)
{
	int	i;
	int	j;

	i = 0;
	while (result[i])
	{
		j = 0;
		if ((result[i][0] == '+' && ft_isdigit(result[i][1]))
			|| (result[i][0] == '-' && ft_isdigit(result[i][1])))
			j++;
		while (result[i][j])
		{
			if (result[i][j] < '0' || result[i][j] > '9')
				p_error("Argument is not a number", 3);
			j++;
		}
		i++;
	}
}

void	print_instructions(char *str, char *str2, char *str3, int c)
{
	if (c == 1)
		ft_printf("%s\n", str);
	else if (c == 2)
		ft_printf("%s\n", str2);
	else if (c == 4)
		return ;
	else if (c == 3 && ft_strncmp(str3, "none", 4) != 0)
		ft_printf("%s\n", str3);
}

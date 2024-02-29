/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 01:17:25 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/09 05:12:35 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
			if (result[i][j] < '0' || result[i][j] > '9' ||
			ft_strlen(result[i]) > 11)
			{
				free_arr(result);
				p_error("Error\n", 3);
			}
			j++;
		}
		i++;
	}
}

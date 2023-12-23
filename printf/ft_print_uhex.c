/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:34:55 by azainabi          #+#    #+#             */
/*   Updated: 2023/11/17 22:19:35 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	rev_print(char *str)
{
	int		len;
	size_t	i;

	len = 0;
	i = ft_strlen(str);
	while (i > 0)
	{
		i--;
		if (write(1, &str[i], 1) == -1)
			return (-1);
		len++;
	}
	return (len);
}

int	ft_print_uhex(unsigned int nb)
{
	int		i;
	int		j;
	int		len;
	char	*base;
	char	result[9];

	i = 0;
	len = 0;
	base = "0123456789ABCDEF";
	if (nb == 0)
	{
		return (write(1, "0", 1));
	}
	while (nb)
	{
		j = nb % 16;
		result[i] = base[j];
		nb /= 16;
		i++;
	}
	result[i] = '\0';
	len = rev_print(result);
	return (len);
}

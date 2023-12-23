/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:38:25 by azainabi          #+#    #+#             */
/*   Updated: 2023/11/17 22:17:30 by azainabi         ###   ########.fr       */
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

static int	ft_convert_lhex(size_t nb)
{
	int		i;
	int		j;
	char	*base;
	char	result[17];

	i = 0;
	base = "0123456789abcdef";
	if (nb == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		else
			return (1);
	}
	while (nb)
	{
		j = nb % 16;
		result[i] = base[j];
		nb /= 16;
		i++;
	}
	result[i] = '\0';
	return (rev_print(result));
}

int	ft_print_p(void *number)
{
	int		len;
	size_t	nb;

	nb = (size_t)number;
	if (write(1, "0x", 2) == -1)
		return (-1);
	len = ft_convert_lhex(nb);
	if ((void *)nb == NULL)
		return (3);
	return (len + 2);
}

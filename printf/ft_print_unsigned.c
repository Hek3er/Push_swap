/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:23:42 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/08 15:05:06 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	char				nb;
	int					len;

	len = 0;
	if (n <= 9)
	{
		nb = n + 48;
		if (write(1, &nb, 1) == -1)
			return (-1);
		len++;
	}
	else
	{
		len += ft_print_unsigned(n / 10);
		len += ft_print_unsigned(n % 10);
		if (len < 0)
			return (-1);
	}
	return (len);
}

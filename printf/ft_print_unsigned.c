/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:23:42 by azainabi          #+#    #+#             */
/*   Updated: 2023/11/17 22:21:23 by azainabi         ###   ########.fr       */
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

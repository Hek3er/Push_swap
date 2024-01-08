/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:14:19 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/08 15:04:46 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	recur(int *len, long *ln)
{
	if (write(1, "-", 1) == -1)
		return (-1);
	*(len) += 1;
	*(ln) *= -1;
	return (*len);
}

int	ft_putnbr(int n)
{
	char	nb;
	int		len;
	long	ln;

	len = 0;
	ln = n;
	if (ln < 0)
	{
		recur(&len, &ln);
	}
	if (ln <= 9)
	{
		nb = ln + 48;
		if (write(1, &nb, 1) == -1)
			return (-1);
		len++;
	}
	else
	{
		len += ft_putnbr(ln / 10);
		len += ft_putnbr(ln % 10);
		if (len < 0)
			return (-1);
	}
	return (len);
}

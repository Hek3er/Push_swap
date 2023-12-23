/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:27:35 by azainabi          #+#    #+#             */
/*   Updated: 2023/11/19 02:59:40 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format(va_list type, const char *str, int *len, int *i)
{
	if (*(len) < 0)
		return (-1);
	else if (str[*i + 1] == '%')
		*len += ft_putchar('%');
	else if (str[*i + 1] == 'c')
		*(len) += ft_putchar(va_arg(type, int));
	else if (str[*i + 1] == 's')
		*(len) += ft_putstr(va_arg(type, char *));
	else if (str[*i + 1] == 'd')
		*(len) += ft_putnbr(va_arg(type, int));
	else if (str[*i + 1] == 'i')
		*(len) += ft_putnbr(va_arg(type, int));
	else if (str[*i + 1] == 'u')
		*(len) += ft_print_unsigned(va_arg(type, unsigned int));
	else if (str[*i + 1] == 'x')
		*(len) += ft_print_lhex(va_arg(type, unsigned int));
	else if (str[*i + 1] == 'X')
		*(len) += ft_print_uhex(va_arg(type, unsigned int));
	else if (str[*i + 1] == 'p')
		*(len) += ft_print_p(va_arg(type, void *));
	else 
		*(len) += ft_putchar(str[*i + 1]);
	*i += 2;
	return (*len);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	va_list(type);
	va_start(type, str);
	while (str[i])
	{
		while (str[i] && str[i] != '%')
		{
			if (ft_putchar(str[i]) == -1)
				return (-1);
			len++;
			i++;
		}
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				return (0);
			format(type, str, &len, &i);
		}
	}
	va_end(type);
	return (len);
}

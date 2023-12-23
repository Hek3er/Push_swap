/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:17:47 by azainabi          #+#    #+#             */
/*   Updated: 2023/11/06 18:18:30 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dl;
	size_t	j;
	size_t	total;

	if (dstsize == 0)
		return (ft_strlen(src));
	dl = ft_strlen(dst);
	j = 0;
	total = dl + ft_strlen(src);
	if (dstsize < dl)
		total = ft_strlen(src) + dstsize;
	while (src[j] && dl < dstsize - 1)
	{
		dst[dl] = src[j];
		dl++;
		j++;
	}
	dst[dl] = '\0';
	return (total);
}

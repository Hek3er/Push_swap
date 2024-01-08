/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:16:43 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/08 11:16:46 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_len(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

static char	*ft_strdup(char *str)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	len = ft_len(str);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*joined;

	if (!s2)
		return (NULL);
	if (!s1)
	{
		joined = ft_strdup(s2);
		return (joined);
	}
	i = 0;
	j = 0;
	joined = malloc(sizeof(char) * (ft_len(s1) + ft_len(s2) + 1));
	if (!joined)
		return (free(s1), NULL);
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2[j])
		joined[i++] = s2[j++];
	joined[i] = '\0';
	return (joined);
}

int	n_search(char *s)
{
	size_t	i;

	i = 0;
	while (i <= ft_len(s))
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

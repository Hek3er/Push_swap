/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 03:19:01 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/09 04:22:19 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 43
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char		*get_next_line(int fd);
int			get_len(char *str);
char		*ft_join(char *s1, char *s2);
int			n_search(char *s);

#endif
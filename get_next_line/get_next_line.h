/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:16:57 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/08 11:16:59 by azainabi         ###   ########.fr       */
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
size_t		ft_len(char *str);
char		*ft_join(char *s1, char *s2);
int			n_search(char *s);

#endif
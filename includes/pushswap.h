/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:21:29 by azainabi          #+#    #+#             */
/*   Updated: 2023/12/25 14:36:15 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include "../ft_libft/libft.h"
#include "../printf/ft_printf.h"
#include <stdlib.h>

typedef struct stack
{
	int				value;
	int				index;
	struct stack	*next;
}	t_stack;


typedef struct var
{
	int		i;
	int 	j;
	int		k;
	int		wc;
	int		size;
	char	**valid;
	char	**result;
	char	**temp;
}	t_var;

/*
 *	Parsing!
*/

char	**get_arg(int x, char **arg);
void	check_int(char **result);
void	p_error(char *s, int x);
int		check_dup(t_stack **stack);
int		is_nsorted(t_stack **stack);
int		get_size(t_stack *stack);

/*
 *	Instructions!
*/

void	push(int data, t_stack **list, int c);
void	pop(t_stack **list);
void	swap(t_stack **list, int c);
void	print_s(t_stack **list);
void	push_from_stack_a(t_stack **stack_a, t_stack **stack_b);
void	push_from_stack_b(t_stack **stack_a, t_stack **stack_b);
void	print_instructions(char *str, char *str2, char *str3, int c);
void	rotate(t_stack **stack, int c);
void	r_rotate(t_stack **stack, int c);
void	swap_both(t_stack **stack_a, t_stack **stack_b);
void	rotate_both(t_stack **stack_a, t_stack **stack_b);
void	rrotate_both(t_stack **stack_a, t_stack **stack_b);
int		is_stack_empty(t_stack **stack);
void	free_stack(t_stack **stack);
void	free_arr(char **arr);

/*
 *	Indexing!
*/

void	index_stack(t_stack **stack, int size);
int		get_top(t_stack *stack);
int		get_max(t_stack *stack);
int		get_min(t_stack *stack);
int		get_bottom(t_stack *stack);

/*
 *	Sort!
*/

void	sort_two(t_stack **stack);
void	sort_three(t_stack **stack);

#endif
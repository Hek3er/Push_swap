/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:17:10 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/08 14:59:22 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../ft_libft/libft.h"
# include "../printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_var
{
	int		i;
	int		j;
	int		k;
	int		wc;
	int		mid;
	int		offset;
	int		start;
	int		end;
	int		size;
	int		div;
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
t_stack	*create_stack(int x, char **arg);
void	free_exit(char *line, t_stack **stack_a, t_stack **stack_b);
void	check_swap(char *line, t_stack **stack_a, t_stack **stack_b);
void	check_push(char *line, t_stack **stack_a, t_stack **stack_b);
void	check_rotate(char *line, t_stack **stack_a, t_stack **stack_b);
void	check_rrotate(char *line, t_stack **stack_a, t_stack **stack_b);
void	check_line(char *line, t_stack **stack_a, t_stack **stack_b);

/*
 *	Instructions!
*/

void	push(int data, int index, t_stack **list, int c);
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
int		get_position(t_stack *stack, int ind);
void	put_top(t_stack **stack_b);
int		get_div(int size);

/*
 *	Sort!
*/

void	sort_two(t_stack **stack);
void	sort_three(t_stack **stack);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
int		*fill_arr(t_stack *stack);
void	quick_sort(int *arr, int len);
void	large_sort(t_stack **stack_a, t_stack **stack_b, int size);

#endif
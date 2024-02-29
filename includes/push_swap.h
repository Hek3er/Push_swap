/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:21:14 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/09 05:16:37 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../get_next_line/get_next_line.h"

/*
 * Struct of some variables (norminette)
*/

typedef struct s_var
{
	int		i;
	int		j;
	int		size;
	int		wc;
	char	**arg;
	char	**tmp;
}				t_var;

/*
 * Linked List Struct
*/

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}				t_stack;

/*
 * Linked list functions
*/

t_stack	*new_node(int value);
t_stack	*last_node(t_stack *stack);
void	push(t_stack **stack, int value, int index, char *s);
void	swap(t_stack **stack, char *s);
void	rotate(t_stack **stack, char *s);
void	rev_rotate(t_stack **stack, char *s);
void	pop(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
int		get_size(t_stack *stack);
int		is_sorted(t_stack **stack);
int		check_duplicate(t_stack *stack);
int		is_stack_empty(t_stack **stack);
int		is_in_stack(t_stack *stack_a, int piv1);
int		get_pos_piv(t_stack *stack_a, int piv1);
int		is_found(t_stack *stack, int x);

/*
 * Text related functions
*/

void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);

/*
 * Parsing
*/

char	**ft_split(char const *s, char c);
int		count(char const *s, char c);
void	free_stack(t_stack **stack);
void	free_arr(char **arr);
void	p_error(char *s, int x);
void	free_exit(char *line, t_stack **stack_a, t_stack **stack_b);
char	**t_join(char **result, char **tmp, int wc);
void	check_int(char **result);
char	**get_arg(int i, char **arg);
long	ft_atoi(const char *str);
t_stack	*create_stack(int i, char **arg);
char	*ft_strdup(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*
 * INDEXING
*/

void	index_stack(t_stack **stack, int size);
int		get_min(t_stack *stack);
int		get_max(t_stack *stack);
int		get_last_ind(t_stack *stack_a);

/*
 * Sorting
*/

void	sort_two(t_stack **stack_a);
void	sort_three(t_stack **stack);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	send_to_b(t_stack **stack_a, t_stack **stack_b);
void	send_to_a(t_stack **stack_a, t_stack **stack_b);

/*
 * BONUS
*/

void	check_push(t_stack **stack_a, t_stack **stack_b, char *line);
void	check_swap(t_stack **stack_a, t_stack **stack_b, char *line);
void	check_rotate(t_stack **stack_a, t_stack **stack_b, char *line);
void	check_rrotate(t_stack **stack_a, t_stack **stack_b, char *line);
void	check_line(t_stack **stack_a, t_stack **stack_b, char *line);
#endif
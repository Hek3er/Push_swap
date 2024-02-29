NAME = push_swap
CHECKER = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = push_swap.c \
	  functions/indexing/get_last_ind.c \
	  functions/indexing/get_max.c \
	  functions/indexing/get_min.c \
	  functions/indexing/index_stack.c \
	  functions/linked_list/check_dup.c \
	  functions/linked_list/get_pos_piv.c \
	  functions/linked_list/get_size.c \
	  functions/linked_list/instructions0.c \
	  functions/linked_list/instructions1.c \
	  functions/linked_list/instructions2.c \
	  functions/linked_list/instructions3.c \
	  functions/linked_list/is_found.c \
	  functions/linked_list/is_in_stack.c \
	  functions/linked_list/is_sorted.c \
	  functions/linked_list/is_stack_empty.c \
	  functions/linked_list/last_node.c \
	  functions/linked_list/new_node.c \
	  functions/linked_list/pop.c \
	  functions/parsing/check_int.c \
	  functions/parsing/create_stack.c \
	  functions/parsing/error.c \
	  functions/parsing/freeing.c \
	  functions/parsing/ft_atoi.c \
	  functions/parsing/ft_isdigit.c \
	  functions/parsing/ft_strdup.c \
	  functions/parsing/ft_strlcpy.c \
	  functions/parsing/ft_strlen.c \
	  functions/parsing/get_arg.c \
	  functions/parsing/join_2d_array.c \
	  functions/parsing/split.c \
	  functions/sort/send_to_a.c \
	  functions/sort/send_to_b.c \
	  functions/sort/sort_five.c \
	  functions/sort/sort_four.c \
	  functions/sort/sort_three.c \
	  functions/sort/sort_two.c \
	  functions/text_functions/ft_putendl_fd.c \
	  functions/text_functions/ft_putstr_fd.c \

OBJ = $(SRC:.c=.o)
BSRC = bonus/checker.c \
	   bonus/check_line.c \
	   bonus/exc_cmd.c \
	   bonus/ft_strcmp.c \
	   functions/indexing/get_last_ind.c \
	   functions/indexing/get_max.c \
	   functions/indexing/get_min.c \
	   functions/indexing/index_stack.c \
	   functions/linked_list/check_dup.c \
	   functions/linked_list/get_pos_piv.c \
	   functions/linked_list/get_size.c \
	   functions/linked_list/instructions0.c \
	   functions/linked_list/instructions1.c \
	   functions/linked_list/instructions2.c \
	   functions/linked_list/instructions3.c \
	   functions/linked_list/is_found.c \
	   functions/linked_list/is_in_stack.c \
	   functions/linked_list/is_sorted.c \
	   functions/linked_list/is_stack_empty.c \
	   functions/linked_list/last_node.c \
	   functions/linked_list/new_node.c \
	   functions/linked_list/pop.c \
	   functions/parsing/check_int.c \
	   functions/parsing/create_stack.c \
	   functions/parsing/error.c \
	   functions/parsing/freeing.c \
	   functions/parsing/ft_atoi.c \
	   functions/parsing/ft_isdigit.c \
	   functions/parsing/ft_strdup.c \
	   functions/parsing/ft_strlcpy.c \
	   functions/parsing/ft_strlen.c \
	   functions/parsing/get_arg.c \
	   functions/parsing/join_2d_array.c \
	   functions/parsing/split.c \
	   get_next_line/get_next_line_utils.c \
	   get_next_line/get_next_line.c \
	   functions/text_functions/ft_putendl_fd.c \
	   functions/text_functions/ft_putstr_fd.c \

BOBJ = $(BSRC:.c=.o)

HEADER = includes/push_swap.h

%.o : %.c $(HEADER)
	@echo "Compiling $< ..."
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus : $(BOBJ)
	@$(CC) $(CFLAGS) $(BOBJ) -o $(CHECKER)

clean :
	@echo "cleaning"
	@rm -rf $(OBJ) $(BOBJ)

fclean :
	@echo "cleaning all"
	@rm -rf $(OBJ) $(BOBJ) $(NAME) $(CHECKER)

re : fclean all

.PHONY : clean fclean


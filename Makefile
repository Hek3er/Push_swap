CC = cc
CFLAGS = -Wall -Werror -Wextra 

SRCS = Push_swap.c parsing/parsing.c parsing/error.c parsing/parsing_2.c functions/the_free.c functions/instructions_1.c functions/indexing.c functions/instructions_2.c functions/instructions_3.c
OFILES = $(SRCS:.c=.o)
NAME = push_swap
LIB = ft_libft/libft.a printf/libftprintf.a

%.o: %.c includes/pushswap.h
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)


$(NAME): $(OFILES)
	@echo "Compiling ft_printf!"
	@cd printf && make && make clean
	@echo "Compiling libft!"
	@cd ft_libft && make && make clean
	@echo "Compiling pushswap!"
	@$(CC) $(CFLAGS) $(OFILES) $(LIB) -o $(NAME)
	@echo "Pushswap Compiled!"

clean:
	@echo "Removing Object Files!"
	@cd ft_libft && make clean
	@cd printf && make clean
	@rm -rf $(OFILES)

fclean: clean
	@cd ft_libft && make fclean
	@cd printf && make fclean
	@rm -rf $(NAME)

re: fclean all


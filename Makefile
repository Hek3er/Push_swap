CC = cc #need to change
CFLAGS = -g # need to change

SRCS = push_swap.c functions/quick_sort.c functions/sort2.c functions/indexing2.c functions/sort.c parsing/parsing3.c parsing/parsing.c parsing/error.c parsing/parse_inst.c parsing/parsing_2.c functions/the_free.c functions/instructions_1.c functions/indexing.c functions/instructions_2.c functions/instructions_3.c
BSRCS = ./bonus/checker.c parsing/parsing3.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c parsing/parsing.c parsing/parsing_2.c parsing/error.c parsing/parse_inst.c functions/indexing.c functions/indexing2.c functions/instructions_1.c functions/instructions_2.c functions/instructions_3.c functions/the_free.c 
OFILES = $(SRCS:.c=.o)
BFILES = $(BSRCS:.c=.o)
NAME = push_swap
BONUS_NAME = checker
LIB = ft_libft/libft.a printf/libftprintf.a

%.o: %.c includes/pushswap.h get_next_line/get_next_line.h
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OFILES)
	@echo "Compiling ft_printf!"
	@cd printf && make
	@echo "Compiling libft!"
	@cd ft_libft && make
	@echo "Compiling pushswap!"
	@$(CC) $(CFLAGS) $(OFILES) $(LIB) -o $(NAME)
	@echo "Pushswap Compiled!"

bonus : $(BFILES)
	@echo "Compiling ft_printf!"
	@cd printf && make
	@echo "Compiling libft!"
	@cd ft_libft && make
	@echo "Compiling checker!"
	@$(CC) $(CFLAGS) $(BFILES) $(LIB) -o $(BONUS_NAME)
	@echo "Checker Compiled!"

clean:
	@echo "Removing Object Files!"
	@cd ft_libft && make clean
	@cd printf && make clean
	@rm -rf $(OFILES) $(BFILES)

fclean: clean
	@cd ft_libft && make fclean
	@cd printf && make fclean
	@rm -rf $(NAME) $(BONUS_NAME)

re: fclean all


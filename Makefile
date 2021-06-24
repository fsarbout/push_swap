CC = gcc

CFLAGS = -Wall -g -Wextra -Werror 

NAME_CH = checker
NAME_PS = push_swap

SRC_CHECKER = srcs/*.c\
	libft/*.c\
	main_checker.c

SRC_PS = srcs/*.c\
	libft/*.c\
	main_push_swap.c
	

OBJ_CH = $(SRC_CHECKER:.C=.O)
OBJ_PS = $(SRC_PS:.C=.O)

all:$(NAME_CH) $(NAME_PS)

$(NAME_CH):$(SRC_CHECKER)
	@cd libft && make re
	@$(CC) $(SRC_CHECKER) $(CFLAGS) -o $(NAME_CH)

$(NAME_PS):$(SRC_PS) 
	@cd libft && make re
	@$(CC) $(SRC_PS) $(CFLAGS) -o $(NAME_PS)

clean:
	@cd libft && make clean
	@rm -rf *.o

fclean: clean
	@cd libft && make fclean
	@rm -rf $(NAME_CH)
	@rm -rf $(NAME_PS)

re: fclean all
NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
SRCFILES = libftprintf.c
OBJFILES = ${SRCFILES:.c=.o}
LIBFT_DIR = libft
LIBFT_LIB = ${LIBFT_DIR}/libft.a

.PHONY: all clean fclean re test

all: $(LIBFT_LIB) $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJFILES) $(LIBFT_LIB)
	ar rcs $(NAME) $(OBJFILES) $(LIBFT_LIB)

%.o: %.c
	cc $(FLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJFILES)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) main.o
	make -C $(LIBFT_DIR) fclean

re: fclean all

test: re
	cc main.c $(FLAGS) -Ilibft -L. -lftprintf -Llibft -lft -o main.o && ./main.o
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRCFILES = libftprintf.c
OBJFILES = $(SRCFILES:.c=.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR)

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJFILES)
	make -C $(LIBFT_DIR)
	ar rcs $(NAME) $(OBJFILES)

clean:
	rm -f $(OBJFILES) a.out
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

test: all
	cc main.c $(SRCFILES) $(FLAGS) $(LIBFT) $(INCLUDES) -o a.out && ./a.out


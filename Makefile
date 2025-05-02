NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCFILES = libftprintf.c libftprintf_utils.c
OBJFILES = $(SRCFILES:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR)

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJFILES) $(LIBFT)
	cp $(LIBFT) .
	ar -rcs $(NAME) $(OBJFILES) libft.a
	rm -f libft.a

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJFILES) test.out
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

test: all
	$(CC) main.c $(NAME) $(CFLAGS) $(INCLUDES) -o test.out && ./test.out
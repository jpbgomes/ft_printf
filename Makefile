NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRCFILES = libftprintf.c libftprintf_utils.c
OBJFILES = $(SRCFILES:.c=.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR)

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJFILES) $(LIBFT)
	# Create libftprintf.a with ft_printf objects
	ar rcs $(NAME) $(OBJFILES)
	# Extract libft.a objects and add them to libftprintf.a
	(cd $(LIBFT_DIR) && ar x libft.a)
	# Move extracted objects to current directory
	mv $(LIBFT_DIR)/*.o .
	# Add libft objects to libftprintf.a
	ar rcs $(NAME) *.o
	# Clean up extracted objects
	rm -f *.o
	ranlib $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJFILES) a.out
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

test: all
	cc main.c $(NAME) $(FLAGS) $(INCLUDES) -o a.out && ./a.out
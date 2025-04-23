NAME = libft.a
CFLAGS = -Wall -Wextra -Werror

SRCFILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_strrchr.c ft_toupper.c
OBJFILES = $(SRCFILES:.c=.o)

BONUSSRCFILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUSOBJFILES = $(BONUSSRCFILES:.c=.o)

.PHONY: all clean fclean re bonus test gdb gdb_all

all: $(NAME)

$(NAME): $(OBJFILES)
	ar rcs $(NAME) $(OBJFILES)

bonus: $(NAME) bonus_objs
	@for obj in $(BONUSOBJFILES); do \
		if ! ar -t $(NAME) | grep -q "$$obj"; then \
			ar rcs $(NAME) $$obj; \
		fi \
	done

bonus_objs: $(BONUSOBJFILES)

clean:
	rm -f $(OBJFILES) $(BONUSOBJFILES)

fclean: clean
	rm -f $(NAME) main.o main_gdb

re: fclean all

test: re bonus
	cc main.c $(CFLAGS) -L. -lft -o main.o && ./main.o

gdb: fclean gdb_all
	cc main.c -g -Wall -Wextra -Werror -L. -lft -o main_gdb
	gdb -tui ./main_gdb

gdb_all:
	cc -g -Wall -Wextra -Werror -c $(SRCFILES)
	ar rcs $(NAME) $(OBJFILES)

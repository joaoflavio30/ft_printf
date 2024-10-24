NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
      ft_putunsignednbr.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

.c.o:
	cc $(CFLAGS) -c $<

clean:
	rm -fr $(OBJ)

fclean: clean
	rm -fr $(NAME)
re: fclean all
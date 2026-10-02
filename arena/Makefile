NAME = arena.a

CFLAGGEN = -Wall -Wextra -Werror -g
ARFLAGGEN = rcs

CC = cc
AR = ar

QUELLE_DATEIEN = arena.c ../libft/ft_strlen.c ../libft/ft_calloc.c

OBJEKT_DATEIEN = $(QUELLE_DATEIEN:.c=.o)


all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGGEN) -c $< -o $@

$(NAME): $(OBJEKT_DATEIEN)
	$(AR) $(ARFLAGGEN) $(NAME) $(OBJEKT_DATEIEN)

clean: 
	rm -f $(OBJEKT_DATEIEN)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean flcean re

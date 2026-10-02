NAME = cub3D
LIBNAME = libft/libft.a datastructures/datastructures.a math/complex_math.a arena/arena.a

CFLAGGEN = -Wall -Wextra -Werror -g

CC = cc

QUELLE_DATEIEN = tester.c

OBJEKT_DATEIEN = $(QUELLE_DATEIEN:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGGEN) -c $< -o $@

libs:
	cd libft && make
	cd math && make
	cd datastructures && make
	cd arena && make

$(NAME): $(OBJEKT_DATEIEN) libs
	$(CC) $(CFLAGGEN) $(OBJEKT_DATEIEN) $(LIBNAME) -o $(NAME)

clean: 
	rm -f $(OBJEKT_DATEIEN)
	rm -f $(SUPRESSION_FILE)
	cd libft && make clean
	cd math && make clean
	cd datastructures && make clean
	cd arena && make clean

fclean: clean 
	rm -f $(NAME)
	rm -f $(LIBNAME)

re: fclean all

.PHONY: all clean flcean re

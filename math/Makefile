NAME = complex_math.a

CFLAGGEN = -Wall -Wextra -Werror
ARFLAGGEN = rcs

CC = cc
AR = ar

QUELLE_DATEIEN = complex_arithmetic.c complex_compare.c quake_sqrt.c rotations.c rounding.c trig.c vector_arithmetic.c vector_scaling.c

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

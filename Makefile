NAME = push_swap.a
CFLAGS = -Wall -Werror -Wextra
AR = ar -rcs
SRC = push_swap.c check.c moves.c stack_utils.c move_functions.c calculations.c printing.c
LIBPTF = libftprintf/libftprintf.a
all: $(NAME)
OBJ = $(SRC:.c=.o)
%.o: %.c
	cc $(CFLAGS) -c $(SRC)
$(LIBPTF):
	make -C libftprintf all
$(NAME): $(LIBPTF) $(OBJ)
	cp $(LIBPTF) $(NAME)
	$(AR) $(NAME) $(OBJ)
clean: cleanlib
	rm -f $(OBJ)
cleanlib: 
	make -C libftprintf clean
fcleanlib:
	make -C libftprintf fclean
fclean: fcleanlib clean
	rm -f $(NAME)
re: fclean $(NAME)
.PHONY: all clean fclean re

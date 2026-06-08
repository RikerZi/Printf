NAME = libftprintf.a
CCALL = cc -Wall -Wextra -Werror
SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)
all: $(NAME)
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
%.o: %.c libft.h
	$(CCALL) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re

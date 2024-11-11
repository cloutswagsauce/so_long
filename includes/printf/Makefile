NAME = libftprintf.a

SRCS = ft_printf.c print_di.c print_p.c print_s.c print_u.c print_hex.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror 

HEADER = ft_printf.h 

AR = ar rcs

RM = rm -f 

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	${MAKE} -C ./libft clean

fclean: clean
	$(RM) $(NAME)
	${MAKE} -C ./libft fclean


re: fclean all

.PHONY: all clean fclean re
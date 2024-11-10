# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 18:17:13 by lfaria-m          #+#    #+#              #
#    Updated: 2024/11/10 18:44:48 by lfaria-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = so_long

# Source files
SRCS = main.c handle_input.c map_read_file.c map_render.c init_game.c validate_map_file.c clean_exit.c

# Object files
OBJS = $(SRCS:.c=.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
MLX_DIR = includes/minilibx
LIB_DIR = includes/libft

MLX = $(MLX_DIR)/libmlx.a
LIB = $(LIB_DIR)/libft.a

# Archiver and remove command
AR = ar rcs
RM = rm -f 

# Library flags 
MLX_FLAGS = -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

LIB_FLAGS = -L $(LIB_DIR) -lft

# Rule to build the executable
all: $(NAME)

# Linking the executable
$(NAME): $(OBJS) $(MLX) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIB_FLAGS) -o $(NAME)

# Compile source files into object files
%.o: %.c 
	$(CC) $(CFLAGS) -I $(MLX_DIR) -I$(LIB_DIR) -c $< -o $@

# Build MinilibX if not already built
$(MLX):
	make -C $(MLX_DIR)
$(LIB):
	make -C $(LIB_DIR)


# Clean object files
clean:
	$(RM) $(OBJS)
	make -C $(MLX_DIR) clean
	make -C $(LIB_DIR) clean

# Clean everything
fclean: clean
	$(RM) $(NAME)
	make -C $(MLX_DIR) fclean
	make -C $(LIB_DIR) fclean

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re

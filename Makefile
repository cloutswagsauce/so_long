# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 18:17:13 by lfaria-m          #+#    #+#              #
#    Updated: 2024/11/01 19:15:56 by lfaria-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = so_long

# Source files
SRCS = main.c

# Object files
OBJS = $(SRCS:.c=.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = minilibx

MLX = $(MLX_DIR)/libmlx.a

# Archiver and remove command
AR = ar rcs
RM = rm -f 

# Library flags (adjust for Linux if needed)
MLX_FLAGS = -L includes/$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# Rule to build the executable
all: $(NAME)

# Linking the executable
$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

# Compile source files into object files
%.o: %.c 
	$(CC) $(CFLAGS) -I includes/$(MLX_DIR) -c $< -o $@

# Build MinilibX if not already built
$(MLX):
	make -C includes/$(MLX_DIR)



# Clean object files
clean:
	$(RM) $(OBJS)

# Clean everything
fclean: clean
	$(RM) $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re

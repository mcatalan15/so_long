# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 10:58:09 by mcatalan@st       #+#    #+#              #
#    Updated: 2023/11/07 19:55:06 by mcatalan@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
GDBFLAG = -g

# Colors
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = ./includes/libft
PRINTF_DIR = ./includes/ft_printf
MLX_DIR = ./includes/mlx

# Source files and corresponding object files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Executable name
TARGET = so_long

# Libraries
LIBS = -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -L$(MLX_DIR) -lmlx -g -framework OpenGL -framework AppKit

# Include directories
INC_DIRS = -I$(LIBFT_DIR)/includes -I$(PRINTF_DIR)/includes -I$(MLX_DIR) -I$(SRC_DIR)

# Build rules
all: subsystems $(TARGET)
	@echo "$(GREEN)Build finished$(RESET)"

subsystems:
	@make -s -C $(LIBFT_DIR)
	@make -s -C $(PRINTF_DIR)
	@make -s -C $(MLX_DIR)


$(TARGET): $(OBJ_FILES)
	@echo "$(GREEN)Bulding libs and objets...$(RESET)"
	$(CC) $(CFLAGS) $(GDBFLAG) $(INC_DIRS) $^ -o $@ $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(GDBFLAG) $(INC_DIRS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning up objets...$(RESET)"
	@make -s -C $(MLX_DIR) clean
	@make -s -C $(LIBFT_DIR) clean
	@make -s -C $(PRINTF_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Cleaning all...$(RESET)"
	rm -f $(TARGET)
	@echo "$(RED)Cleaning libft...$(RESET)"
	@make -s -C $(LIBFT_DIR) fclean
	@echo "$(RED)Cleaning ft_printf...$(RESET)"
	@make -s -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

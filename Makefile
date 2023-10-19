# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 10:58:09 by mcatalan@st       #+#    #+#              #
#    Updated: 2023/10/19 13:01:28 by mcatalan@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# LIBFT_D	= includes/libft/
# LIBFT	= libft.a

# FT_PRINTF_D	=	includes/ft_printf/
# FT_PRINTF	=	ft_printf.a

# CC = gcc

# EXEC 	= 	so_long

# SRCS		= 	src/main.c	\
# 				src/controlls.c\
# 				src/map.c	\
# 				src/movements.c \
# 				src/utils.c	\
# 				src/window.c	\

# OBJS 		= 	$(SRCS:.c=.o)

# DEPS	=	$(SRCS:.c=.d)

# INCLUDE = -I./
# RM = rm -f
# CFLAGS  =  -Wall -Wextra -Werror
# MLXFALGS = -L includes/mlx/ -lmlx -framework OpenGL -framework AppKit

# all:	
# 	$(CC) $(CFLAGS) ./src/*.c -o $(EXEC)

# makelibft:
# 	@make --no-print-directory -C $(LIBFT_D)

# makeftprintf:
# 	@make --no-print-directory -C $(FT_PRINTF_D)

# mlx:
# 	@make	--no-print-directory -C	$(MLX_DIR) libmlx.a

# all:	make$(EXEC)

# %.o: %.c
# 	$(CC) $(CFLAGS) -MMD $(INCLUDE) -c $< -o $@

# $(NAME): $(OBJS) $(LIBFT_D)$(LIBFT) $(FT_PRINTF_D)$(FT_PRINTF) 
# 	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBFT_D)$(LIBFT) $(FT_PRINTF_D)$(FT_PRINTF)
# -include $(DEPS)

CC = gcc
FLAGS = -o so_long -g -framework OpenGL -framework AppKit -L./includes/mlx -lmlx -L./includes/libft -L./includes/ft_printf
RMFOR1337 = rm -rf a.out
RM = @rm -rf
BSRC = $(shell find bonus/mainfiles -name "bonus*.c") 

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all:
	$(CC) ./src/*.c $(FLAGS)
	make -C ./src/
	@echo $(G)ALERT [PLS go to directory bonus --- "cd ./bonus" and type for run -- "./so_long_bonus ../map/mapchose.ber"]$(G)
	$(RMFOR1337)

fclean:
	$(RM)  so_long so_long.dSYM
	$(RM) ./mainfiles/*.o ./mainfiles/mainfiles
	$(RM) ./minilibx/*.o
	$(RM) ./bonus/so_long_bonus
	$(RM) ./bonus/so_long_bonus.dSYM
	@echo $(B)Removed [TEMPORARY FILES]$(X)
	@echo $(R)Removed [./mainfiles/*.o]$(X)
	@echo $(R)Removed [./minilibx/*.o]$(X)
	@echo $(R)Removed [REMOVED FINISH]$(X)
	@echo $(R)Removed [REMOVED FINISH]$(X)
	@echo $(R)Removed [REMOVED FINISH]$(X)
%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

norm:
	@echo $(B)[--NORMINETTE SUCCES %100 CLEAN CODE...]$(B)
	norminette $(shell find ./mainfiles/ -name "*.c")
.PHONY: re norm fclean clean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 10:58:09 by mcatalan@st       #+#    #+#              #
#    Updated: 2023/10/18 21:16:37 by mcatalan@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_D	= includes/libft/
LIBFT	= libft.a

FT_PRINTF_D	=	includes/ft_printf/
FT_PRINTF	=	ft_printf.a

CC = gcc

NAME 	= 	so_long

SRCS		= 	src/main.c	\
				src/controlls.c\
				src/map.c	\
				src/movements.c \
				src/utils.c	\
				src/window.c	\

OBJ 		= 	$(SRCS:.c=.o)

MLX_D		= includes/mlx/
MLX_LIB 	= $(MLX_D)libmlx.a
MLX_FLAGS 	= -L./includes/mlx -lmlx -framework OpenGL -framework AppKit

CFLAGS  =  -Wall -Wextra -Werror

INCLUDE = -I./

$(LIBFT_D)$(LIBFT):
	@make --no-print-directory -s -C $(LIBFT_D)

$(FT_PRINTF_D)$(FT_PRINTF):
	@make --no-print-directory -s -C $(FT_PRINTF_D)

%.o: %.c
	$(CC) $(CFLAGS) -I $(HEADER) -MMD -Imlx -c $< -o $@


$(NAME):	$(OBJ) $(LIBFT_D)$(LIBFT) $(FT_PRINTF_D)$(FT_PRINTF)
	@$(CC) $(OBJ) -o $(NAME) $(MLX_FLAGS) $(MLX_LIB)

all:		subsystems $(NAME)

subsystems:
	@make	--no-print-directory -C	$(MLX_DIR) libmlx.a

libft:
	@make --no-print-directory -C $(LIBFT_D) libft
	
ftprintf:
	@make --no-print-directory -C $(FT_PRINTF_D) ftprintf

libs:
	subsystems printf libft

clean:
	rm -f $(OBJ) $(LIBFT_D)$(LIBFT) $(FT_PRINTF_D)$(FT_PRINTF) $(NAME)


fclean:		clean
			rm -f $(NAME)

re:			fclean all

# v:			re
# 			-v

.PHONY:		all clean fclean re subsystems libft ftprintf libs
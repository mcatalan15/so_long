# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 10:58:09 by mcatalan@st       #+#    #+#              #
#    Updated: 2023/10/04 14:45:35 by mcatalan@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_D	= includes/libft/
LIBFT	= libft.a

FT_PRINTF_D	=	includes/ft_printf/
FT_PRINTF	=	ft_printf.a

CC = gcc

NAME 	= 	so_long

SRCS		= 	src/main.c 

OBJ 		= 	$(SRCS:.c=.o)

MLX_DIR 	= includes/mlx/
MLX_LIB 	= $(MLX_DIR)libmlx.a
MLX_FLAGS 	= -Lincludes/mlx -lmlx -framework OpenGL -framework AppKit

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
	@make	--no-print-directory -C	$(MLX_DIR)

# makelibft:
# 	@make --no-print-directory -C $(LIBFT_D)
	
# makeftprintf:
# 	@make --no-print-directory -C $(FT_PRINTF_D)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re
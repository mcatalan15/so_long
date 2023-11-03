/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:45:47 by mcatalan          #+#    #+#             */
/*   Updated: 2023/11/03 10:38:21 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../includes/ft_printf/includes/ft_printf.h"
# include "../includes/libft/libft.h"
# include "../includes/mlx/mlx.h"
# include "graphic.h"
// # include "get_next_line.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53
# define SIZE 48
# define MAP_CHARS "10PCE\n"

t_block	set_block(char name);

int		key_check(int key_code, t_game *game);
int		destroy_window(t_game *game);
int		ft_line_length(int fd);
int		ft_count_lines(int fd);

void	baslangic(t_game *game);
void	message(char *msg, t_game *game);
void	wall_control(t_game *game);
void	map_control(t_game *game);
void	game_control(t_game *game);
int		move_check(t_game *game, int i, int j);
void	ft_window_size(t_game *data, char **argv);
void	*myfree(void *str);
void	*put_image(t_image image, int x, int y);
void	create_map(t_game *game, int i);
void	create_floor(t_game game, int b);
void	create_map_length(char *area, t_game *game, int i);
void	create_map_line(t_game *game, char **argv);
void	update(t_game *game, int x, int y);
void	right(t_game *game);
void	up(t_game *game);
void	down(t_game *game);
void	left(t_game *game);
int		map_destroy(t_game *game);

char	*get_next_line(int fd);
void	messages(char *msg, t_game *game);

void	checker(t_game *game);

//map2.c
// void create_map_line_copy(t_game *game, char **argv);
// void map_destroy_copy(t_game *game);

void	print_map(t_game *game);
void	print_map_copy(t_game *game);

// utils2.c
void	print_map(t_game *game);
void	print_map_copy(t_game *game);

int msg(char *str);

#endif
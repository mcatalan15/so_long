/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:45:47 by mcatalan          #+#    #+#             */
/*   Updated: 2023/10/18 18:44:43 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/includes/ft_printf.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include "checker.h"
# include "graphic.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

#define UP 13
#define DOWN 1
#define LEFT 0
#define RIGHT 2
#define ESC 53
#define SIZE 48

//controlls.c
int move_check(t_game *game, int i, int j);
void map_control(t_game *game);
void wall_control(t_game *game);
void game_control(t_game *game);

//main.c
int main(int argc, char **argv);
int so_long(int argc, char **argv);
int checker(int argc, char **argv);
void game(char **argv);
void start(t_game *game);
void helper(void);
int keyboard(int key_press, t_game *game);

//map.c
void create_map(t_game *game, char **argv);
void create_map_length(char *area, t_game *game, int i);
void create_floor(t_game game, int b);
void mount_map(t_game *game, int i);
void map_destroy(t_game *game);

//utils.c
t_block set_block(char name);
void *put_image(t_img img, int x, int y);
char *get_next_line(int fd);

// window.c
int destroy_window(t_game *game);
int ft_line_length(int fd);
int ft_count_lines(int fd);
void size_window(t_game *data, char **argv);

//movements.c
void down(t_game *game);
void up(t_game *game);
void left(t_game *game);
void right(t_game *game);
void update(t_game *game, int x, int y);

#endif
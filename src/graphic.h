/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:25:05 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/10/29 20:58:55 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

typedef struct s_player
{
	int x;
	int y;
	int coin;
	int hareket;

} t_player;

typedef struct s_game
{
	void *mlx;
	void *window;
	char **map;
	char **map_copy;
	int items;
	int ppos;
	int exitpos;
	size_t size_x;
	int size_y;
	t_player player;
} t_game;

typedef struct s_image
{
	char *relative_path;
	struct s_game wlx;
	void *img;
	int img_h;
	int img_w;
} t_image;

typedef struct s_block
{
	char *name;
	char *relative_path;
} t_block;

#endif
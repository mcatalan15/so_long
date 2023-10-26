/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:25:05 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/10/26 18:08:52 by mcatalan@st      ###   ########.fr       */
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
	int coincheck;
	int playercheck;
	int exitcheck;
	size_t size_x;
	int size_y;
	t_player player;
} t_game;

typedef struct s_image
{
	char *relative_path;
	struct s_game wlx;
	void *img;
	int img_height;
	int img_width;
} t_image;

typedef struct s_block
{
	char *name;
	char *relative_path;
} t_block;

// typedef struct s_player
// {
// 	int	x;
// 	int	y;
// 	int	collectible;
// 	int	move;
// }		t_player;

// typedef struct s_game
// {
// 	void		*mlx;
// 	void		*win;
// 	char		**map;
// 	int			items;
// 	int			ppos;
// 	int			exitpos;
// 	size_t		size_x;
// 	int			size_y;
// 	t_player	player;
// }				t_game;

// typedef struct s_img
// {
// 	char			*relative_path;
// 	struct s_game	wlx;
// 	void			*img;
// 	int				img_h;
// 	int				img_w;
// }					t_img;

// typedef struct s_block
// {
// 	char	*name;
// 	char	*relative_path;
// }			t_block;

#endif
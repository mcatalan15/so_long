/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:25:05 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/10/31 11:33:13 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# include <stdbool.h>

typedef struct s_player
{
	int	x;
	int	y;
	int	coin;
	int	hareket;

}	t_player;

typedef struct s_game
{
	t_player	player;
	void		*mlx;
	void		*window;
	char		**map;
	char		**map_copy;
	int			items;
	int			ppos;
	int			exitpos;
	size_t		size_x;
	int			size_y;
	bool		find_end;
	int			num_coins_find;
}	t_game;

typedef struct s_image
{
	struct s_game	wlx;
	char			*relative_path;
	void			*img;
	int				img_h;
	int				img_w;
}	t_image;

typedef struct s_block
{
	char	*name;
	char	*relative_path;
}	t_block;

#endif
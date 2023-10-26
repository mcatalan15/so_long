/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:43:10 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/10/26 18:10:04 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include "so_long.h"

void update(t_game *game, int x, int y)
{
	t_image image;

	image.relative_path = "./img/xpm/asphalt.xpm";
	image.wlx = *game;
	put_image(image, game->player.x, game->player.y);
	put_image(image, x, y);
}

void right(t_game *game)
{
	int i;
	int j;
	t_image image;

	image.relative_path = "./img/xpm/alonso.xpm";
	image.wlx = *game;
	i = game->player.y;
	j = game->player.x + 48;
	if ((move_check(game, (i / 48), (j / 48)) != 1))
	{
		game->player.hareket++;
		ft_printf("Number of movements = %d\n", game->player.hareket);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}

void left(t_game *game)
{
	int i;
	int j;
	t_image image;

	image.relative_path = "./img/xpm/alonso_left.xpm";
	image.wlx = *game;
	i = game->player.y;
	j = game->player.x - 48;
	if ((move_check(game, (i / 48), (j / 48)) != 1))
	{
		game->player.hareket++;
		ft_printf("Number of movements = %d\n", game->player.hareket);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}

void up(t_game *game)
{
	int i;
	int j;
	t_image image;

	image.relative_path = "./img/xpm/alonso_left.xpm";
	image.wlx = *game;
	i = game->player.y - 48;
	j = game->player.x;
	if ((move_check(game, (i / 48), (j / 48)) != 1))
	{
		game->player.hareket++;
		ft_printf("Number of movements = %d\n", game->player.hareket);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}

void down(t_game *game)
{
	int i;
	int j;
	t_image image;

	image.relative_path = "./img/xpm/alonso_down.xpm";
	image.wlx = *game;
	i = game->player.y + 48;
	j = game->player.x;
	if ((move_check(game, (i / 48), (j / 48)) != 1))
	{
		game->player.hareket++;
		ft_printf("Number of movements = %d\n", game->player.hareket);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:43:10 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/10/19 12:48:30 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long.h"

void	update(t_game *game, int x, int y)
{
	t_img	img;

	img.relative_path = " ./../img/floor.xpm";
	img.wlx = *game;
	put_image(img, game->player.x, game->player.y);
	put_image(img, x, y);
}

void	right(t_game *game)
{
	t_img	img;
	int		i;
	int		j;

	img.relative_path = "./../img/bayraktarTB2.xpm";
	img.wlx = *game;
	i = game->player.y;
	j = game->player.x + 48;
	if ((move_check(game, (i / 48), (j / 48)) != 1))
	{
		game->player.move++;
		printf("Num of movements = %d\n", game->player.move);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(img, j, i);
	}
}

void	left(t_game *game)
{
	int		i;
	int		j;
	t_img	img;

	img.relative_path = "./../img/left.xpm";
	img.wlx = *game;
	i = game->player.y;
	j = game->player.x - 48;
	if ((move_check(game, (i / 48), (j / 48)) != 1))
	{
		game->player.move++;
		printf("Num of movements = %d\n", game->player.move);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(img, j, i);
	}
}

void	up(t_game *game)
{
	int		i;
	int		j;
	t_img	img;

	img.relative_path = "./img/ust.xpm";
	img.wlx = *game;
	i = game->player.y - 48;
	j = game->player.x;
	if ((move_check(game, (i / 48), (j / 48)) != 1))
	{
		game->player.move++;
		printf("Num of movements = %d\n", game->player.move);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(img, j, i);
	}
}

void	down(t_game *game)
{
	int		i;
	int		j;
	t_img	img;

	img.relative_path = "./img/karakter.xpm";
	img.wlx = *game;
	i = game->player.y + 48;
	j = game->player.x;
	if ((move_check(game, (i / 48), (j / 48)) != 1))
	{
		game->player.move++;
		printf("Num of movements = %d\n", game->player.move);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(img, j, i);
	}
}

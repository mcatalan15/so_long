/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:32:26 by mcatalan          #+#    #+#             */
/*   Updated: 2023/11/02 10:54:51 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	message(char *msg, t_game *game)
{
	ft_printf("%s", msg);
	map_destroy(game);
	exit(0);
}

int	keyboard(int key_code, t_game *game)
{
	if (key_code == ESC)
		destroy_window(game);
	if (key_code == UP)
		up(game);
	if (key_code == RIGHT)
		right(game);
	if (key_code == LEFT)
		left(game);
	if (key_code == DOWN)
		down(game);
	return (0);
}

void	init_struct(t_game *game)
{
	game->items = 0;
	game->map = NULL;
	game->exitpos = 0;
	game->player.coin = 0;
	game->player.hareket = 0;
	game->ppos = 0;
	game->map_copy = NULL;
	game->num_coins_find = 0;
	game->find_end = false;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error\nJust ./so_long. Add the map wit the .ber extension\n");
		exit (0);
	}
	game.mlx = mlx_init();
	ft_window_size(&game, argv);
	game.window = mlx_new_window(game.mlx, game.size_x, game.size_y,
			"mcatalan so_long");
	init_struct(&game);
	create_map_line(&game, argv);
	game_control(&game);
	checker(&game);
	mlx_hook(game.window, 17, 1L << 2, destroy_window, &game);
	mlx_key_hook(game.window, keyboard, &game);
	mlx_loop(game.mlx);
}

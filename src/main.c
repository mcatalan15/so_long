/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:32:26 by mcatalan          #+#    #+#             */
/*   Updated: 2023/10/26 18:04:22 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_map(char *filename)
{
	(void)filename;
	ft_printf("checking\n");
	return (0);
}

void message(char *msg, t_game *game)
{
	ft_printf("%s", msg);
	map_destroy(game);
	exit(0);
}

int keyboard(int key_code, t_game *game)
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

void init_struct(t_game *game)
{
	game->coincheck = 0;
	game->exitcheck = 0;
	game->player.coin = 0;
	game->player.hareket = 0;
	game->playercheck = 0;
}

int main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		message("Error\nJust ./so_long and the map.ber\n", &game);
	if (check_map(argv[1]) == 1)
		message("Error\n", &game);
	ft_window_size(&game, argv);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.size_x, game.size_y, "so_long mcatalan");
	init_struct(&game);
	create_map_line(&game, argv);
	game_control(&game);
	mlx_hook(game.window, 17, 1L << 2, destroy_window, &game);
	mlx_key_hook(game.window, keyboard, &game);
	mlx_loop(game.mlx);
}

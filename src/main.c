/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:32:26 by mcatalan          #+#    #+#             */
/*   Updated: 2023/10/19 12:49:53 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long.h"

// void	messages(char *msg, t_game *game)
// {
// 	printf("%s", msg);
// 	map_destroy(game);
// 	exit(0);
// }

int	keyboard(int key_press, t_game *game)
{
	if (key_press == ESC)
		destroy_window(game);
	if (key_press == UP)
		up(game);
	if (key_press == RIGHT)
		right(game);
	if (key_press == LEFT)
		left(game);
	if (key_press == DOWN)
		down(game);
	return (0);
}

void	start(t_game *game)
{
	game->items = 0;
	game->exitpos = 0;
	game->player.collectible = 0;
	game->ppos = 0;
}

void	game(char **argv)
{
	t_game	game;

	size_window(&game, argv);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.size_x, game.size_y,
			"mcatalan SO_LONG");
	start(&game);
	create_map(&game, argv);
	mlx_hook(game.win, 17, 1L << 2, mlx_destroy_window, &game);
	mlx_key_hook(game.win, keyboard, &game);
	mlx_loop(game.mlx);
}

int	so_long(int argc, char **argv)
{
	checker(argc, argv);
	game(argv);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		so_long(argc, argv);
	else if (argc != 2 || (argv[1][0] == '-' && argv[1][1] == 'h'))
	{
		helper();
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:32:26 by mcatalan          #+#    #+#             */
/*   Updated: 2023/10/05 11:49:33 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long.h"

void	helper(void)
{
	ft_printf("HOW TO PLAY SO_LONG:\n","\tW:\n","\tS\n","\tA\n", "\tD\n");
}

int	start(t_game *game)
{
	game->collectable = 0;
	game->exitpos = 0;
	game->player.collectible = 0;
	game->playerpos = 0;
}

int game(int argc, char **argv)
{
	t_game game;
	
	size_window(&game, argv);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.size_x, game.size_y, "mcatalan SO_LONG");
	start(&game);
	create_map();
}

int checker(void)
{
	ft_printf("esto es checker");
}

int so_long(int argc, char **argv)
{
	checker();
	game(argc, argv);
	return(0);
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

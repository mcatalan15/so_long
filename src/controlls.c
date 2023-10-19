/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:37:30 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/10/19 12:39:08 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long.h"

int	move_check(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		return (1);
	else if (game->map[i][j] == 'C')
	{
		game->player.collectible++;
		game->map[i][j] = '0';
	}
	else if (game->map[i][j] == 'E')
	{
		if (game->player.collectible != game->items)
		{
			printf("Items left to be collected\n");
			return (1);
		}
		ft_printf("Game compleated\n");
		// message(GREEN "Game completed\n" ENDC, game);
		return (0);
	}
	return (0);
}

void	map_control(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
				game->exitpos++;
			j++;
		}
		i++;
	}
	if (game->items == 0)
		ft_printf("Error\nNo items to collect!\n");
		// message(RED "Error\nNo collecteble!\n" ENDC, game);
	if (game->exitpos == 0)
		ft_printf("Error\nThere's no exit door on the map!\n");
		// message("Error\nThere's no exit door on the map!\n", game);
	if (game->ppos != 1)
		ft_printf("Error\nYou can only have 1 character!\n");
		// message("Error\nYou can only have 1 character!\n", game);
}

void	wall_control(t_game *game)
{
	size_t	x;
	int		y;

	y = 0;
	while (y < (game->size_y / SIZE))
	{
		x = 0;
		while (x < (game->size_x / SIZE))
		{
			if ((y == 0 || x == 0) && game->map[y][x] != '1')
				ft_printf("Error\nThe map must be walled\n");
				// message(RED "Error\nThe map must be walled\n" ENDC, game);
			else if ((y == (game->size_y / SIZE - 1)
					|| x == (game->size_x / SIZE - 1))
				&& game->map[y][x] != '1')
				ft_printf("Error\nThe map must be walled\n");
				// message(RED "Error\nThe map must be walled\n" ENDC, game);
				x++;
		}
		y++;
	}
}

void	game_control(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->items++;
			if (game->map[i][j] == 'P')
			{
				game->player.x = j * SIZE;
				game->player.y = i * SIZE;
				game->ppos++;
			}
			j++;
		}
		i++;
	}
	map_control(game);
	wall_control(game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:37:30 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/11/03 11:02:48 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
				msg("Error\nThe map must be walled\n");
			else if ((y == (game->size_y / SIZE - 1)
					|| x == (game->size_x / SIZE - 1))
				&& game->map[y][x] != '1')
				msg("Error\nThe map must be walled!\n");
			x++;
		}
		y++;
	}
}

int	msg(char *str)
{
	ft_printf("%s", str);
	exit (0);
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
		msg("Error\nNo items to collect on the map!\n");
	if (game->exitpos == 0)
		msg("Error\nNo exit door on the map!\n");
	if (game->ppos < 1)
		msg("Error\nThere's no player on the map!\n");
	if (game->ppos > 1)
		msg("Error\nThere's more than 1 player on the map!\n");
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

int	move_check(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		return (1);
	else if (game->map[i][j] == 'C')
	{
		game->player.coin++;
		game->map[i][j] = '0';
	}
	else if (game->map[i][j] == 'E')
	{
		if (game->player.coin != game->items)
		{
			printf("There are items left to be collected!\n");
			return (1);
		}
		msg("You win!\n");
		return (0);
	}
	return (0);
}

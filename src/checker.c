/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:49:25 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/11/03 11:57:40 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_valid_move(t_game *game, int row, int col)
{
	int	numrows;
	int	numcols;

	numcols = game->size_x / 48;
	numrows = game->size_y / 48;
	if ((row >= 0 && row < numrows && col >= 0 && col < numcols)
		&& (game->map_copy[row][col] == 'C' || game->map_copy[row][col] == 'E'
	|| game->map_copy[row][col] == '0'))
	{
		if (game->map_copy[row][col] == 'C')
			game->num_coins_find++;
		else if (game->map_copy[row][col] == 'E')
			game->find_end = true;
		return (true);
	}
	return (false);
}

bool	find_path(t_game *game, int row, int col)
{
	int	i;
	int	new_row;
	int	new_col;

	i = 0;
	game->map_copy[row][col] = '.';
	int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	while (i < 4)
	{
		new_row = row + moves[i][0];
		new_col = col + moves[i][1];
		if (is_valid_move(game, new_row, new_col))
		{
			if (find_path(game, new_row, new_col))
			{
				return (true);
			}
		}
		i++;
	}
	game->map_copy[row][col] = 'X';
	return (false);
}

void	checker(t_game *game)
{
	size_t	start_row;
	size_t	start_col;
	size_t	size_y;
	size_t	size_x;
	size_t	i;
	size_t	j;

	i = 0;
	size_x = game->size_x / 48;
	size_y = (game->size_y / 48);
	copy_map(game);
	while (i < size_y)
	{
		j = 0;
		while (j < size_x)
		{
			if (game->map_copy[i][j] == 'P')
			{
				start_row = i;
				start_col = j;
				break ;
			}
			j++;
		}
		i++;
	}
	find_path(game, start_row, start_col);
	if (game->find_end && game->items == game->num_coins_find)
		printf("EL mapa es solucionalble\n");
	else
		msg("The map has no solution\n");
}

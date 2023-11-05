/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:49:25 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/11/05 20:40:07 by mcatalan@st      ###   ########.fr       */
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
	game->map_copy[row][col] = '.';
	if (is_valid_move(game, row - 1, col))
	{
		if (find_path(game, row - 1, col))
			return (true);
	}
	if (is_valid_move(game, row + 1, col))
	{
		if (find_path(game, row + 1, col))
			return (true);
	}
	if (is_valid_move(game, row, col - 1))
	{
		if (find_path(game, row, col - 1))
			return (true);
	}
	if (is_valid_move(game, row, col + 1))
	{
		if (find_path(game, row, col + 1))
			return (true);
	}
	game->map_copy[row][col] = 'X';
	return (false);
}

void	initialize_and_copy_map(t_game *game, size_t *s_row, size_t *s_col)
{
	size_t	size_x;
	size_t	size_y;
	size_t	i;
	size_t	j;

	size_x = game->size_x / 48;
	size_y = game->size_y / 48;
	i = 0;
	copy_map(game);
	while (i < size_y)
	{
		j = 0;
		while (j < size_x)
		{
			if (game->map_copy[i][j] == 'P')
			{
				*s_row = i;
				*s_col = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	checker(t_game *game)
{
	size_t	start_row;
	size_t	start_col;

	initialize_and_copy_map(game, &start_row, &start_col);
	find_path(game, start_row, start_col);
	if (game->find_end && game->items == game->num_coins_find)
		printf("\n");
	else
		msg("The map has no solution\n");
}

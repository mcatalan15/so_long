/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:49:25 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/11/03 10:42:00 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	copy_map(t_game *game)
{
	int	rows;
	int	cols;

	cols = game->size_x / 48;
	rows = game->size_y / 48;
	if (game->map_copy != NULL)
	{
		for (int i = 0; i < rows; i++)
			free(game->map_copy[i]);
		free(game->map_copy);
	}
	game->map_copy = (char **)malloc(rows * sizeof(char *));
	if (game->map_copy == NULL)
		return (0);

	for (int i = 0; i < rows; i++)
	{
		(game->map_copy)[i] = (char *)malloc((cols + 1) * sizeof(char));
		if ((game->map_copy)[i] == NULL)
		{
			for (int j = 0; j < i; j++)
			{
				free((game->map_copy)[j]);
			}
			free(game->map_copy);
			game->map_copy = NULL;
			message("Error\nNot possible to copy the map\n", game);
		}
		ft_strcpy((game->map_copy)[i], game->map[i]);
	}

	return (1);
}

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

	int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	
	for (int i = 0; i < 4; i++)
	{
		int new_row = row + moves[i][0];
		int new_col = col + moves[i][1];

		if (is_valid_move(game, new_row, new_col))
		{
			if (find_path(game, new_row, new_col))
			{
				return (true);
			}
		}
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

	size_x = game->size_x / 48;
	size_y = (game->size_y / 48);
	copy_map(game);
	for (size_t i = 0; i < size_y; i++)
	{
		for (size_t j = 0; j < size_x; j++)
		{
			if (game->map_copy[i][j] == 'P')
			{
				start_row = i;
				start_col = j;
				break ;
			}
		}
	}
	find_path(game, start_row, start_col);
	if (game->find_end && game->items == game->num_coins_find)
		printf("EL mapa es solucionalble\n");
	else
		msg("The map has no solution\n");
	
}

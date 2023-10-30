/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:49:25 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/10/30 13:03:23 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int copy_map(t_game *game)
{
	int rows = game->size_y / 48;
	int cols = game->size_x / 48;

	if (game->map_copy != NULL)
	{
		for (int i = 0; i < rows; i++)
			free(game->map_copy[i]);
		free(game->map_copy);
	}
	game->map_copy = (char **)malloc(rows * sizeof(char *));
	if (game->map_copy == NULL)
		return 0;

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

	return 1;
}

void print_map_copy(t_game *game)
{
	int rows = game->size_y / 48;
	int cols = game->size_x / 48;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%c", game->map_copy[i][j]);
		}
		printf("\n");
	}
}

void print_map(t_game *game)
{
	int rows = game->size_y / 48;
	int cols = game->size_x / 48;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%c", game->map[i][j]);
		}
		printf("\n");
	}
}

bool is_valid_move(t_game *game, int row, int col, int numRows, int numCols)
{
	if (row >= 0 && row < numRows && col >= 0 && col < numCols)
		return (game->map_copy[row][col] == '0' || game->map_copy[row][col] == 'C');
	return false;
}

bool find_path(t_game *game, int row, int col)
{
	int numRows = game->size_y / 48;
	int numCols = game->size_x / 48;
	// ft_printf("find_path\n");
	// print_map(game);
	if (game->map_copy[row][col] == 'E')
	{
		ft_printf("hay E\n");
		return true;
	}

	game->map_copy[row][col] = '.';

	int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	
	for (int i = 0; i < 4; i++)
	{
		int new_row = row + moves[i][0];
		int new_col = col + moves[i][1];

		if (is_valid_move(game, new_row, new_col, numRows, numCols))
		{
			if (find_path(game, new_row, new_col))
			{
				return true;
			}
		}
	}
	game->map_copy[row][col] = 'X';

	return false;
}


void	checker(t_game *game)
{
	size_t start_row, start_col;
	size_t size_y = (game->size_y / 48);//-1
	size_t size_x = game->size_x/48;

	copy_map(game);
	
	// ft_printf("print map\n");
	// print_map(game);
	// ft_printf("print map copy\n");
	// print_map_copy(game);


	for (size_t i = 0; i < size_y; i++)
	{
		for (size_t j = 0; j < size_x; j++)
		{
			if (game->map_copy[i][j] == 'P')
			{
				start_row = i;
				start_col = j;
				break;
			}
		}
	}
	// ft_printf("print map\n");
	// ft_printf("%zu\n%zu\n",start_row,start_col);
	if (find_path(game, start_row, start_col))
		message("It's not possible to reach the exit 'E' from 'P'.\n", game);
	else
		ft_printf("hay camino\n");
	ft_printf("print map copy\n");
	print_map_copy(game);
	ft_printf("print map\n");
	print_map(game);
}

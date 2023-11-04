/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:46:36 by mcatalan          #+#    #+#             */
/*   Updated: 2023/11/04 18:10:12 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	copy_map_scondary(t_game *game, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < rows)
	{
		(game->map_copy)[i] = (char *)malloc((cols + 1) * sizeof(char));
		if ((game->map_copy)[i] == NULL)
		{
			j = 0;
			while (j < i)
			{
				free((game->map_copy)[j]);
				j++;
			}
			free(game->map_copy);
			game->map_copy = NULL;
			message("Error\nNot possible to copy the map\n", game);
		}
		ft_strcpy((game->map_copy)[i], game->map[i]);
		i++;
	}
	return (0);
}

int	copy_map(t_game *game)
{
	int	rows;
	int	cols;
	int	i;

	i = 0;
	cols = game->size_x / 48;
	rows = game->size_y / 48;
	if (game->map_copy != NULL)
	{
		while (i < rows)
		{
			free(game->map_copy[i]);
			i++;
		}
		free(game->map_copy);
	}
	game->map_copy = (char **)malloc(rows * sizeof(char *));
	if (game->map_copy == NULL)
		return (0);
	copy_map_scondary(game, rows, cols);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:46:36 by mcatalan          #+#    #+#             */
/*   Updated: 2023/11/03 11:53:41 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	copy_map(t_game *game)
{
	int	rows;
	int	cols;
	int	i;
	int	j;

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
	i = 0;
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
	return (1);
}

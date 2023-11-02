/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:29:44 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/11/02 11:39:58 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map_copy(t_game *game)
{
	int	rows;
	int	cols;

	cols = game->size_x / 48;
	rows = game->size_y / 48;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%c", game->map_copy[i][j]);
		}
		printf("\n");
	}
}

void	print_map(t_game *game)
{
	int i = 0;

	while (game->map[i])
	{
		printf("%s\n", game->map[i]);
		i++;
	}
}

t_block	set_block(char name)
{
	t_block	maps[6];
	int		i;

	maps[0] = (t_block){"1", "./img/max.xpm"};
	maps[1] = (t_block){"0", "./img/asphalt.xpm"};
	maps[2] = (t_block){"C", "./img/pirelli_green.xpm"};
	maps[3] = (t_block){"P", "./img/alonso.xpm"};
	maps[4] = (t_block){"E", "./img/33.xpm"};
	maps[5] = (t_block){NULL, NULL};
	i = 0;
	while (maps[i].name != NULL)
	{
		if (maps[i].name[0] == name)
		{
			return (maps[i]);
			break ;
		}
		i++;
	}
	return (maps[5]);
}

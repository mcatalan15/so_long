/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:29:44 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/11/03 11:43:58 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	msg(char *str)
{
	ft_printf("%s", str);
	exit (0);
}

void	message(char *msg, t_game *game)
{
	ft_printf("%s", msg);
	map_destroy(game);
	exit(0);
}

void	print_map_copy(t_game *game)
{
	int	rows;
	int	cols;
	int	i;
	int	j;

	i = 0;
	cols = game->size_x / 48;
	rows = game->size_y / 48;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			printf("%c", game->map_copy[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_map(t_game *game)
{
	int	i;

	i = 0;
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

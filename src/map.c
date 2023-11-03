/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:31:32 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/11/03 11:18:21 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_destroy(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map)
		return (1);
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	return (0);
}

void	create_map(t_game *game, int i)
{
	t_block	map;
	t_image	image;
	int		j;

	image.wlx = *game;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			map = set_block(game->map[i][j]);
			image.relative_path = map.relative_path;
			put_image(image, (j * SIZE), (i * SIZE));
			j++;
		}
		i++;
	}
}

void	create_floor(t_game game, int b)
{
	t_image	image;
	int		j;

	image.wlx = game;
	j = 0;
	if (game.map[(game.size_y / 48)] && game.map[(game.size_y / 48)][0] != '\0')
		message("Incorrect map\n", &game);
	while (game.map[b][j])
	{
		if (!(ft_strchr("1PCE0", game.map[b][j])))
			message("Error\nIncorrect characters\n", &game);
		image.relative_path = "./img/asphalt.xpm";
		put_image(image, (j * SIZE), (b * SIZE));
		j++;
	}
}

void	create_map_length(char *area, t_game *game, int i)
{
	t_image	image;
	int		j;

	image.wlx = *game;
	j = 0;
	game->map[i] = (char *)malloc(sizeof(char) * (9999));
	while (area[j])
	{
		if (area[j] == '\n')
			break ;
		game->map[i][j] = area[j];
		j++;
	}
	game->map[i][j] = '\0';
	create_floor(*game, i);
	create_map(game, i);
}

void	create_map_line(t_game *game, char **argv)
{
	int		fd;
	char	*area;
	int		i;

	game->map = (char **)ft_calloc(sizeof(char *), (9999));
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (i <= game->size_y / 48)
	{
		area = get_next_line(fd);
		if (area == NULL)
			break ;
		create_map_length(area, game, i);
		myfree(area);
		i++;
	}
	game->map[i] = NULL;
	close(fd);
}

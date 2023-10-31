/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:31:32 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/10/31 13:05:02 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_destroy(t_game *game)
{
	int	i;
	int	rows;
	int	cols;

	rows = game->size_y / 48;
	cols = game->size_x / 48;
	i = 0;
	print_map(game);
	ft_printf("\n");
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%c", game->map[i][j]);
		}
		printf("\n");
	}
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
	// if (ft_strlen(game.map[b]) != game.size_x / 48 && b != (game.size_y / 48))
	// 	message("The map is not rectangular\n", &game);
	if (game.map[(game.size_y / 48)] && game.map[(game.size_y / 48)][0] != '\0')
		message("Incorrect map\n", &game);
	while (game.map[b])
	{
		j = 0;
		while (game.map[b][j])
		{
			if (!(ft_strchr("1PCE0", game.map[b][j])))
				message("Error\nIncorrect characters\n", &game);
			image.relative_path = "./img/asphalt.xpm";
			put_image(image, (j * SIZE), (b * SIZE));
			j++;
		}
		b++;
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
	create_floor(*game, i);
	create_map(game, i);
}

void	create_map_line(t_game *game, char **argv)
{
	int		fd;
	char	*area;
	int		i;

	game->map = (char **)malloc(sizeof(char *) * (9999));
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (i <= game->size_y / 48)
	{
		// while ((area = get_next_line(fd)) != NULL)
		// {
		// 	if (area == NULL)
		// 	{
		// 		break ;
		// 	}
		// 	create_map_length(area, game, )
		// }
		area = get_next_line(fd);
		if (area == NULL)
			break ;
		create_map_length(area, game, i);
		myfree(area);
		i++;
	}
	close(fd);
}

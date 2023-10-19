/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:31:32 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/10/19 12:53:10 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long.h"

void	map_destroy(t_game *game)
{
	int	y;

	y = 0;
	while (game->map[y])
	{
		free(game->map[y]);
		y++;
	}
}

void	mount_map(t_game *game, int i)
{
	int		j;
	t_block	map;
	t_img	img;

	img.wlx = *game;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			map = set_block(game->map[i][j]);
			img.relative_path = map.relative_path;
			put_image(img, (j * SIZE), (i * SIZE));
			j++;
		}
		i++;
	}
}

void	create_floor(t_game game, int b)
{
	int		j;
	t_img	image;

	image.wlx = game;
	j = 0;
	if (ft_strlen(game.map[b]) != game.size_x / 48 && b != (game.size_y / 48))
		ft_printf("The map is not rectangular\n");
		// message(RED "The map is not rectangular\n" ENDC, &game);
	if (game.map[(game.size_y / 48)] && game.map[(game.size_y / 48)][0] != '\0')
		ft_printf("Map not valid\n");
		// message(RED "Map not valid\n" ENDC, &game);
	while (game.map[b])
	{
		j = 0;
		while (game.map[b][j])
		{
			if (!(ft_strchr("1PCE0", game.map[b][j])))
				ft_printf("Error\nSome characters left\nCheck map if there is an 0, 1, C, E, P");
				//message(RED "Error\nYabancı eleman sorunu\n" ENDC, &game);
			image.relative_path = "/.../img/floor.xpm";
			put_image(image, (j * SIZE), (b * SIZE));
			j++;
		}
		b++;
	}
}

void	create_map_length(char *area, t_game *game, int i)
{
	int		j;
	t_img	img;

	img.wlx = *game;
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
	mount_map(game, i);
}

void	create_map(t_game *game, char **argv)
{
	int		fd;
	char	*area;
	int		i;

	game->map = (char **)malloc(sizeof(char *) * (9999));
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (i <= game->size_y / 48)
	{
		area = get_next_line(fd);
		if (area == NULL)
			break ;
		create_map_length(area, game, i);
		i++;
	}
	close(fd);
}

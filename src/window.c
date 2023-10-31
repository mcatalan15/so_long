/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:50:33 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/10/31 12:13:17 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	message("Game closed\n", game);
	map_destroy(game);
	exit(0);
}

void	ft_window_size(t_game *data, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		message("Error\nFile not found\n", data);
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		message("Error\nThe file provided does not have .ber extension\n", data);
	data->size_x = (ft_line_length(fd) * 48);
	data->size_y = ft_count_lines(fd) * 48;
}

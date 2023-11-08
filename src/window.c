/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:50:33 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/11/08 13:05:58 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	msg("Game closed\n");
	map_destroy(game);
	exit(0);
}

void	ft_window_size(t_game *game, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		msg("Error\nFile not found\n");
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		msg("Error\nThe file provided does not have .ber extension\n");
	game->size_x = (ft_line_length(fd) * 48);
	game->size_y = (ft_count_lines(fd) * 48);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:50:33 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/10/18 18:30:58 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long.h"

int destroy_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_printf("Game finished\n");
	map_destroy(game);
	exit(0);
}

int ft_line_length(int fd)
{
	char buffer[0];
	int length;
	int bytes;

	buffer[0] = '\0';
	bytes = 1;
	length = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (buffer[0] != '\n')
			length++;
		else
			break;
	}
	return (length);
}

int ft_count_lines(int fd)
{
	int linecount;
	char buffer[0];
	int bytes;

	buffer[0] = '\0';
	linecount = 1;
	while (1)
	{
		bytes = read(fd, buffer, 1);
		if (bytes < 1)
			break;
		if (buffer[0] == '\n')
			linecount++;
	}
	return (linecount);
}

void size_window(t_game *data, char **argv)
{
	int fd;
	
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_printf("File not found\n");
		//messages
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		ft_printf("Your map doesn't have a .ber extension\n");
		//messages
	data->size_x = (ft_line_length(fd) * 48);
	data->size_y = ft_count_lines(fd) * 48;
}
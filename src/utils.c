/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:29:44 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/10/18 18:44:07 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long.h"

void *put_image(t_img img, int x, int y)
{
	img.img = mlx_xpm_file_to_image(img.wlx.mlx,
									  img.relative_path, &img.img_w, &img.img_h);
	mlx_put_image_to_window(img.wlx.mlx, img.wlx.win, img.img, x, y);
	return (img.img);
}

t_block set_block(char name)
{
	t_block maps[6];
	int i;

	maps[0] = (t_block){"1", "./../img/duvar.xpm"};
	maps[1] = (t_block){"0", "./../img/floor.xpm"};
	maps[2] = (t_block){"C", "./../img/s400.xpm"};
	maps[3] = (t_block){"P", "./../img/bayraktarTB2.xpm"};
	maps[4] = (t_block){"E", "./../img/exit.xpm"};
	maps[5] = (t_block){NULL, NULL};
	i = 0;
	while (maps[i].name != NULL)
	{
		if (maps[i].name[0] == name)
		{
			return (maps[i]);
			break;
		}
		i++;
	}
	return (maps[5]);
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

void *myfree(void *str)
{
	free(str);
	return (NULL);
}

char *get_next_line(int fd)
{
	char buffer;
	char *line;
	int rd_byte;
	int i;

	rd_byte = 1;
	i = 0;
	line = (char *)malloc(sizeof(char) * 9999);
	buffer = 0;
	if (fd < 0)
		return (NULL);
	while (rd_byte > 0)
	{
		rd_byte = read(fd, &buffer, 1);
		if (rd_byte <= 0)
			break;
		line[i++] = buffer;
		if (buffer == '\n')
			break;
	}
	line[i] = '\0';
	if (!*line)
		myfree(line);
	return (line);
}
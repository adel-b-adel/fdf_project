/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:03:09 by rfrankly          #+#    #+#             */
/*   Updated: 2019/11/03 17:08:46 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		count_lines(t_map *map)
{
	int		fd;
	int		count;
	char	buf;

	count = 0;
	fd = open(map->map_file_name, O_RDONLY);
	while ((read(fd, &buf, 1)))
	{
		if (buf == '\n')
			count++;
	}
	if (count < 2)
		exit_invalid_map();
	close(fd);
	return (count);
}

void	check_coord_mass_len(char **line_coord, t_map *map)
{
	int i;

	i = -1;
	while (line_coord[++i])
		;
	if (map->first_line_len != i)
		exit_invalid_map();
}

void	ft_read_file(t_map *map)
{
	int y;
	int fd;

	y = 1;
	map->lines_count = count_lines(map);
	if (!(map->coords = (t_point ***)malloc(sizeof(t_point **)\
						* (map->lines_count + 1))))
		exit_with_perror(map->prog_name);
	fd = open(map->map_file_name, O_RDONLY);
	write_first_line_get_len(map, fd);
	while (y < map->lines_count)
	{
		write_other_line(map, fd, y);
		y++;
	}
	close(fd);
}

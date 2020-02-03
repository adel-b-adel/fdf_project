/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 17:09:29 by rfrankly          #+#    #+#             */
/*   Updated: 2019/11/03 18:37:00 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	write_line_loop(char **line_coord, int y, int i, t_map *map)
{
	while (line_coord[i])
	{
		if (!(map->coords[y][i] = (t_point *)malloc(sizeof(t_point))))
			exit_with_perror(map->prog_name);
		if (!check_is_number(line_coord[i]))
		{
			ft_putendl("Not number!!! Invalid map.");
			exit(-1);
		}
		map->coords[y][i]->z = ft_atoi(line_coord[i]);
		map->z_min = map->coords[y][i]->z < map->z_min\
					? map->coords[y][i]->z : map->z_min;
		map->z_max = map->coords[y][i]->z > map->z_max\
					? map->coords[y][i]->z : map->z_max;
		map->coords[y][i]->y = y;
		map->coords[y][i]->x = i;
		map->coords[y][i]->color = read_color(line_coord[i]);
		i++;
	}
}

void		write_first_line_get_len(t_map *map, int fd)
{
	int		i;
	char	*line;
	char	**line_coord;

	i = 0;
	get_next_line(fd, &line);
	line_coord = ft_strsplit(line, ' ');
	map->first_line_len = 0;
	free(line);
	while (line_coord[map->first_line_len])
		map->first_line_len++;
	if (map->first_line_len < 1)
		exit_invalid_map();
	if (!(map->coords[0] = (t_point **)malloc(sizeof(t_point *)\
							* (map->first_line_len + 1))))
		exit_with_perror(map->prog_name);
	write_line_loop(line_coord, 0, i, map);
	free_mass(line_coord);
}

void		write_other_line(t_map *map, int fd, int y)
{
	int		i;
	char	*line;
	char	**line_coord;

	i = 0;
	get_next_line(fd, &line);
	line_coord = ft_strsplit(line, ' ');
	free(line);
	check_coord_mass_len(line_coord, map);
	if (!(map->coords[y] = (t_point **)malloc(sizeof(t_point *)\
							* (map->first_line_len + 1))))
		exit_with_perror(map->prog_name);
	write_line_loop(line_coord, y, i, map);
	free_mass(line_coord);
}

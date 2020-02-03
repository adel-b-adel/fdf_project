/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 17:01:55 by rfrankly          #+#    #+#             */
/*   Updated: 2019/11/03 17:02:30 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void		init_map(t_map *map)
{
	map->angle_x = 0;
	map->angle_y = 0;
	map->angle_z = 0;
	map->offset_x = WIN_WIDTH / 2;
	map->offset_y = WIN_HEIGHT / 2;
	map->scale_z = 1;
	map->scale = WIN_WIDTH / sqrt(map->lines_count * map->lines_count +\
						map->first_line_len * map->first_line_len);
}

void			check_input(int argc, char **argv, t_map *map)
{
	int fd;

	if (argc != 2)
	{
		ft_putendl("usage: ./fdf map_file_name");
		exit(-1);
	}
	else
	{
		fd = open(argv[1], O_RDWR);
		if (fd < 0)
		{
			perror(argv[0]);
			exit(-1);
		}
		map->map_file_name = argv[1];
		close(fd);
	}
	map->z_min = 0;
	map->z_max = 0;
}

int				main(int argc, char **argv)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	check_input(argc, argv, map);
	map->prog_name = argv[0];
	ft_read_file(map);
	init_map(map);
	map->mlx = mlx_init();
	map->window = mlx_new_window(map->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	map->image = mlx_new_image(map->mlx, WIN_WIDTH, WIN_HEIGHT);
	map->pixels = (int *)mlx_get_data_addr(map->image, &map->img_inf[0],\
					&map->img_inf[1], &map->img_inf[2]);
	draw_map(map);
	mlx_hook(map->window, 2, 0, process_key_press, map);
	mlx_hook(map->window, 17, 0, process_exit, map);
	mlx_loop(map->mlx);
	return (0);
}

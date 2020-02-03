/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 17:03:45 by rfrankly          #+#    #+#             */
/*   Updated: 2019/11/03 18:56:01 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void		move_to_start(t_map *map)
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

static int		match_move_key(t_key key, t_map *map)
{
	if (key == UP_OFFSET_Y_MIN)
		map->offset_y -= 10;
	else if (key == DOWN_OFFSET_Y_PLS)
		map->offset_y += 10;
	else if (key == LEFT_OFFSET_X_MIN)
		map->offset_x -= 10;
	else if (key == RIGHT_OFFSET_X_PLS)
		map->offset_x += 10;
	else if (key == NUM_MUL_SCALE_PLS && (map->scale < (WIN_WIDTH /\
	sqrt(map->lines_count * map->lines_count +\
						map->first_line_len * map->first_line_len) * 3)))
		map->scale *= 1.05;
	else if (key == NUM_DIV_SCALE_MIN && (map->scale > (WIN_WIDTH /\
	sqrt(map->lines_count * map->lines_count +\
						map->first_line_len * map->first_line_len) * 0.15)))
		map->scale *= 0.95;
	else
		return (0);
	return (1);
}

static int		match_rotate_key(t_key key, t_map *map)
{
	if (key == NUM_7_ROT_X_MIN)
		map->angle_x -= 5;
	else if (key == NUM_9_ROT_X_PLS)
		map->angle_x += 5;
	else if (key == NUM_4_ROT_Y_MIN)
		map->angle_y -= 5;
	else if (key == NUM_6_ROT_Y_PLS)
		map->angle_y += 5;
	else if (key == NUM_1_ROT_Z_MIN)
		map->angle_z -= 5;
	else if (key == NUM_3_ROT_Z_PLS)
		map->angle_z += 5;
	else if (key == NUM_MINUS_HIGH && map->scale_z < 100)
		map->scale_z += 1;
	else if (key == NUM_PLUS_HIGH && map->scale_z >= 2)
		map->scale_z -= 1;
	else if (key == NULL_START)
		move_to_start(map);
	else
		return (0);
	return (1);
}

int				process_key_press(t_key key, t_map *map)
{
	if (key == 53)
		process_exit(map);
	else if (match_move_key(key, map) || match_rotate_key(key, map))
	{
		draw_map(map);
		return (1);
	}
	return (0);
}

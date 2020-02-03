/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 17:07:18 by rfrankly          #+#    #+#             */
/*   Updated: 2019/11/03 17:07:21 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void			gradient_color(t_draw *t, t_point *src, t_point *dst, int *pix)
{
	while (t->steps > 0)
	{
		if ((int)t->tmp.x >= 0 && (int)t->tmp.x < WIN_WIDTH\
			&& (int)t->tmp.y >= 0 && (int)t->tmp.y < WIN_HEIGHT)
			pix[(int)t->tmp.x + (int)t->tmp.y * WIN_WIDTH] = \
			get_grad_color(*t, src, dst);
		t->tmp.x += t->step_x;
		t->tmp.y += t->step_y;
		t->steps--;
	}
}

void			draw_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < WIN_HEIGHT * WIN_WIDTH)
	{
		map->pixels[i] = 0;
		i++;
	}
	i = 0;
	while (i < map->lines_count)
	{
		j = 0;
		while (j < map->first_line_len)
		{
			if (j < map->first_line_len - 1)
				line_right(map, i, j);
			if (i < map->lines_count - 1)
				line_down(map, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(map->mlx, map->window, map->image, 0, 0);
}

void			draw_line(int *pixels, t_point *src, t_point *dst)
{
	t_draw t;

	t.dist_x = dst->x - src->x;
	t.dist_y = dst->y - src->y;
	if (fabsf(t.dist_x) >= fabsf(t.dist_y))
	{
		t.step_x = t.dist_x >= 0 ? 1 : -1;
		t.step_y = t.dist_y / fabsf(t.dist_x);
		t.steps = abs((int)t.dist_x);
	}
	else
	{
		t.step_y = t.dist_y >= 0 ? 1 : -1;
		t.step_x = t.dist_x / fabsf(t.dist_y);
		t.steps = abs((int)t.dist_y);
	}
	t.tmp = (t_point){src->x, src->y, src->z, src->color};
	gradient_color(&t, src, dst, pixels);
}

void			line_right(t_map *map, int i, int j)
{
	map->src.x = map->coords[i][j]->x - map->first_line_len / 2;
	map->src.y = map->coords[i][j]->y - map->lines_count / 2;
	map->src.z = map->coords[i][j]->z / map->scale_z;
	map->src.color = get_color_with_z(map->coords[i][j]->color\
									, map, map->src.z);
	map->dst.x = map->coords[i][j + 1]->x - map->first_line_len / 2;
	map->dst.y = map->coords[i][j + 1]->y - map->lines_count / 2;
	map->dst.z = map->coords[i][j + 1]->z / map->scale_z;
	map->dst.color = get_color_with_z(map->coords[i][j + 1]->color\
									, map, map->dst.z);
	rotate_point(&map->src, map);
	rotate_point(&map->dst, map);
	map->src.x = map->src.x * map->scale + map->offset_x;
	map->src.y = map->src.y * map->scale + map->offset_y;
	map->dst.x = map->dst.x * map->scale + map->offset_x;
	map->dst.y = map->dst.y * map->scale + map->offset_y;
	draw_line(map->pixels, &map->src, &map->dst);
}

void			line_down(t_map *map, int i, int j)
{
	map->src.x = map->coords[i][j]->x - map->first_line_len / 2;
	map->src.y = map->coords[i][j]->y - map->lines_count / 2;
	map->src.z = map->coords[i][j]->z / map->scale_z;
	map->src.color = get_color_with_z(map->coords[i][j]->color\
									, map, map->src.z);
	map->dst.x = map->coords[i + 1][j]->x - map->first_line_len / 2;
	map->dst.y = map->coords[i + 1][j]->y - map->lines_count / 2;
	map->dst.z = map->coords[i + 1][j]->z / map->scale_z;
	map->dst.color = get_color_with_z(map->coords[i + 1][j]->color\
									, map, map->dst.z);
	rotate_point(&map->src, map);
	rotate_point(&map->dst, map);
	map->src.x = map->src.x * map->scale + map->offset_x;
	map->src.y = map->src.y * map->scale + map->offset_y;
	map->dst.x = map->dst.x * map->scale + map->offset_x;
	map->dst.y = map->dst.y * map->scale + map->offset_y;
	draw_line(map->pixels, &map->src, &map->dst);
}

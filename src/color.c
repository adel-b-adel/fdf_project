/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 21:41:04 by rfrankly          #+#    #+#             */
/*   Updated: 2019/11/03 17:06:46 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static double	get_percent(int z_min, int z_max, int z)
{
	double place;
	double dist;
	double ret;

	ret = 1.0;
	place = z - z_min;
	dist = z_max - z_min;
	if (dist != 0)
		ret = place / dist;
	return (ret);
}

int				get_color_with_z(int color, t_map *map, float z)
{
	double percent;

	if (color != -1)
		return (color);
	percent = get_percent(map->z_min, map->z_max, z);
	if (percent < 0.2)
		return (COLOR_VLB);
	else if (percent < 0.4)
		return (COLOR_VLV);
	else if (percent < 0.6)
		return (COLOR_VLO);
	else if (percent < 0.8)
		return (COLOR_VLG);
	else
		return (COLOR_VLY);
}

static int		change_color(int src, int dst, float percent)
{
	int ret;

	ret = (1 - percent) * src + percent * dst;
	return (ret);
}

int				get_grad_color(t_draw t, t_point *src, t_point *dst)
{
	int		red;
	int		green;
	int		blue;
	double	percent;

	if (t.tmp.color == dst->color)
		return (t.tmp.color);
	if (t.dist_x > t.dist_y)
		percent = get_percent(src->x, dst->x, t.tmp.x);
	else
		percent = get_percent(src->y, dst->y, t.tmp.y);
	red = change_color((src->color >> 16) & 0xFF,\
				(dst->color >> 16) & 0xFF, percent);
	green = change_color((src->color >> 8) & 0xFF,\
				(dst->color >> 8) & 0xFF, percent);
	blue = change_color(src->color & 0xFF, dst->color & 0xFF, percent);
	return ((red << 16) | (green << 8) | blue);
}

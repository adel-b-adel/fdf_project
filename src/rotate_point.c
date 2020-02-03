/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 20:45:50 by rfrankly          #+#    #+#             */
/*   Updated: 2019/10/10 19:52:23 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static float g_rad_in_degree = 2 * M_PI / 360;

void	rotate_x(t_point *point, int angle)
{
	float	radian;
	float	cos;
	float	sin;
	float	y;
	float	z;

	y = point->y;
	z = point->z;
	radian = g_rad_in_degree * angle;
	cos = cosf(radian);
	sin = sinf(radian);
	point->y = y * cos - z * sin;
	point->z = y * sin + z * cos;
}

void	rotate_y(t_point *point, int angle)
{
	float	radian;
	float	cos;
	float	sin;
	float	x;
	float	z;

	x = point->x;
	z = point->z;
	radian = g_rad_in_degree * angle;
	cos = cosf(radian);
	sin = sinf(radian);
	point->x = x * cos + z * sin;
	point->z = -x * sin + z * cos;
}

void	rotate_z(t_point *point, int angle)
{
	float	radian;
	float	cos;
	float	sin;
	float	x;
	float	y;

	x = point->x;
	y = point->y;
	radian = g_rad_in_degree * angle;
	cos = cosf(radian);
	sin = sinf(radian);
	point->x = x * cos - y * sin;
	point->y = x * sin + y * cos;
}

void	rotate_point(t_point *point, t_map *map)
{
	if (map->angle_x != 0)
		rotate_x(point, map->angle_x);
	if (map->angle_y != 0)
		rotate_y(point, map->angle_y);
	if (map->angle_z != 0)
		rotate_z(point, map->angle_z);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 17:01:14 by rfrankly          #+#    #+#             */
/*   Updated: 2019/11/03 18:46:28 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define WIN_WIDTH 1400
# define WIN_HEIGHT 1200

typedef enum	e_key
{
	UP_OFFSET_Y_MIN = 126,
	DOWN_OFFSET_Y_PLS = 125,
	LEFT_OFFSET_X_MIN = 123,
	RIGHT_OFFSET_X_PLS = 124,
	NUM_MUL_SCALE_PLS = 67,
	NUM_DIV_SCALE_MIN = 75,
	NUM_7_ROT_X_MIN = 89,
	NUM_9_ROT_X_PLS = 92,
	NUM_4_ROT_Y_MIN = 86,
	NUM_6_ROT_Y_PLS = 88,
	NUM_1_ROT_Z_MIN = 83,
	NUM_3_ROT_Z_PLS = 85,
	NUM_PLUS_HIGH = 69,
	NUM_MINUS_HIGH = 78,
	NULL_START = 82
}				t_key;

typedef enum	e_color
{
	COLOR_VLB = 0x99FFEE,
	COLOR_VLV = 0xBF80FF,
	COLOR_VLO = 0x00E7FB,
	COLOR_VLG = 0x9999FF,
	COLOR_VLY = 0xFF99FF
}				t_color;

typedef struct	s_point
{
	float		x;
	float		y;
	float		z;
	int			color;
}				t_point;

typedef struct	s_draw
{
	float		dist_x;
	float		dist_y;
	float		step_x;
	float		step_y;
	float		steps;
	t_point		tmp;
}				t_draw;

typedef struct	s_map
{
	void		*mlx;
	void		*window;
	void		*image;
	float		scale;
	int			img_inf[3];
	int			offset_x;
	int			offset_y;
	int			scale_z;
	int			angle_x;
	int			angle_y;
	int			angle_z;
	int			lines_count;
	int			first_line_len;
	int			*pixels;
	int			z_min;
	int			z_max;
	char		*prog_name;
	char		*map_file_name;
	t_point		src;
	t_point		dst;
	t_point		***coords;
}				t_map;

/*
**	main.c
*/

void			check_input(int argc, char **argv, t_map *map);

/*
**	read_file.c
*/

int				count_lines(t_map *map);
void			check_coord_mass_len(char **line_coord, t_map *map);
void			ft_read_file(t_map *map);

/*
**	write_line.c
*/

void			write_first_line_get_len(t_map *map, int fd);
void			write_other_line(t_map *map, int fd, int y);

/*
**	rotate_point.c
*/

void			rotate_point(t_point *point, t_map *map);
void			rotate_z(t_point *point, int angle);
void			rotate_y(t_point *point, int angle);
void			rotate_x(t_point *point, int angle);

/*
**	exits.c
*/

int				process_exit();
void			exit_invalid_map(void);
void			exit_with_perror(char *name);
void			free_mass(char **mass);
void			free_map(t_map *map);

/*
**	color.c
*/

int				get_color_with_z(int color, t_map *map, float z);
int				get_grad_color(t_draw t, t_point *src, t_point *dst);

/*
**	draw.c
*/

void			draw_line(int *pixels, t_point *src, t_point *dst);
void			line_right(t_map *map, int i, int j);
void			line_down(t_map *map, int i, int j);
void			draw_map(t_map *map);

/*
**	read_color_from_file
*/

int				read_color(char *s);

/*
**	key_press.c
*/

int				process_key_press(t_key key, t_map *map);

/*
**	is_number.c
*/

int				check_is_number(char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 21:21:16 by rfrankly          #+#    #+#             */
/*   Updated: 2019/11/03 18:37:33 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		process_exit(void)
{
	exit(0);
	return (0);
}

void	exit_invalid_map(void)
{
	ft_putstr("Invalid map!\n");
	exit(-1);
}

void	exit_with_perror(char *name)
{
	perror(name);
	exit(-2);
}

void	free_mass(char **mass)
{
	int i;

	i = 0;
	while (mass[i] != NULL)
	{
		free(mass[i]);
		i++;
	}
	free(mass);
}

void	free_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i++ < map->lines_count + 1)
	{
		j = 0;
		while (j++ < map->first_line_len + 1)
			free(map->coords[i][j]);
		free(map->coords[i]);
	}
	free(map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 18:27:42 by rfrankly          #+#    #+#             */
/*   Updated: 2019/11/03 19:02:00 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	check_is_number(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit((int)str[i]) && !(i > 0 && str[i] == ','))
			return (0);
		if (!ft_isdigit((int)str[i]) && (i > 0 && str[i] == ','))
			return (1);
		i++;
	}
	return (1);
}

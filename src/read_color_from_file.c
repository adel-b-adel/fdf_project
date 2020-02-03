/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_color_from_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 17:07:53 by rfrankly          #+#    #+#             */
/*   Updated: 2019/11/03 17:07:56 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int		check_base(char c)
{
	char	*s1;
	int		i;

	i = 0;
	s1 = "0123456789ABCDEF";
	while (c != s1[i] && s1[i])
		i++;
	return (i);
}

int				atoi_hex_min(const char *str)
{
	int		i;
	long	numb;

	i = 0;
	numb = 0;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n' ||\
			str[i] == '\v' || str[i] == '\r' || str[i] == '\f' ||\
			str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '0' && str[i + 1] == 'x')
		i = i + 2;
	while (((str[i] >= '0' && str[i] <= '9') ||\
		(str[i] >= 'A' && str[i] <= 'F')) && numb >= 0)
	{
		numb = numb * 16 + check_base(str[i]);
		i++;
	}
	return ((int)numb);
}

int				read_color(char *s)
{
	char	**tmp;
	int		i;
	int		ret;

	i = 0;
	tmp = NULL;
	ret = -1;
	tmp = ft_strsplit(s, ',');
	if (tmp)
	{
		if (tmp[i] && tmp[i + 1])
			ret = atoi_hex_min(tmp[i + 1]);
		if (!ret)
			ret = -1;
		free_mass(tmp);
	}
	return (ret);
}

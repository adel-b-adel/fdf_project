/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 18:03:51 by rfrankly          #+#    #+#             */
/*   Updated: 2019/01/08 15:43:07 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

int			ft_atoi(const char *str)
{
	int		i;
	long	numb;
	int		sign;

	i = 0;
	numb = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n' ||
	str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = is_sign(str[i]);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && numb >= 0)
	{
		numb = numb * 10 + (str[i] - '0');
		i++;
	}
	if (numb < 0 && sign < 0)
		return (0);
	if (numb < 0 && sign > 0)
		return (-1);
	return ((int)numb * sign);
}

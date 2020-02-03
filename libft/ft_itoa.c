/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 20:56:35 by rfrankly          #+#    #+#             */
/*   Updated: 2019/01/02 14:47:09 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	f_rec(char *str, int n, int i, int sign)
{
	if (sign)
		*str = '-';
	if (n < 0)
	{
		while (i > 0)
		{
			str[i + sign - 1] = -(n % 10) + '0';
			n = n / 10;
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			str[i + sign - 1] = n % 10 + '0';
			n = n / 10;
			i--;
		}
	}
}

char		*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		i;
	int		n_new;

	sign = 0;
	i = 1;
	n_new = n;
	if (n < 0)
		sign = 1;
	while (n_new / 10 != 0)
	{
		n_new /= 10;
		i++;
	}
	if (!(str = ft_strnew(i + sign)))
		return (NULL);
	f_rec(str, n, i, sign);
	return (str);
}

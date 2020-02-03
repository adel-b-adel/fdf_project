/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:22:14 by rfrankly          #+#    #+#             */
/*   Updated: 2019/01/21 11:29:15 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t max;
	size_t d;
	size_t i;
	size_t j;

	d = ft_strlen(dest);
	i = 0;
	j = d;
	if (size < d + 1)
		return (size + ft_strlen(src));
	if (size > d + 1)
	{
		max = size - d - 1;
		while (max != 0 && src[i] != '\0')
		{
			dest[j] = src[i];
			j++;
			i++;
			max--;
		}
		dest[j] = '\0';
	}
	return (ft_strlen(src) + d);
}

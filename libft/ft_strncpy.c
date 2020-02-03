/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:42:18 by rfrankly          #+#    #+#             */
/*   Updated: 2018/12/10 15:14:05 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while ((len != 0) && (src[j] != '\0'))
	{
		dst[i] = src[j];
		j++;
		i++;
		len--;
	}
	while (len != 0)
	{
		dst[i] = '\0';
		len--;
		i++;
	}
	return (dst);
}

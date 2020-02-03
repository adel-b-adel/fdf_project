/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:55:48 by rfrankly          #+#    #+#             */
/*   Updated: 2019/01/14 17:34:28 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t len;
	size_t i;

	i = 0;
	len = ft_strlen(dest);
	while (n != 0)
	{
		if (src[i])
		{
			dest[len] = src[i];
			len++;
			n--;
			i++;
		}
		else
			break ;
	}
	dest[len] = '\0';
	return (dest);
}

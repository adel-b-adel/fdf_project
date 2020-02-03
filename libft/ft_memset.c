/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:10:55 by rfrankly          #+#    #+#             */
/*   Updated: 2018/12/27 15:23:46 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	cc;
	char			*s;
	size_t			i;

	s = b;
	cc = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		s[i] = cc;
		i++;
	}
	return (b);
}

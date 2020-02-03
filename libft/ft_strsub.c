/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 17:02:45 by rfrankly          #+#    #+#             */
/*   Updated: 2019/01/01 17:15:47 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	int		i;

	i = 0;
	if (s == NULL || (!(subs = ft_strnew(len))))
		return (NULL);
	while (len != 0)
	{
		subs[i++] = s[start++];
		len--;
	}
	return (subs);
}

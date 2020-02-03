/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:53:52 by rfrankly          #+#    #+#             */
/*   Updated: 2018/12/28 17:06:24 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	findj(const char *haystack, const char *needle, int k, int maxk)
{
	int j;

	j = 0;
	while (needle[j] != '\0' && k < maxk)
	{
		if (haystack[k] == needle[j])
		{
			k++;
			j++;
		}
		else
			break ;
	}
	return (j);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while (haystack[i] != '\0' && i < (int)len)
	{
		if (haystack[i] == needle[0])
		{
			if (needle[findj(haystack, needle, i, (int)len)] == '\0')
				return ((char*)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

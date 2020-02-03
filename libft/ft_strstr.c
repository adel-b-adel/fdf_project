/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 17:41:10 by rfrankly          #+#    #+#             */
/*   Updated: 2018/12/28 16:46:45 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_j(const char *haystack, const char *needle, int k)
{
	int j;

	j = 0;
	while (needle[j] != '\0')
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

char		*ft_strstr(const char *haystack, const char *needle)
{
	int i;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			if (needle[find_j(haystack, needle, i)] == '\0')
				return ((char*)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

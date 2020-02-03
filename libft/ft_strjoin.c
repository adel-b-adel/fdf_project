/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 17:25:54 by rfrankly          #+#    #+#             */
/*   Updated: 2019/01/01 17:34:29 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *new_s;

	if (s1 == NULL || s2 == NULL ||
		(!(new_s = ft_strnew(ft_strlen(s1) + ft_strlen(s2)))))
		return (NULL);
	ft_strcat(new_s, s1);
	ft_strcat(new_s, s2);
	return (new_s);
}

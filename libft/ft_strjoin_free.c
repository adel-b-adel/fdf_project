/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 12:17:20 by rfrankly          #+#    #+#             */
/*   Updated: 2019/01/21 12:48:48 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char *new_s;

	if (s1 == NULL || s2 == NULL ||
		(!(new_s = ft_strnew(ft_strlen(s1) + ft_strlen(s2)))))
		return (NULL);
	ft_strcat(new_s, s1);
	ft_strcat(new_s, s2);
	free(s1);
	s1 = NULL;
	free(s2);
	s2 = NULL;
	return (new_s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 15:48:32 by rfrankly          #+#    #+#             */
/*   Updated: 2019/01/01 16:17:05 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *str;
	char *str_ret;

	if (s == NULL || f == NULL || (!(str = ft_strnew(ft_strlen(s)))))
		return (NULL);
	str_ret = str;
	while (*s)
	{
		*str = f(*s);
		str++;
		s++;
	}
	return (str_ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:41:59 by rfrankly          #+#    #+#             */
/*   Updated: 2018/12/10 15:13:18 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	int i;

	i = 0;
	while (n != 0 && (str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] == str2[i])
		{
			i++;
			n--;
		}
		else
			return (((unsigned char)str1[i]) - ((unsigned char)str2[i]));
	}
	return (0);
}

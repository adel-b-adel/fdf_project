/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 16:11:24 by rfrankly          #+#    #+#             */
/*   Updated: 2018/12/30 17:10:23 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *mass;
	void *ret;

	if (!(mass = (char *)malloc(size)))
		return (NULL);
	ret = mass;
	while (size)
	{
		*mass = '\0';
		mass++;
		size--;
	}
	return (ret);
}

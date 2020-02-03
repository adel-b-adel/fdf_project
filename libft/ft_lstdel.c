/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:14:13 by rfrankly          #+#    #+#             */
/*   Updated: 2019/01/04 16:34:49 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *n_copy;

	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	while (*alst)
	{
		n_copy = (*alst)->next;
		ft_lstdelone(alst, del);
		(*alst) = n_copy;
	}
}

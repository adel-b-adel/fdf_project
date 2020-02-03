/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 17:13:43 by rfrankly          #+#    #+#             */
/*   Updated: 2019/01/21 12:10:59 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *ret;
	t_list *tmp;

	if (!lst || !f || !(new = (*f)(lst)))
		return (NULL);
	ret = new;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if (!(new->next = (*f)(lst)))
		{
			while (ret)
			{
				tmp = ret->next;
				free(ret->content);
				free(ret);
				ret = tmp;
			}
			return (NULL);
		}
		new = new->next;
	}
	new->next = NULL;
	return (ret);
}

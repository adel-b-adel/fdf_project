/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 15:02:28 by rfrankly          #+#    #+#             */
/*   Updated: 2019/01/02 17:06:31 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_numb(char const *s, char c)
{
	int k;

	k = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
			k++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (k);
}

static int	str_len(char const *word_s, char c)
{
	int k;

	k = 0;
	while (*word_s != c && *word_s != '\0')
	{
		k++;
		word_s++;
	}
	return (k);
}

static void	rec_word(char const **s, char *str, char c)
{
	while (**s != c && **s != '\0')
	{
		*str = **s;
		str++;
		(*s)++;
	}
}

static char	**clean(char **ret, int i)
{
	i--;
	while (i >= 0)
	{
		free(ret[i]);
		i--;
	}
	free(ret);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (!(ret = (char **)malloc((word_numb(s, c) + 1) * sizeof(char *))))
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		if (!(ret[i] = ft_strnew(str_len(s, c))))
			return (clean(ret, i));
		rec_word(&s, ret[i], c);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 20:43:23 by rfrankly          #+#    #+#             */
/*   Updated: 2019/09/29 19:23:28 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		checker(const int fd, char **line)
{
	if (fd < 0 || fd > 5000 || BUFF_SIZE <= 0 || !line)
		return (1);
	*line = NULL;
	return (0);
}

int		check_buf(char *buf)
{
	while (*buf != '\0')
	{
		if (*buf == '\n')
			return (1);
		buf++;
	}
	return (0);
}

int		read_and_record(const int fd, char **str)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*c;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		c = *str;
		*str = ft_strjoin(*str, buf);
		free(c);
		if (check_buf(buf))
			return (ret);
	}
	return (ret);
}

void	record_only(char **str, char **line)
{
	char	*c;
	int		i;
	int		len;

	i = 0;
	c = *str;
	if ((len = ft_strlen(*str)) > 0)
	{
		while (c[i] != '\0')
		{
			if (c[i] == '\n')
				break ;
			i++;
		}
		*line = ft_strsub(c, 0, i);
		if (c[i] == '\n')
		{
			*str = ft_strsub(*str, i + 1, len - 1 - i);
			free(c);
			return ;
		}
		free(*str);
		*str = ft_strnew(0);
	}
}

int		get_next_line(const int fd, char **line)
{
	static char	*end[5000];
	char		*str;
	int			ret;

	if (checker(fd, line))
		return (-1);
	str = end[fd];
	if (str == NULL)
		str = ft_strnew(0);
	if (!check_buf(str))
		ret = read_and_record(fd, &str);
	record_only(&str, line);
	end[fd] = str;
	if (*line)
		return (1);
	if (ret == -1)
		return (-1);
	*line = ft_strnew(0);
	return (0);
}

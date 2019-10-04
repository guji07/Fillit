/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:39:55 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/09/21 14:39:56 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		ft_vl(char *arr)
{
	int		i;

	i = 0;
	while (arr[i] && arr[i] != '\n')
		i++;
	return (i);
}

int				get_next_line(const int fd, char **line)
{
	static	char	*a[256];
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int				n;

	if (fd < 0 || !line || (read(fd, buf, 0) < 0))
		return (-1);
	if (!a[fd])
		a[fd] = ft_strnew(0);
	while ((n = read(fd, buf, BUFF_SIZE)))
	{
		buf[n] = '\0';
		tmp = ft_strjoin(a[fd], buf);
		free(a[fd]);
		a[fd] = tmp;
		if (ft_strchr(a[fd], '\n'))
			break ;
	}
	if (!n && *a[fd] == '\0')
		return (0);
	*line = ft_strsub(a[fd], 0, ft_vl(a[fd]));
	n = ft_strlen(a[fd] + ft_vl(a[fd]) + 1);
	(ft_strlen(*line) < ft_strlen(a[fd])) ?
	ft_memmove(a[fd], a[fd] + ft_vl(a[fd]) + 1, n + 1) : ft_strdel(&a[fd]);
	return (1);
}

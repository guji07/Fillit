/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:06:50 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/20 14:31:27 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*get_file(t_list **start, int fd)
{
	t_list *tmp;

	tmp = *start;
	while (tmp)
	{
		if (tmp->content_size == (size_t)fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(start, tmp);
	return (tmp);
}

static int		end(const char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*fb;
	int				ret;
	char			buf[BUFF_SIZE + 1];
	t_list			*tmp;

	CHECKRETURN((fd < 0 || line == NULL || read(fd, buf, 0) < 0), -1);
	tmp = get_file(&fb, fd);
	if (!tmp->content)
		CHECKRETURN(!(tmp->content = ft_strnew(0)), -1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		ft_swapfree(&tmp->content, ft_strjoin(tmp->content, buf));
		CHECKRETURN(!tmp->content, -1);
		if (ft_strchr(tmp->content, '\n'))
			break ;
	}
	CHECKRETURN(!*(char *)(tmp->content) && ret < BUFF_SIZE, 0);
	CHECKRETURN(!(*line = ft_strsub(tmp->content, 0, end(tmp->content))), -1);
	if (ft_strlen(*line) < ft_strlen(tmp->content))
		ft_swapfree(&tmp->content,
			ft_strdup(tmp->content + end(tmp->content) + 1));
	else
		ft_memdel(&tmp->content);
	return (1);
}

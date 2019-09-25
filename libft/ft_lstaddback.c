/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:53:39 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/09 22:59:38 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list **alst, t_list *new)
{
	t_list *buf;
	t_list *list;

	list = *alst;
	buf = *alst;
	while (buf->next)
		buf = buf->next;
	buf->next = new;
	*alst = list;
}

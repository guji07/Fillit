/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfreeone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 01:42:19 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/29 17:44:32 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfreeone(t_list *lst)
{
	ft_memdel(&lst->content);
	lst->content = ft_strdup(lst->next->content);
	lst->content_size = lst->next->content_size;
	ft_memdel(&lst->next->content);
	lst->next->next = lst->next;
	free(lst);
}

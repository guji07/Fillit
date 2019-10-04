/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 12:06:04 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/09/21 13:09:48 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_GET_NEXT_LINE_H
# define GET_NEXT_LINE_GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>

int		get_next_line(const int fd, char **line);

#endif

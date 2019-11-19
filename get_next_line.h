/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:55:50 by bclerc            #+#    #+#             */
/*   Updated: 2019/11/19 14:48:24 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int     get_next_line(const int fd, char **line);
void    *ft_memmove(void *dest, const void *src, size_t n);

#endif

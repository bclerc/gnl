/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 10:16:46 by bclerc            #+#    #+#             */
/*   Updated: 2019/01/04 13:13:32 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		readline(char **save, const int fd)
{
	char	buff[BUFF_SIZE + 1];
	char	*pt;
	int		ret;

	ret = read(fd, buff, BUFF_SIZE);
	buff[ret] = 0;
	pt = *save;
	*save = ft_strjoin(*save, buff);
	ft_strdel(&pt);
	return (ret);
}

int		setline(char *pos, char **line, char **save)
{
	*pos = '\0';
	*line = ft_strdup(*save);
	*save = ft_memmove(save, pos + 1, ft_strlen(pos + 1) + 1);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char static	*save;
	char		*pos;
	int			ret;

	if (fd < 0 || BUFF_SIZE < 1 || !line || (read(fd, NULL, 0) < 0))
		return (-1);
	save = save ? save : ft_strnew(0);
	ret = 42;
	while (ret > 0)
	{
		if ((pos = ft_strchr(save, '\n')))
		{
			return (setline(pos, line, &save));
		}
		ret = readline(&save, fd);
	}
	if (!ret && ft_strlen(save))
	{
		*line = ft_strdup(save);
		ft_strclr(save);
		ft_strdel(&save);
		return (1);
	}
	return (0);
}

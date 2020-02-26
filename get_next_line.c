/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 10:16:46 by bclerc            #+#    #+#             */
/*   Updated: 2020/02/26 09:12:03 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strdel(char **as)
{
	int				i;

	if (*as)
	{
		i = 0;
		while (i < ft_strlen(*as))
		{
			*as[i] = 0;
			i++;
		}
	}
	if (!as)
		return ;
	free(*as);
	*as = NULL;
}

int		readline(char **save, const int fd)
{
	char	buff[BUFFER_SIZE + 1];
	char	*pt;
	int		ret;

	ret = read(fd, buff, BUFFER_SIZE);
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
	ft_memmove(*save, pos + 1, ft_strlen(pos + 1) + 1);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char static	*save;
	char		*pos;
	int			ret;

	if (fd < 0 || BUFFER_SIZE < 1 || !line || (read(fd, NULL, 0) < 0))
		return (-1);
	save = save ? save : ft_strdup("");
	ret = 42;
	while (ret > 0)
	{
		if ((pos = ft_strchr(save, '\n')))
			return (setline(pos, line, &save));
		ret = readline(&save, fd);
	}
	if (!ret && ft_strlen(save))
	{
		*line = ft_strdup(save);
		ft_strdel(&save);
		return (0);
	}
	*line = ft_strdup("");
	return (ret);
}

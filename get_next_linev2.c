/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_linev2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 14:56:19 by bclerc            #+#    #+#             */
/*   Updated: 2018/12/31 15:31:47 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*set_line(char **line, char *save)
{
	int		i;
	char	*tmp;

	i = 0;
	while (save[i] != '\n' && save[i])
		i++;
	if (!(*line = ft_strndup(save, i)))
		return (NULL);
	if (i < (int)ft_strlen(save))
	{
		if (!(tmp = ft_strdup(&save[i + 1])))
		{
			free(save);
			return (NULL);
		}
		free(save);
		return (tmp);
	}
	else
	{
		save = NULL;
		return (NULL);
	}
}

int	g_read(char *buff, int fd, char **line, t_gnl gnl)
{

	while ((gnl.ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[gnl.ret] = '\0';
		if (!gnl.save)
		{
			if (!(gnl.save = ft_strnew(0)))
				return(-1);
		}
		if (!(gnl.save = ft_strjoinfree(gnl.save, buff)))
		{
			free(gnl.save);
			return (-1);
		}
		if (!ft_strchr(buff, '\n'))
			continue ;
		if (!(gnl.save = set_line(line, gnl.save)))
			free(gnl.save);
		break;
	}
	return (1);
}

int get_next_line(const int fd, char **line)
{
	char 		buff[BUFF_SIZE + 1];
	t_gnl gnl;

	if(fd < 0 || BUFF_SIZE < 1 || !line )
		return (-1);
	if ((gnl.line_ret = g_read(buff, fd, line, gnl)) == -1)
		return (-1);
	if (gnl.ret && gnl.save)
		return (1);
	if (gnl.ret == 0 && gnl.save)
	{
		gnl.save = set_line(line, gnl.save);
		return (1);
	}
	else if (gnl.ret == 0)
	{
		free(gnl.save);
		*line = NULL;
		return (0);
	}
	return (1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 10:16:46 by bclerc            #+#    #+#             */
/*   Updated: 2019/01/02 15:20:41 by bclerc           ###   ########.fr       */
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
	if (i < (int)ft_strlen(save) && save[i + 1] != 0)
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

int		checker(int ret, char **save, char **line)
{
	if (ret == 0 && *save)
	{
		*save = set_line(line, *save);
		return (1);
	}
	else if (ret == 0)
	{
		free(*save);
		*line = NULL;
		return (0);
	}
	if (ret > 0 && *save)
		return (1);
	if (ret < 0)
		return (-1);

	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	char static	*save;
	int			ret;

	if (fd < 0 || BUFF_SIZE < 1 || !line || (read(fd, buff, 0) < 0))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (!save && !(save = ft_strnew(0)))
			return (-1);
		if (!(save = ft_strjoinfree(save, buff)))
		{
			free(save);
			return (-1);
		}
		if (!ft_strchr(buff, '\n'))
			continue ;
		if (!(save = set_line(line, save)))
			free(save);
		break ;
	}
	return (checker(ret, &save, line));
}

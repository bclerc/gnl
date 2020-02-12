/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 10:16:46 by bclerc            #+#    #+#             */
/*   Updated: 2020/02/12 16:31:49 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	int				i;
	unsigned char	*tmp;

	i = 0;
	tmp = s;
	while (i < (int)n)
	{
		tmp[i] = 0;
		i++;
	}
}

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

static int	readline(const int fd, char **buffer)
{
	char	tmp[BUFFER_SIZE + 1];
	char	*old_tmp;
	int		ret;

	if ((ret = read(fd, tmp, BUFFER_SIZE)) == -1)
		return (-1);
	tmp[ret] = '\0';
	old_tmp = *buffer;
	*buffer = ft_strjoin(*buffer, tmp);
	ft_strdel(&old_tmp);
	return (ret);
}

int			clean_buffer(char **buffer,char *line)
{
	line = ft_strdup(*buffer);
	ft_strdel(buffer);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char		*buffer = 0;
	char			*end;
	int				ret;

	if (!line || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	buffer = buffer == 0 ? ft_strdup("") : buffer;
	ret = 1;
	while (ret > 0)
	{
		if ((end = ft_strchr(buffer, '\n')))
		{
			*end = '\0';
			*line = ft_strdup(buffer);
			ft_memmove(buffer, end + 1, ft_strlen(end + 1) + 1);
			return (0);
		}
		ret = readline(fd, &buffer);
	}
	if (ret == 0 && ft_strlen(buffer))
		return (clean_buffer(&buffer, *line));
	(*line) = ft_strdup("");
	return (ret);
}
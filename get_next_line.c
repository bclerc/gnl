/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:54:17 by bclerc            #+#    #+#             */
/*   Updated: 2018/12/12 16:11:37 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char   *set_line(char **line, char *save)
{
    int i;

    i = 0;
    while (save[i] != '\n' && save[i])
        i++;
    *line = ft_strndup(save, i);
    if (save[i + 1])
        return  (ft_strdup(&save[i + 1]));
    else
    {
        save = NULL;
        return (NULL);
    }
}

int get_next_line(const int fd, char **line)
{
    char buff[BUFF_SIZE + 1];
    char static *save;
    int ret;

    ret = 0;
    if(fd < 0)
        return (-1);
    while((ret = read(fd, buff, BUFF_SIZE)) > 0)
    {
         buff[ret] = '\0';
        if  (!save)
        {
            if (!(save = ft_strnew(ft_strlen(buff))))
                return (-1);
        }
        if (!(save = ft_strjoin(save, buff)))
            {
                free(save);
                return (-1);
            }
        if (!ft_strchr(buff, '\n'))
            continue ;
       if (!(save = set_line(line, save)))
                free(save);
        break;
    }
    if (ret && save)
        return (1);
    if (ret == 0 && save)
    {
        save = set_line(line, save);
        return (1);
    }
    else if (ret == 0)
    {
        free(save);
        *line = NULL;
        return (0);
    }
    return (1);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 10:16:46 by bclerc            #+#    #+#             */
/*   Updated: 2018/12/26 10:41:30 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char   *set_line(char **line, char *save)
{
    int i;
    char *tmp;

    i = 0;
    while (save[i] != '\n' && save[i])
        i++;
    *line = ft_strndup(save, i);
    if (i < (int)ft_strlen(save))
    {
        if (!(tmp = ft_strdup(&save[i + 1])))
        {
            free(save);
            return  (NULL);
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

int get_next_line(const int fd, char **line)
{
    char buff[BUFF_SIZE + 1];
    char static *save;
    int ret;

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
        if (!(save = ft_strjoinfree(save, buff)))
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


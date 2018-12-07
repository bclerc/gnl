/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:54:17 by bclerc            #+#    #+#             */
/*   Updated: 2018/12/07 13:39:57 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char   *set_line(char **line, char *save)
{
    int i;
    int b;
    char *tmp;
    i = 0;
    while (save[i] != '\n' && save[i])
        i++;
    *line = ft_strndup(save, i);
    return(ft_strdup(&save[i + 1]));
}

int get_next_line(const int fd, char **line)
{
    char buff[BUFF_SIZE + 1];
    char static *save;
    char *tmp;
    int ret;
    int last;

    ret = 0;
    last = 0;
    while((ret = read(fd, buff, BUFF_SIZE)))
    {
        buff[ret] = 0;
        if(!save)
        save = ft_strnew(ft_strlen(buff));
        save = ft_strjoin(save, buff);
        if (!ft_strchr(buff, '\n'))
        {
            continue ;
        }
        save = set_line(line, save);
        break;
    }
    return (0);
}

int main(void)
{
    int fd;
    char *tab;
    int i;
    char **pt;
    tab = "";
    pt = &tab;
    fd = open("test", O_RDONLY);
    i = 0;
    while (i < 10)
    {
    get_next_line(fd, pt);
    printf("Ligne : %s \n", *pt);
    i++;
    }
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:55:50 by bclerc            #+#    #+#             */
/*   Updated: 2020/01/30 04:49:05 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		ft_strlen(char *str);
char	*ft_strcat(char *dest, const char *src);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strnew(size_t size);
char	*ft_strdup(const char *s);
char	*ft_strcat(char *dest, const char *src);
void	ft_strdel(char **as);
char	*ft_strjoin(char const *s1, char const *s2);

#endif

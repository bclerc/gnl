/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:34:00 by bclerc            #+#    #+#             */
/*   Updated: 2019/11/19 14:45:32 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     ft_strlen(char *str)
{
    size_t i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char*)s;
	while (tmp[i])
	{
		if (tmp[i] == c)
			return (&tmp[i]);
		i++;
	}
	if (!tmp[i] && !c)
		return (&tmp[i]);
	return (0);
}


char	*ft_strdup(const char *s)
{
	char	*tmp;
	char	*tab;
	int		i;

	if ((tab = (char*)malloc((ft_strlen((char*)s) + 1) * sizeof(char))) == NULL)
		return (0);
	tmp = (char *)s;
	i = 0;
	while (tmp[i])
	{
		tab[i] = tmp[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *rt;
    int i;
	if (!s1 || !s2)
		return (NULL);
	if ((rt = malloc((ft_strlen((char*)s1) + ft_strlen((char *)s2)) * sizeof(char))) == NULL)
		return (NULL);
    i = 0;
	while (s1[i])
	{
		rt[i] = s1[i];
		i++;
	}
	rt[i] = '\0';
	return (ft_strcat(rt, s2));
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
    int i;

	if (dest <= src)
    {
        i = 0;
	    while (i < n)
	    {
	    	((char*)dest)[i] = ((char*)src)[i];
	    	i++;
	    }
	    return (dest);
    }
	else
	{
		while (n >= 1)
		{
			((char*)dest)[n - 1] = ((char*)src)[n - 1];
			n--;
		}
	}
	return (dest);
}




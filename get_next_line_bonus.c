/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:32:31 by otmallah          #+#    #+#             */
/*   Updated: 2021/11/29 14:32:32 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_check_sec(char *str, int c)
{
	int		i;
	int		j;
	char	*st;

	i = 0;
	j = 0;
	st = NULL;
	while (str[i] != c && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		st = ft_calloc(1, (i + 1));
	else if (str[i] == '\n')
		st = ft_calloc(1, (i + 2));
	if (!st)
		return (NULL);
	while (str[j] != c && str[j] != '\0')
	{
		st[j] = str[j];
		j++;
	}
	st[j] = str[j];
	return (st);
}

char	*ft_check(char *str, char *buf, int fd)
{
	int		i;
	int		read_line;
	char	*temp;

	i = 0;
	while (buf && buf[i] != '\n')
	{
		i = 0;
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line <= 0)
			break ;
		buf[read_line] = '\0';
		temp = ft_strjoin(str, buf);
		free(str);
		str = temp;
		while (buf[i] != '\n' && buf[i])
			i++;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*str[OPEN_MAX];
	char		*tomp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	if (str[fd] == NULL)
		str[fd] = ft_strdup("");
	str[fd] = ft_check(str[fd], buff, fd);
	free(buff);
	if (str[fd][0] == '\0')
	{
		free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	tomp = ft_check_sec(str[fd], '\n');
	str[fd] = ft_strchr(str[fd], '\n');
	return (tomp);
}

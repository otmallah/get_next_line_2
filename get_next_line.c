/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:36:09 by otmallah          #+#    #+#             */
/*   Updated: 2021/11/29 14:36:11 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*str;
	char		*tomp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = ft_calloc(1, BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (str == NULL)
		str = ft_strdup("");
	str = ft_check(str, buff, fd);
	free(buff);
	if (str[0] == '\0')
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	tomp = ft_check_sec(str, '\n');
	str = ft_strchr(str, '\n');
	return (tomp);
}

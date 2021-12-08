/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:33:05 by otmallah          #+#    #+#             */
/*   Updated: 2021/11/29 14:33:10 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcat(char *str1, char *str2)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str1[i])
		i++;
	while (str2[j])
	{
		str1[i + j] = str2[j];
		j++;
	}
	str1[i + j] = '\0';
	return (str1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		k;
	int		i;
	int		j;

	k = 0;
	i = 0;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (NULL);
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	str = (char *)malloc(i + j + 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	if (!str)
		return (NULL);
	ft_strcat(str, (char *)s1);
	ft_strcat(str, (char *)s2);
	return (str);
}

char	*ft_strchr(char *str, int c)
{
	int		i;
	char	*sep;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
		{
			sep = ft_strdup(str + i + 1);
			free(str);
			return (sep);
		}
		i++;
	}
	free(str);
	return (0);
}

char	*ft_strdup(const char *str)
{
	char	*se;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	se = (char *)malloc((i + 1) * sizeof(char));
	if (!se)
		return (NULL);
	while (str[j])
	{
		se[j] = str[j];
		j++;
	}
	se[j] = '\0';
	return (se);
}

void	*ft_calloc(size_t n, size_t c)
{
	void		*str;
	size_t		i;

	i = 0;
	str = malloc(n * c);
	if (str == 0)
		return (NULL);
	while (i < (n * c))
	{
		((char *)str)[i] = 0;
		i++;
	}
	return (str);
}

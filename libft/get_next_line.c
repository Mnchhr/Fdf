/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:08:51 by mkuehl            #+#    #+#             */
/*   Updated: 2021/12/17 19:08:52 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy_gnl(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_get_line_from_remainder(char **line, char **remainder)
{
	char	*ptr;

	ptr = ft_strchr_gnl(*remainder, '\n');
	if (ptr)
	{
		*ptr = '\0';
		*line = ft_strjoin_gnl(*line, *remainder);
		if (!(*line))
			return (-1);
		*remainder = ft_strcpy_gnl(*remainder, ++ptr);
		return (1);
	}
	else
	{
		*line = ft_strjoin_gnl(*line, *remainder);
		if (!(*line))
			return (-1);
		free(*remainder);
		*remainder = NULL;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*remainder;
	char		buff[BUFFER_SIZE + 1];
	ssize_t		flag;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line || (read(fd, buff, 0) < -1))
		return (-1);
	*line = ft_strnew_gnl(0);
	if (remainder && line)
		if ((ft_get_line_from_remainder(line, &remainder)) == 1)
			return (1);
	flag = 1;
	while (flag)
	{
		flag = read(fd, buff, BUFFER_SIZE);
		if (flag < 0)
			return (-1);
		buff[flag] = '\0';
		remainder = ft_strdup_gnl(buff);
		if (!remainder || !line)
			return (-1);
		if ((ft_get_line_from_remainder(line, &remainder)) == 1)
			return (1);
	}
	return (0);
}

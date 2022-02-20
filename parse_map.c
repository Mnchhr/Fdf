/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:53:14 by mkuehl            #+#    #+#             */
/*   Updated: 2021/12/16 17:10:55 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_wdcounter(char const *str, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

static int	ft_get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY);
	height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		height++;
		free(line);
	}
	free(line);
	close(fd);
	return (height);
}

static int	ft_get_width(char *file_name)
{
	char	*line;
	int		fd;
	int		width;

	fd = open(file_name, O_RDONLY);
	get_next_line(fd, &line);
	width = ft_wdcounter(line, ' ');
	free(line);
	close(fd);
	return (width);
}

static void	ft_fill_array(int *array, char *line)
{
	int		j;
	char	**nums;

	nums = ft_split(line, ' ');
	j = 0;
	while (nums[j])
	{
		array[j] = ft_atoi(nums[j]);
		j++;
	}
	j = 0;
	while (nums[j])
		free(nums[j++]);
	free(nums);
}

void	ft_parse_map(char *file_name, t_fdf *data)
{
	int		fd;
	int		i;
	char	*line;

	data->height = ft_get_height(file_name);
	data->width = ft_get_width(file_name);
	ft_alloc_mem_for_array(data);
	i = 0;
	fd = open(file_name, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		ft_fill_array(data->z_array[i++], line);
		free(line);
	}
	free(line);
	close(fd);
}

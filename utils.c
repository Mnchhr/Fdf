/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:55:45 by mkuehl            #+#    #+#             */
/*   Updated: 2021/12/17 17:23:25 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	if (y < HEIGHT && x < WIDTH && y >= 0 && x >= 0)
	{
		dst = data->addr + (y * data->line_length + \
			x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	ft_check_input(char *file_name)
{
	int	fd;

	fd = open(file_name, O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		ft_terminate("No folders allowed");
	}
	close(fd);
	fd = open(file_name, O_RDONLY);
	if ((fd < 0) || (read(fd, NULL, 0) < 0))
	{
		close(fd);
		ft_terminate(strerror(errno));
	}
	close(fd);
}

int	ft_alloc_mem_for_array(t_fdf *data)
{
	int	i;

	data->z_array = (int **)malloc(sizeof(int *) * (data->height + 1));
	if (!data->z_array)
	{
		free(data);
		ft_terminate("Malloc error");
	}
	i = 0;
	while (i <= data->height)
	{
		data->z_array[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		if (!data->z_array[i])
		{
			while (i > 0)
				free(data->z_array[--i]);
			free(data->z_array);
			free(data);
			ft_terminate("Malloc error");
		}
		i++;
	}
	return (0);
}

float	ft_mod(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

float	ft_max(float x, float y)
{
	if (x >= y)
		return (x);
	else
		return (y);
}

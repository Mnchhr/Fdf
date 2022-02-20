/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:01:58 by mkuehl            #+#    #+#             */
/*   Updated: 2021/12/19 18:37:28 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_isometric(float *x, float *y, int z, t_fdf *data)
{
	if (data->conic_img == 0)
	{
		*x = (*x - *y) * cos(1);
		*y = (*x + *y) * sin(1.2) - z * ALTITUDE;
	}
	*x += (data->shift_x + WIDTH / 2);
	*y += (data->shift_y + HEIGHT / 3);
}

static void	ft_bresenham(t_coords *coords, t_fdf *data)
{
	float	max;
	float	x;
	float	y;
	float	x1;
	float	y1;

	x = coords->x * data->zoom;
	x1 = coords->x1 * data->zoom;
	y = coords->y * data->zoom;
	y1 = coords->y1 * data->zoom;
	if (coords->z || coords->z1)
		data->color = 0x0066a754;
	else
		data->color = 0x008fd8ff;
	ft_isometric(&x, &y, coords->z, data);
	ft_isometric(&x1, &y1, coords->z1, data);
	max = ft_max(ft_mod(x1 - x), ft_mod(y1 - y));
	data->x_step = (x1 - x) / max;
	data->y_step = (y1 - y) / max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		ft_mlx_pixel_put(data, x, y, data->color);
		x += data->x_step;
		y += data->y_step;
	}
}

static void	ft_init_image(t_coords *coords, t_fdf *data)
{
	coords->y = 0;
	while (coords->y < data->height)
	{
		coords->x = 0;
		while (coords->x < data->width)
		{
			coords->x1 = coords->x + 1;
			coords->y1 = coords->y;
			coords->z = data->z_array[(int)coords->y][(int)coords->x];
			coords->z1 = data->z_array[(int)coords->y1][(int)coords->x1];
			if (coords->x < data->width - 1)
				ft_bresenham(coords, data);
			coords->y1 = coords->y + 1;
			coords->x1 = coords->x;
			coords->z1 = data->z_array[(int)coords->y1][(int)coords->x1];
			if (coords->y < data->height - 1)
				ft_bresenham(coords, data);
			coords->x++;
		}
		coords->y++;
	}
}

static void	ft_string_put(t_fdf *data)
{
	int		y;
	void	*mlx;
	void	*win;
	int		color;

	y = 0;
	color = 0x00ffffff;
	mlx = data->mlx_ptr;
	win = data->win_ptr;
	mlx_string_put(mlx, win, 65, y += 20, 0x0000eeff, "CONTROL TOOLS:");
	mlx_string_put(mlx, win, 15, y += 35, color, "Zoom in/out: Scroll or +/-");
	mlx_string_put(mlx, win, 15, y += 30, color, "Move: Arrows");
	mlx_string_put(mlx, win, 15, y += 25, color, "Isometric projection: I Key");
	mlx_string_put(mlx, win, 15, y += 25, color, "Top view projection: P Key");
}

void	ft_draw(t_fdf *data)
{
	t_coords	*coords;

	coords = (t_coords *)malloc(sizeof(t_coords));
	if (!coords)
	{
		ft_free_data(&data);
		ft_terminate("Malloc error");
	}
	ft_init_image(coords, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	ft_string_put(data);
	free(coords);
}

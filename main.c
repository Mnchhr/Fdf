/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:45:07 by mkuehl            #+#    #+#             */
/*   Updated: 2021/12/19 15:58:47 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_redraw(t_fdf *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel, \
		&data->line_length, &data->endian);
	ft_draw(data);
}

static void	ft_escape_prog(t_fdf *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_free_data(&data);
	exit(0);
}

static int	deal_key(int key, t_fdf *data)
{
	if (key == 126)
		data->shift_y -= 50;
	else if (key == 125)
		data->shift_y += 50;
	else if (key == 124)
		data->shift_x += 50;
	else if (key == 123)
		data->shift_x -= 50;
	else if (key == 69 && data->zoom <= 50)
		data->zoom += 1;
	else if (key == 78 && data->zoom >= 5)
		data->zoom -= 1;
	else if (key == 35)
		data->conic_img = 1;
	else if (key == 34)
		data->conic_img = 0;
	else if (key == 53)
		ft_escape_prog(data);
	ft_redraw(data);
	return (0);
}

static int	deal_mouse(int button, int x, int y, t_fdf *data)
{
	if (button == 4 && data->zoom <= 50)
		data->zoom += 1;
	else if (button == 5 && data->zoom >= 5)
		data->zoom -= 1;
	ft_redraw(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf		*data;

	if (argc == 2)
	{
		ft_check_input(argv[1]);
		ft_init_data(&data);
		ft_parse_map(argv[1], data);
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "FDF");
		data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
		data->addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel, \
			&data->line_length, &data->endian);
		ft_draw(data);
		mlx_mouse_hook(data->win_ptr, deal_mouse, data);
		mlx_key_hook(data->win_ptr, deal_key, data);
		mlx_loop(data->mlx_ptr);
	}
	else
		ft_terminate("Invalid number of arguments");
	return (0);
}

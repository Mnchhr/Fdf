/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:45:11 by mkuehl            #+#    #+#             */
/*   Updated: 2021/12/19 15:31:21 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <errno.h>

# define HEIGHT 1000
# define WIDTH 1500
# define ALTITUDE 10

typedef struct s_coords
{
	float	x;
	float	y;
	float	x1;
	float	y1;
	int		z;
	int		z1;
}	t_coords;

typedef struct s_fdf
{
	int		conic_img;
	int		width;
	int		height;
	int		**z_array;
	int		color;
	int		zoom;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	float	x_step;
	float	y_step;
	int		shift_x;
	int		shift_y;
}	t_fdf;

void	ft_parse_map(char *file_name, t_fdf *data);
void	ft_draw(t_fdf *data);
void	ft_mlx_pixel_put(t_fdf *data, int x, int y, int color);
void	ft_check_input(char *file_name);
int		ft_alloc_mem_for_array(t_fdf *data);
float	ft_max(float x, float y);
float	ft_mod(float i);
void	ft_terminate(char *message);
void	ft_init_data(t_fdf **data);
void	ft_free_data(t_fdf **data);

#endif
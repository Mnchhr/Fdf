/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:37:39 by mkuehl            #+#    #+#             */
/*   Updated: 2021/12/19 15:24:52 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_terminate(char *message)
{
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	exit(1);
}

void	ft_init_data(t_fdf **data)
{
	(*data) = (t_fdf *)malloc(sizeof(t_fdf));
	if (!(*data))
		ft_terminate("Malloc error");
	(*data)->zoom = 10;
	(*data)->shift_x = 0;
	(*data)->shift_y = 0;
	(*data)->conic_img = 0;
}

void	ft_free_data(t_fdf **data)
{
	int	i;

	i = 0;
	while (i < (*data)->height + 1)
		free((*data)->z_array[i++]);
	free((*data)->z_array);
	free((*data));
}

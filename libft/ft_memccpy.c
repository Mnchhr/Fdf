/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:12:45 by mkuehl            #+#    #+#             */
/*   Updated: 2021/05/05 20:02:52 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;
	size_t			i;

	i = 0;
	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (n--)
	{
		destination[i] = source[i];
		if (source[i] == (unsigned char)c)
			return (destination + i + 1);
		i++;
	}
	return (NULL);
}

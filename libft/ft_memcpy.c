/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:11:47 by mkuehl            #+#    #+#             */
/*   Updated: 2021/05/11 20:52:18 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;

	if (!n || dst == src)
		return (dst);
	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (n--)
		*destination++ = *source++;
	return (dst);
}

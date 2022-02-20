/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:12:54 by mkuehl            #+#    #+#             */
/*   Updated: 2021/05/11 20:52:04 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*destination;
	char	*source;

	destination = (char *)dst;
	source = (char *)src;
	if (!len || dst == src)
		return (dst);
	if (dst < src)
	{
		while (len--)
			*destination++ = *source++;
	}
	else
	{
		destination += len;
		source += len;
		while (len--)
			*--destination = *--source;
	}
	return (dst);
}

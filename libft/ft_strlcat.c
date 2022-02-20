/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:13:14 by mkuehl            #+#    #+#             */
/*   Updated: 2021/05/08 15:41:33 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t dstsize, size_t dstlen)
{
	if (dstsize < dstlen)
		return (dstsize);
	else
		return (dstlen);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	strlen;
	size_t	dstlen;
	size_t	i;

	dstlen = ft_strlen(dst);
	strlen = ft_min(dstsize, dstlen) + ft_strlen(src);
	if (dstsize > dstlen)
	{
		dst = dst + dstlen;
		dstsize = dstsize - dstlen;
		i = 0;
		while (src[i] != '\0' && dstsize > 1)
		{
			dst[i] = src[i];
			i++;
			dstsize--;
		}
		dst[i] = '\0';
	}
	return (strlen);
}

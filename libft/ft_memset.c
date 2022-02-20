/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 19:44:01 by mkuehl            #+#    #+#             */
/*   Updated: 2021/04/19 20:42:50 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	altc;
	unsigned char	*ptr;

	altc = (unsigned char)c;
	ptr = (unsigned char *)b;
	while (len > 0)
	{
		*ptr = altc;
		ptr++;
		len--;
	}
	return (b);
}

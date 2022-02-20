/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:46:18 by mkuehl            #+#    #+#             */
/*   Updated: 2021/05/10 19:43:15 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	nbytes;

	if (nmemb == 0 || size == 0)
		return ((void *)malloc(1));
	nbytes = nmemb * size;
	ptr = (void *)malloc(nbytes);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nbytes);
	return (ptr);
}

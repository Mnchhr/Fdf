/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:13:49 by mkuehl            #+#    #+#             */
/*   Updated: 2021/05/05 20:18:30 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	size_t	i;

	i = ft_strlen(s);
	ptr = (char *)s;
	ptr += i;
	i++;
	while (i--)
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr--;
	}
	return (NULL);
}

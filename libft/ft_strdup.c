/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:15:18 by mkuehl            #+#    #+#             */
/*   Updated: 2021/11/08 15:49:13 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_libft(const char *s1)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s1) + 1;
	ptr = (char *)malloc(len * sizeof(char));
	if (!ptr)
		return (NULL);
	len = 0;
	while (s1[len] != '\0')
	{
		ptr[len] = s1[len];
		len++;
	}
	ptr[len] = '\0';
	return (ptr);
}

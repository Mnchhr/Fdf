/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:13:40 by mkuehl            #+#    #+#             */
/*   Updated: 2021/05/10 17:40:15 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hay;
	size_t	needle_len;
	size_t	i;
	size_t	j;

	hay = (char *)haystack;
	needle_len = ft_strlen(needle);
	if (!(needle_len))
		return (hay);
	if (ft_strlen(haystack) < needle_len || len < needle_len)
		return (NULL);
	i = 0;
	while (hay[i] && i <= len - needle_len)
	{
		j = 0;
		while (needle[j] && needle[j] == hay[i + j])
			j++;
		if (j == needle_len)
			return (&hay[i]);
		i++;
	}
	return (NULL);
}

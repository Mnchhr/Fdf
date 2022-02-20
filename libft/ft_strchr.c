/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:13:04 by mkuehl            #+#    #+#             */
/*   Updated: 2021/05/05 20:22:16 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*alts;
	size_t	i;

	i = ft_strlen(s) + 1;
	alts = (char *)s;
	while (i--)
	{
		if (*alts == (unsigned char)c)
			return (alts);
		alts++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:15:54 by mkuehl            #+#    #+#             */
/*   Updated: 2021/11/08 15:51:12 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_get_str(char const *s, size_t start, size_t len)
{
	char	*substr;
	size_t	i;

	substr = (char *)malloc(len * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (--len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	strlen;
	size_t	tempstart;

	if (!s)
		return (NULL);
	tempstart = (size_t)start;
	strlen = ft_strlen(s);
	if (strlen < tempstart)
	{
		substr = ft_strdup_libft("");
		return (substr);
	}
	if ((strlen + tempstart) < len)
		len = strlen + 1;
	substr = ft_get_str(s, tempstart, len + 1);
	return (substr);
}

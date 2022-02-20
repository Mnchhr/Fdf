/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:15:45 by mkuehl            #+#    #+#             */
/*   Updated: 2021/11/08 15:50:58 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_in_set(char s, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	last;

	if (!s1)
		return (ft_strdup_libft(""));
	if (!set)
		return ((char *)s1);
	last = ft_strlen(s1) - 1;
	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_in_set(s1[i], set) != 1)
			break ;
		i++;
	}
	while (last != 0)
	{
		if (ft_in_set(s1[last], set) != 1)
			break ;
		last--;
	}
	if (last < i)
		return (ft_strdup_libft(""));
	return (ft_substr(s1, i, (last - i + 1)));
}

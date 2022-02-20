/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:08:45 by mkuehl            #+#    #+#             */
/*   Updated: 2021/12/17 19:09:22 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	char	*alts;
	size_t	i;

	i = ft_strlen_gnl(s) + 1;
	alts = (char *)s;
	while (i--)
	{
		if (*alts == (unsigned char)c)
			return (alts);
		alts++;
	}
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1) \
		* sizeof(char));
	if (!s3)
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free(s1);
	return (s3);
}

char	*ft_strdup_gnl(const char *s1)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen_gnl(s1) + 1;
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

char	*ft_strnew_gnl(size_t size)
{
	char	*newstr;

	newstr = (char *)malloc(sizeof(char) * (size + 1));
	if (!newstr)
		return (NULL);
	newstr[size] = '\0';
	while (size--)
		newstr[size] = '\0';
	return (newstr);
}

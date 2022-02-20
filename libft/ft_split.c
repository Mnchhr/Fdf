/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:14:58 by mkuehl            #+#    #+#             */
/*   Updated: 2021/11/08 15:50:37 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_string_count(char const *s, char c)
{
	size_t	count;
	size_t	index;

	count = 0;
	index = 0;
	while (s[index])
	{
		while (s[index] == c)
			index++;
		if (s[index])
			count++;
		while (s[index] && s[index] != c)
			index++;
	}
	return (count);
}

static	void	ft_free(char **array, size_t i)
{
	while (i--)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array[0]);
	array[0] = NULL;
	free(array);
	array = NULL;
}

static	char	*ft_get_string(char *subs, char c)
{
	const char	*string;

	string = (const char *)subs;
	while (*subs && *subs != c)
		subs++;
	*subs = '\0';
	return (ft_strdup_libft(string));
}

static	char	**ft_trim_strings(char *s, char c, size_t count, char **array)
{
	char	*string;
	size_t	i;

	array = (char **)ft_calloc((count + 1), sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			string = ft_get_string(s, c);
			if (!string)
			{
				ft_free(array, i);
				return (NULL);
			}
			array[i++] = string;
			s += (ft_strlen(string) + 1);
		}
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	char	*temps;
	size_t	wordscount;

	if (!s)
		return (0);
	if (!*s)
	{
		array = (char **)ft_calloc(1, sizeof(char *));
		array[0] = NULL;
		return (array);
	}
	if (!c)
	{
		array = (char **)ft_calloc(2, sizeof(char *));
		array[0] = ft_strdup_libft(s);
		array[1] = NULL;
		return (array);
	}
	wordscount = ft_string_count(s, c);
	temps = ft_strdup_libft(s);
	array = NULL;
	array = ft_trim_strings(temps, c, wordscount, array);
	free(temps);
	return (array);
}

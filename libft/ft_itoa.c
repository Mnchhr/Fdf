/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:14:37 by mkuehl            #+#    #+#             */
/*   Updated: 2021/11/10 16:51:37 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_negative(int n)
{
	int	negative;

	negative = 0;
	if (n < 0)
		negative = 1;
	return (negative);
}

static	int	ft_numlen_itoa(int num, int negative)
{
	int	numlen;

	numlen = 1;
	while (num / 10)
	{
		numlen++;
		num /= 10;
	}
	return (numlen + negative);
}

char	*ft_itoa(int n)
{
	int		numlen;
	int		negative;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup_libft("-2147483648"));
	negative = ft_negative(n);
	if (n < 0)
		n *= -1;
	numlen = ft_numlen_itoa(n, negative);
	str = (char *)ft_calloc(numlen + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[numlen--] = '\0';
	while (numlen >= negative)
	{
		str[numlen--] = (n % 10) + '0';
		n /= 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}

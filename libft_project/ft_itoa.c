/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorasan <kcorasan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:29:30 by kcorasan          #+#    #+#             */
/*   Updated: 2026/06/21 17:29:31 by kcorasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_num_len(long long n)
{
	size_t	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long long	num;
	size_t		len;
	char		*str;

	num = n;
	len = ft_num_len(num);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num < 0)
		num = -num;
	while (len > 0)
	{
		if (num >= 10)
			str[--len] = (char)('0' + (num % 10));
		else
			str[--len] = (char)('0' + num);
		num /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

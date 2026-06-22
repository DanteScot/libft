/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorasan <kcorasan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 16:45:43 by kcorasan          #+#    #+#             */
/*   Updated: 2026/06/20 16:45:43 by kcorasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s2;
	size_t				i;

	d = (unsigned char *)dest;
	s2 = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s2[i];
		i++;
	}
	return (dest);
}

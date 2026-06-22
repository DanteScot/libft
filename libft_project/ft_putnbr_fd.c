/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorasan <kcorasan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:39:48 by kcorasan          #+#    #+#             */
/*   Updated: 2026/06/21 17:39:48 by kcorasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printnbr(long long n, int fd)
{
	char	c;

	if (n >= 10)
		ft_printnbr(n / 10, fd);
	c = (char)('0' + (n % 10));
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	num;

	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	ft_printnbr(num, fd);
}

#include "libft.h"

static void	ft_putnbr_ll(long long n, int fd)
{
	char	c;

	if (n >= 10)
		ft_putnbr_ll(n / 10, fd);
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
	ft_putnbr_ll(num, fd);
}

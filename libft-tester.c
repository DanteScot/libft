/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft-tester.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorasan <kcorasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 18:21:54 by kcorasan          #+#    #+#             */
/*   Updated: 2026/06/06 19:15:18 by kcorasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./project/libft.h"
#include <stdio.h>

static void	result(int counter, int ok)
{
	if (ok)
		printf("%d: OK\n", counter);
	else
		printf("%d: ERRORE\n", counter);
}

void	test_isalpha(void)
{
	int	counter;

	printf("\n------ BEGIN TEST FT_ISALPHA ------\n");
	counter = 0;
	result(++counter, ft_isalpha('a') == 1);
	result(++counter, ft_isalpha('A') == 1);
	result(++counter, ft_isalpha('z') == 1);
	result(++counter, ft_isalpha('Z') == 1);
	result(++counter, ft_isalpha('k') == 1);
	result(++counter, ft_isalpha('K') == 1);
	result(++counter, ft_isalpha('1') == 0);
	result(++counter, ft_isalpha(10) == 0);
	result(++counter, ft_isalpha('[') == 0);
	result(++counter, ft_isalpha('/') == 0);
	printf("------ END TEST FT_ISALPHA ------\n");
}

void	test_isdigit(void)
{
	int	counter;

	printf("\n------ BEGIN TEST FT_ISDIGIT ------\n");
	counter = 0;
	result(++counter, ft_isdigit('0') == 1);
	result(++counter, ft_isdigit('5') == 1);
	result(++counter, ft_isdigit('9') == 1);
	result(++counter, ft_isdigit('a') == 0);
	result(++counter, ft_isdigit(' ') == 0);
	result(++counter, ft_isdigit('/') == 0);
	result(++counter, ft_isdigit(47) == 0);
	result(++counter, ft_isdigit(58) == 0);
	printf("------ END TEST FT_ISDIGIT ------\n");
}

void	test_isalnum(void)
{
	int	counter;

	printf("\n------ BEGIN TEST FT_ISALNUM ------\n");
	counter = 0;
	result(++counter, ft_isalnum('a') == 1);
	result(++counter, ft_isalnum('Z') == 1);
	result(++counter, ft_isalnum('0') == 1);
	result(++counter, ft_isalnum('7') == 1);
	result(++counter, ft_isalnum('-') == 0);
	result(++counter, ft_isalnum(' ') == 0);
	result(++counter, ft_isalnum('!') == 0);
	printf("------ END TEST FT_ISALNUM ------\n");
}

void	test_isascii(void)
{
	int	counter;

	printf("\n------ BEGIN TEST FT_ISASCII ------\n");
	counter = 0;
	result(++counter, ft_isascii(0) == 1);
	result(++counter, ft_isascii(32) == 1);
	result(++counter, ft_isascii(65) == 1);
	result(++counter, ft_isascii(127) == 1);
	result(++counter, ft_isascii(128) == 0);
	result(++counter, ft_isascii(-1) == 0);
	result(++counter, ft_isascii(255) == 0);
	printf("------ END TEST FT_ISASCII ------\n");
}

void	test_isprint(void)
{
	int	counter;

	printf("\n------ BEGIN TEST FT_ISPRINT ------\n");
	counter = 0;
	result(++counter, ft_isprint(32) == 1);
	result(++counter, ft_isprint(48) == 1);
	result(++counter, ft_isprint(126) == 1);
	result(++counter, ft_isprint(31) == 0);
	result(++counter, ft_isprint(127) == 0);
	result(++counter, ft_isprint(10) == 0);
	printf("------ END TEST FT_ISPRINT ------\n");
}

void	test_strlen(void)
{
	size_t	len;

	printf("\n------ BEGIN TEST FT_STRLEN ------\n");
	len = ft_strlen("");
	printf("1: %s\n", len == 0 ? "OK" : "ERRORE");

	len = ft_strlen("hello");
	printf("2: %s\n", len == 5 ? "OK" : "ERRORE");

	len = ft_strlen("ciao");
	printf("3: %s\n", len == 4 ? "OK" : "ERRORE");
    
	len = ft_strlen("a b");
	printf("4: %s\n", len == 3 ? "OK" : "ERRORE");

	len = ft_strlen("\0hidden");
	printf("5: %s\n", len == 0 ? "OK" : "ERRORE");
	printf("------ END TEST FT_STRLEN ------\n");
}

void	test_memset(void)
{
	char	buf[10];
	char	*ret;
	int	counter;
	size_t	i;

	printf("\n------ BEGIN TEST FT_MEMSET ------\n");
	counter = 0;
	for (i = 0; i < sizeof(buf); i++)
		buf[i] = 'x';
	ret = ft_memset(buf, 'a', 5);
	result(++counter, ret == buf);
	result(++counter, buf[0] == 'a' && buf[4] == 'a' && buf[5] == 'x');
	ret = ft_memset(buf, 0, 3);
	result(++counter, ret == buf);
	result(++counter, buf[0] == 0 && buf[2] == 0 && buf[3] == 'a');
	result(++counter, ft_memset(buf, 'b', 0) == buf);
	result(++counter, buf[0] == 0);
	result(++counter, ft_memset(buf, 'z', 10) == buf && buf[9] == 'z');
	printf("------ END TEST FT_MEMSET ------\n");
}

int	main(void)
{
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_strlen();
	test_memset();

	return (0);
}

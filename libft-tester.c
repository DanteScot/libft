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
#include <string.h>

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

void	test_bzero_memcpy_memmove(void)
{
	char a[6] = "hello";
	char b[6];

	printf("\n------ BEGIN TEST BZERO/MEMCPY/MEMMOVE ------\n");
	ft_bzero(a, 5);
	printf("bzero: %s\n", a[0] == 0 ? "OK" : "ERRORE");
	ft_memcpy(b, "abcde", 6);
	printf("memcpy: %s\n", strcmp(b, "abcde") == 0 ? "OK" : "ERRORE");
	ft_memmove(b + 1, b, 4);
	printf("memmove: %s\n", strncmp(b + 1, "abcd", 4) == 0 ? "OK" : "ERRORE");
	printf("------ END TEST BZERO/MEMCPY/MEMMOVE ------\n");
}

void	test_strlcpy_cat_and_chr(void)
{
	char dst[10];

	printf("\n------ BEGIN TEST STRLCPY/STRLCAT/STRCHR/RCHR ------\n");
	ft_strlcpy(dst, "hello", sizeof(dst));
	printf("strlcpy: %s\n", strcmp(dst, "hello") == 0 ? "OK" : "ERRORE");
	ft_strlcat(dst, " world", sizeof(dst));
	printf("strlcat: %s\n", strstr(dst, "hello") ? "OK" : "ERRORE");
	printf("strchr: %s\n", ft_strchr("abc", 'b') ? "OK" : "ERRORE");
	printf("strrchr: %s\n", ft_strrchr("abca", 'a') ? "OK" : "ERRORE");
	printf("------ END TEST STRLCPY/STRLCAT/STRCHR/RCHR ------\n");
}

void	test_toupper_tolower_and_strncmp(void)
{
	printf("\n------ BEGIN TEST TOUPPER/TOLOWER/STRNCMP ------\n");
	printf("toupper: %s\n", ft_toupper('a') == 'A' ? "OK" : "ERRORE");
	printf("tolower: %s\n", ft_tolower('A') == 'a' ? "OK" : "ERRORE");
	printf("strncmp: %s\n", ft_strncmp("abc", "abd", 2) == 0 ? "OK" : "ERRORE");
	printf("------ END TEST TOUPPER/TOLOWER/STRNCMP ------\n");
}

void	test_memchr_memcmp_strnstr_atoi(void)
{
	char s[] = "abcd";

	printf("\n------ BEGIN TEST MEMCHR/MEMCMP/STRNSTR/ATOI ------\n");
	printf("memchr: %s\n", ft_memchr(s, 'c', 4) ? "OK" : "ERRORE");
	printf("memcmp: %s\n", ft_memcmp("ab", "ab", 2) == 0 ? "OK" : "ERRORE");
	printf("strnstr: %s\n", ft_strnstr("hello world", "world", 11) ? "OK" : "ERRORE");
	printf("atoi: %s\n", ft_atoi("  -42") == -42 ? "OK" : "ERRORE");
	printf("------ END TEST MEMCHR/MEMCMP/STRNSTR/ATOI ------\n");
}

void	test_calloc_strdup_substr_join_trim_split_itoa(void)
{
	char *p;
	char **arr;

	printf("\n------ BEGIN TEST CALLOC/DUP/… ------\n");
	p = ft_calloc(5, 1);
	printf("calloc: %s\n", p && p[0] == 0 ? "OK" : "ERRORE");
	free(p);
	p = ft_strdup("hello");
	printf("strdup: %s\n", p && strcmp(p, "hello") == 0 ? "OK" : "ERRORE");
	free(p);
	p = ft_substr("abcdef", 2, 3);
	printf("substr: %s\n", p && strcmp(p, "cde") == 0 ? "OK" : "ERRORE");
	free(p);
	p = ft_strjoin("ab", "cd");
	printf("strjoin: %s\n", p && strcmp(p, "abcd") == 0 ? "OK" : "ERRORE");
	free(p);
	p = ft_strtrim("--abc--", "-");
	printf("strtrim: %s\n", p && strcmp(p, "abc") == 0 ? "OK" : "ERRORE");
	free(p);
	arr = ft_split("one,two,three", ',');
	printf("split: %s\n", arr && arr[0] && strcmp(arr[0], "one") == 0 ? "OK" : "ERRORE");
	// free split
	if (arr)
	{
		int i = 0;
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
	p = ft_itoa(-123);
	printf("itoa: %s\n", p && strcmp(p, "-123") == 0 ? "OK" : "ERRORE");
	free(p);
	printf("------ END TEST CALLOC/DUP/… ------\n");
}

void	test_strmapi_striteri_putchar_putstr_putendl_putnbr(void)
{
	char *m;
	char s[] = "abc";

	printf("\n------ BEGIN TEST STRMAPI/STRITERI/PUT*FD ------\n");
	static char to_upper(unsigned int i, char c)
	{
		(void)i;
		if (c >= 'a' && c <= 'z')
			return (char)(c - 32);
		return (c);
	}
	static void noop_iter(unsigned int i, char *c)
	{
		(void)i;
		(void)c;
	}
	m = ft_strmapi("abc", to_upper);
	if (m) { free(m); }
	ft_striteri(s, noop_iter);
	ft_putchar_fd('A', 1);
	write(1, "\n", 1);
	ft_putstr_fd("hello", 1);
	write(1, "\n", 1);
	ft_putendl_fd("line", 1);
	ft_putnbr_fd(42, 1);
	write(1, "\n", 1);
	printf("------ END TEST STRMAPI/STRITERI/PUT*FD ------\n");
}

void	test_list_functions(void)
{
	t_list *lst = NULL;
	t_list *n1 = ft_lstnew((void *)"one");
	t_list *n2 = ft_lstnew((void *)"two");

	printf("\n------ BEGIN TEST LISTS ------\n");
	ft_lstadd_front(&lst, n1);
	ft_lstadd_back(&lst, n2);
	printf("lstsize: %s\n", ft_lstsize(lst) == 2 ? "OK" : "ERRORE");
	printf("lstlast: %s\n", ft_lstlast(lst) == n2 ? "OK" : "ERRORE");
	ft_lstdelone(n1, NULL);
	ft_lstclear(&lst, NULL);
	printf("------ END TEST LISTS ------\n");
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

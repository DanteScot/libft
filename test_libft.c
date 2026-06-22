#include "/home/kcorasan/Desktop/libft/libft_project/libft.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

static int	g_failures = 0;

#define CHECK(cond) \
	do { \
		if (!(cond)) { \
			fprintf(stderr, "[FAIL] %s:%d: %s\n", __FILE__, __LINE__, #cond); \
			g_failures++; \
		} else { \
			fprintf(stdout, "[ OK ] %s\n", #cond); \
		} \
	} while (0)

static char	shift_map(unsigned int i, char c)
{
	return ((char)(c + (char)i));
}

static void	upper_iter(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = (char)(*c - 32);
}

static void	*dup_int(void *ptr)
{
	int	*src;
	int	*dst;

	src = (int *)ptr;
	dst = (int *)malloc(sizeof(int));
	if (!dst)
		return (NULL);
	*dst = *src;
	return (dst);
}

static void	del_int(void *ptr)
{
	free(ptr);
}

static void	increment_int(void *ptr)
{
	int	*value;

	value = (int *)ptr;
	(*value)++;
}

static int	is_same_cstr(const char *a, const char *b)
{
	return (strcmp(a, b) == 0);
}

static void	test_char_and_memory(void)
{
	char	buf[32];
	char	dst[32];
	char	overlap[32];

	CHECK(ft_isalpha('a') == 1);
	CHECK(ft_isalpha('1') == 0);
	CHECK(ft_isdigit('9') == 1);
	CHECK(ft_isalnum('Z') == 1);
	CHECK(ft_isascii(127) == 1);
	CHECK(ft_isascii(128) == 0);
	CHECK(ft_isprint(' ') == 1);
	CHECK(ft_isprint('\n') == 0);

	CHECK(ft_strlen("libft") == 5);

	ft_memset(buf, 'A', 5);
	buf[5] = '\0';
	CHECK(strcmp(buf, "AAAAA") == 0);

	ft_bzero(buf, 5);
	CHECK(buf[0] == '\0' && buf[4] == '\0');

	ft_memcpy(dst, "hello", 6);
	CHECK(strcmp(dst, "hello") == 0);

	strcpy(overlap, "abcdef");
	ft_memmove(overlap + 2, overlap, 4);
	CHECK(strcmp(overlap, "ababcd") == 0);

	CHECK(ft_strlcpy(dst, "hello", sizeof(dst)) == 5);
	CHECK(strcmp(dst, "hello") == 0);
	CHECK(ft_strlcat(dst, " world", sizeof(dst)) == 11);
	CHECK(strcmp(dst, "hello world") == 0);

	CHECK(ft_toupper('a') == 'A');
	CHECK(ft_tolower('Z') == 'z');

	CHECK(ft_strchr("abc", 'b') != NULL);
	CHECK(ft_strchr("abc", 'x') == NULL);
	CHECK(ft_strrchr("abca", 'a') != NULL);

	CHECK(ft_strncmp("abc", "abd", 2) == 0);
	CHECK(ft_strncmp("abc", "abd", 3) < 0);

	CHECK(ft_memchr("hello", 'l', 5) != NULL);
	CHECK(ft_memcmp("abc", "abc", 3) == 0);
	CHECK(ft_memcmp("abc", "abd", 3) < 0);

	CHECK(ft_strnstr("hello world", "world", 11) != NULL);
	CHECK(ft_strnstr("hello world", "world", 4) == NULL);

	CHECK(ft_atoi("   -42") == -42);
	CHECK(ft_atoi("+123") == 123);

	{
		int	*p;

		p = (int *)ft_calloc(3, sizeof(int));
		CHECK(p != NULL);
		CHECK(p[0] == 0 && p[1] == 0 && p[2] == 0);
		free(p);
	}
	{
		void	*p;

		p = ft_calloc(0, 10);
		CHECK(p != NULL);
		free(p);
	}

	{
		char	*s;

		s = ft_strdup("copy");
		CHECK(s != NULL);
		CHECK(strcmp(s, "copy") == 0);
		free(s);
	}
}

static void	test_extra_strings(void)
{
	char	*s;
	char	*join;
	char	*trim;
	char	**split;
	char	*map;

	s = ft_substr("libft", 1, 3);
	CHECK(is_same_cstr(s, "ibf"));
	free(s);

	s = ft_substr("libft", 10, 2);
	CHECK(is_same_cstr(s, ""));
	free(s);

	join = ft_strjoin("hello", "libft");
	CHECK(is_same_cstr(join, "hellolibft"));
	free(join);

	trim = ft_strtrim("  \tlibft\n", " \t\n");
	CHECK(is_same_cstr(trim, "libft"));
	free(trim);

	split = ft_split("a,b,,c", ',');
	CHECK(split != NULL);
	CHECK(is_same_cstr(split[0], "a"));
	CHECK(is_same_cstr(split[1], "b"));
	CHECK(is_same_cstr(split[2], "c"));
	CHECK(split[3] == NULL);
	for (size_t i = 0; split[i]; i++)
		free(split[i]);
	free(split);

	split = ft_split("", ',');
	CHECK(split != NULL);
	CHECK(split[0] == NULL);
	free(split);

	map = ft_strmapi("abc", shift_map);
	CHECK(is_same_cstr(map, "ace"));
	free(map);

	{
		char	mutable[] = "abc";

		ft_striteri(mutable, upper_iter);
		CHECK(is_same_cstr(mutable, "ABC"));
	}
}

static void	test_output_functions(void)
{
	// ft_putchar_fd('X', STDOUT_FILENO);
	// ft_putstr_fd(" test", STDOUT_FILENO);
	// ft_putendl_fd(" line", STDOUT_FILENO);
	// ft_putnbr_fd(-2147483648, STDOUT_FILENO);
	// ft_putchar_fd('\n', STDOUT_FILENO);
	printf("[TEST] fd functions: ");
	fflush(stdout);

	ft_putchar_fd('X', 1);
	ft_putstr_fd(" test line", 1);
	ft_putendl_fd("", 1);

	printf("[TEST] ft_putnbr_fd(INT_MIN): ");
	fflush(stdout);
	ft_putnbr_fd(-2147483648, 1);
	printf("\n");
	CHECK(1);
}

static void	test_lists(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;
	t_list	*head;
	int		x;
	int		y;
	int		z;
	t_list	*mapped;

	x = 1;
	y = 2;
	z = 3;
	a = ft_lstnew(&x);
	b = ft_lstnew(&y);
	c = ft_lstnew(&z);
	CHECK(a && b && c);

	head = NULL;
	ft_lstadd_front(&head, a);
	CHECK(head == a);
	ft_lstadd_back(&head, b);
	ft_lstadd_back(&head, c);
	CHECK(ft_lstsize(head) == 3);
	CHECK(ft_lstlast(head) == c);

	ft_lstiter(head, increment_int);
	CHECK(x == 2 && y == 3 && z == 4);

	mapped = ft_lstmap(head, dup_int, del_int);
	CHECK(mapped != NULL);
	CHECK(ft_lstsize(mapped) == 3);
	CHECK(*(int *)mapped->content == 2);
	CHECK(*(int *)mapped->next->content == 3);
	CHECK(*(int *)ft_lstlast(mapped)->content == 4);

	ft_lstclear(&mapped, del_int);
	CHECK(mapped == NULL);

	ft_lstclear(&head, NULL);
	CHECK(head == NULL);
}

int	main(void)
{
	test_char_and_memory();
	test_extra_strings();
	test_output_functions();
	test_lists();

	if (g_failures == 0)
	{
		puts("All tests completed.");
		return (0);
	}
	fprintf(stderr, "%d checks failed.\n", g_failures);
	return (1);
}

*This project has been created as part of the 42 curriculum by <login1>.*

# libft

## Description
This project recreates a personal C library containing string, memory, character classification, conversion, output, and linked-list utilities. The goal is to understand how common libc-style functions work by implementing them from scratch.

## Instructions
Build the library with:

```bash
make
```

Clean object files with:

```bash
make clean
```

Remove the library and object files with:

```bash
make fclean
```

Rebuild everything with:

```bash
make re
```

Compile the standalone tester against the library:

```bash
cc -Wall -Wextra -Werror test_libft.c -L. -lft -o test_libft
```

Run it with:

```bash
./test_libft
```

## Library contents
The library includes:
- character checks: ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, ft_isprint
- memory and string handling: ft_strlen, ft_memset, ft_bzero, ft_memcpy, ft_memmove, ft_strlcpy, ft_strlcat, ft_toupper, ft_tolower, ft_strchr, ft_strrchr, ft_strncmp, ft_memchr, ft_memcmp, ft_strnstr, ft_atoi, ft_calloc, ft_strdup
- extra string helpers: ft_substr, ft_strjoin, ft_strtrim, ft_split, ft_itoa, ft_strmapi, ft_striteri
- output helpers: ft_putchar_fd, ft_putstr_fd, ft_putendl_fd, ft_putnbr_fd
- linked lists: ft_lstnew, ft_lstadd_front, ft_lstsize, ft_lstlast, ft_lstadd_back, ft_lstdelone, ft_lstclear, ft_lstiter, ft_lstmap

## Resources
- `man` pages for libc functions
- 42 libft subject
- C standard library documentation
- GCC/Clang documentation for warnings and build flags
- AI was used to generate the initial implementation, the Makefile, and the standalone test file, then to organize the project structure and edge-case coverage.

## Test file
A separate file, `test_libft.c`, is included to exercise all functions without depending on any external project files beyond the library itself.

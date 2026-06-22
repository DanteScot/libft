*This project has been created as part of the 42 curriculum by kcorasan.*

# libft

## Description
This project recreates libc plus some useful extra functions and linked-list utilities. The goal is to understand and implement everything from scratch.

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

<!-- Compile the standalone tester against the library:

```bash
cc -Wall -Wextra -Werror test_libft.c -L. -lft -o test_libft
```

Run it with:

```bash
./test_libft
``` -->

## Detailed description
The library includes various function for different use-cases, all implemented using as few external functions as possible.

- character checks, functions that check whether the character matches a specific criterion: ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, ft_isprint

- memory manipulation, function that works directly on the memory: ft_memset, ft_bzero, ft_memcpy, ft_memmove, ft_memchr, ft_memcmp, ft_calloc

- string manipulation, functions that works with the string (may use some memomory manipulation): ft_strlen, ft_strlcpy, ft_strlcat, ft_toupper, ft_tolower, ft_strchr, ft_strrchr, ft_strncmp, ft_strnstr, ft_atoi, ft_strdup, ft_substr, ft_strjoin, ft_strtrim, ft_split, ft_itoa, ft_strmapi, ft_striteri

- output helpers, functions used to easily print: ft_putchar_fd, ft_putstr_fd, ft_putendl_fd, ft_putnbr_fd

- linked lists, functions that manipulate memory in order to create, use and delete custom a structure: ft_lstnew, ft_lstadd_front, ft_lstsize, ft_lstlast, ft_lstadd_back, ft_lstdelone, ft_lstclear, ft_lstiter, ft_lstmap

## Resources
- `man:` pages for libc functions

- `42 libft subject:` for custom functions

- `Stack Overflow:` for various doubts about function implementation

- `Various websites:` for tutorials about the makefile

- `AI:` used to generate the base for this readme and the standalone test file (that is not part of the project itself, used to test edge cases that I may not think about). It was used as a validator too for the coherence between my work and the subject (after I was sure enough).

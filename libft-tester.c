#include "./project/libft.h"
#include <stdio.h>

void test_isalpha()
{
    printf("\n------ BEGIN TEST FT_ISALPHA ------\n");

    int counter = 0;

    counter++;
    if(ft_isalpha('a') == 1) printf("%d: OK\n", counter);
    else printf("%d: ERRORE\n", counter);

    counter++;
    if(ft_isalpha('A') == 1) printf("%d: OK\n", counter);
    else printf("%d: ERRORE\n", counter);

    counter++;
    if(ft_isalpha('z') == 1) printf("%d: OK\n", counter);
    else printf("%d: ERRORE\n", counter);

    counter++;
    if(ft_isalpha('Z') == 1) printf("%d: OK\n", counter);
    else printf("%d: ERRORE\n", counter);

    counter++;
    if(ft_isalpha('k') == 1) printf("%d: OK\n", counter);
    else printf("%d: ERRORE\n", counter);

    counter++;
    if(ft_isalpha('K') == 1) printf("%d: OK\n", counter);
    else printf("%d: ERRORE\n", counter);

    counter++;
    if(ft_isalpha('1') == 0) printf("%d: OK\n", counter);
    else printf("%d: ERRORE\n", counter);

    counter++;
    if(ft_isalpha(10) == 0) printf("%d: OK\n", counter);
    else printf("%d: ERRORE\n", counter);

    counter++;
    if(ft_isalpha('[') == 0) printf("%d: OK\n", counter);
    else printf("%d: ERRORE\n", counter);

    counter++;
    if(ft_isalpha('/') == 0) printf("%d: OK\n", counter);
    else printf("%d: ERRORE\n", counter);

    printf("------ END TEST FT_ISALPHA ------\n");
}

int main()
{
    test_isalpha();

    return 0;
}
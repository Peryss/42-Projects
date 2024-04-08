#include "libft.h"

int ft_isalpha(int arg)
{
    if (arg >= 'a' && arg <= 'z')
        return (2);
    if (arg >= 'A' && arg <= 'Z')
        return (1);
    return (0);
}
/*
int main()
{
    int i = 'A';
    int j = 'a';
    int x = '+';

    printf("A: %d\n", ft_isalpha(i));
    printf("a: %d\n", ft_isalpha(j));
    printf("+: %d\n", ft_isalpha(x));
    return (0);
}
*/
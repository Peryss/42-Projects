#include "libft.h"

int ft_isdigit(int arg)
{
    if (arg >= '0' && arg <= '9')
        return (1);
    return (0);
}
/*
int main()
{
    int i = 'A';
    int j = 'a';
    int x = '1';

    printf("A: %d\n", ft_isdigit(i));
    printf("a: %d\n", ft_isdigit(j));
    printf("1: %d\n", ft_isdigit(x));
    return (0);
}
*/
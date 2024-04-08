#include "libft.h"

int ft_isalnum(int arg)
{
    if (ft_isalpha(arg) != 0 || ft_isdigit(arg) != 0)
        return(1);
    return (0);
}
/*
int main()
{
    int i = '1';
    int j = 'a';
    int x = '+';

    printf("1: %d\n", ft_isalnum(i));
    printf("a: %d\n", ft_isalnum(j));
    printf("+: %d\n", ft_isalnum(x));
    return (0);
}
*/
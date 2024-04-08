#include "libft.h"

int ft_toupper(int ch)
{
    if (ft_isalpha(ch) == 2)
        ch = ch - 32;
    return (ch);
}
/*
int main()
{
    int a = 'a';
    int b = '+';
    
    printf ("a: %c\n", (char) ft_toupper(a));
    printf ("+: %c\n", (char) ft_toupper(b));
    return (0);
}
*/
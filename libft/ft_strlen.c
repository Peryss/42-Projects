#include "libft.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
        i++;
    return (i);
}
/*
int main()
{
    printf("String length: %d", ft_strlen("Hello World!"));
    return (0);
}
*/
#include "libft.h"

int atoi(const char *str)
{
    int i;
    int sign;
    int t;
    int nb;

    t = 1;
    i = 0;
    while (str[i] = 32 || (str[i] <= 13 && str[i] >= 9))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '+')
            sign = 1;
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] <= '9' && str[i] >= '0')
    {
        nb = 
    }

    return (0);
}
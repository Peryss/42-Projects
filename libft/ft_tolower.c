#include "libft.h"

int ft_tolower(int ch)
{
    if (ft_isalpha(ch) == 1)
        ch = ch + 32;
    return (ch);
}
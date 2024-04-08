# include "libft.h"

void *ft_memchr(const void *str, int c, size_t n)
{
    size_t i;
    unsigned char *ptr;

    ptr = (unsigned char *)str;
    i = 0;
    while (i < n)
    {
        if (ptr[i] == c)
            return (ptr + i);
        i++;
    }
    return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main () {
   const char str[] = "https://www.tutorialspoint.com";
   const char ch = '.';
   char *ret;

   ret = ft_memchr(str, ch, strlen(str));

   printf("String after |%c| is - |%s|\n", ch, ret);

   return(0);
}
*/
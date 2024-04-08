#include "libft.h"

char *ft_strrchr(char *str, int c)
{
    int i;

    i = ft_strlen(str) - 1;
    while (i >= 0)
    {
        if (str[i] == c)
            return (str + i);
        i--;
    }
    return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main () {
   char str[] = "https://www.tutorialspoint.com";
   char ch = '.';
   char *ret;

   ret = ft_strrchr(str, ch);

   printf("String after |%c| is - |%s|\n", ch, ret);
   
   return(0);
}
*/

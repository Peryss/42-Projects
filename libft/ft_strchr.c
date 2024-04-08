#include "libft.h"

char *ft_strchr(char *str, int c)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == c)
            return (str + i);
        i++;
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

   ret = ft_strchr(str, ch);

   printf("String after |%c| is - |%s|\n", ch, ret);
   
   return(0);
}
*/
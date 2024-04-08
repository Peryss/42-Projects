#include "libft.h"

int ft_strncmp(const char *str1, const char *str2, size_t n)
{
    size_t i;

    i = 0;
    while(i < n - 1 && str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
            return((char)str1[i] - (char)str2[i]);
        i++;
    }
    return ((char)str1[i] - (char)str2[i]);
}
/*
#include <stdio.h>
int main () {
   char str1[15];
   char str2[15];
   int ret;

   strcpy(str1, "ABCDE");
   strcpy(str2, "ABCDEF");

   ret = ft_strncmp(str1, str2, 6);

   printf("return value: %d", ret);
   
   return(0);
}
*/
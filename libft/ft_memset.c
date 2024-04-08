#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
    size_t i;
    char *ptr;

    ptr = s;
    i = 0;
    while (i < n)
    {
        ptr[i] = (unsigned char)c; 
        i++;
    }
    return (s);
}

/*
int main () {
   char str[50];

   strcpy(str,"This is string.h library function");
   puts(str);

   ft_memset(str,'$',7);
   puts(str);
   
   return(0);
}
*/
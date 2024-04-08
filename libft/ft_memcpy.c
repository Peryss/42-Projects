#include "libft.h"

void *ft_memcpy(void *dest, const void * src, size_t n)
{
    char *ptr;
    const char *ptrs;
    size_t i;

    i = 0;
    ptr = dest;
    ptrs = src;
    while (i < n)
    {
        *(ptr + i) = *(ptrs + i);
        i++;
    }
    return(dest);
}
/*
int main()
{
    char str1[] = "Geeks";
    char str2[] = "Quiz";
 
    puts("str1 before memcpy ");
    puts(str1);
 
    // Copies contents of str2 to str1
    ft_memcpy(str1, str2, sizeof(str2));
 
    puts("\nstr1 after memcpy ");
    puts(str1);
 
    return 0;
}
*/
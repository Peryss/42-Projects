#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t i;
    char *ptr;

    i = 0;
    ptr = (char *) src;
    if (dst == NULL)
        return (0);
    if (size == 0)
        return (ft_strlen(ptr));
    while (i < size - 1 && ptr[i] != '\0')
    {
        dst[i] = ptr[i];
        i++;
    }
    dst[i] = '\0';
    return (ft_strlen(ptr));
}
/*
int main() {
    // Test the ft_strlcpy function
    char src[] = "Hello, world!";
    char dst[20];
    size_t size = 10;

    int result = ft_strlcpy(dst, src, size);
    
    printf("Result: %d\n", result);
    printf("Copied string: %s\n", dst);
    
    return 0;
}
*/
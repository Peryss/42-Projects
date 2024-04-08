#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t i;
    size_t j;
    size_t res;
    int nt;

    i = 0;
    j = 0;
    res = ft_strlen(dst) + ft_strlen((char *)src);
    if (size == 0)
        return (res);
    while (dst[i] != '\0' && i < size)
        i++;
    if (i < size)
        nt = 1;
    while (src[j] != '\0' && i < size - 1)
    {
        dst[i] = src[j];
        i++;
        j++;
    }
    if (nt == 1)
        dst[i] = '\0';
    return (res);
}
/*
int main() {
    // Test the ft_strlcat function
    char dst[20] = "Hello, ";
    char src[] = "world!";
    size_t size = sizeof(dst);

    size_t result = ft_strlcat(dst, src, size);

    printf("Result: %zu\n", result);
    printf("Concatenated string: %s\n", dst);

    return 0;
}
*/
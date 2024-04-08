#include "libft.h"

void bzero(void *s, size_t n)
{
    char *ptr;
    size_t i;

    ptr = s;
    i = 0;
    while (i < n)
    {
        ptr[i] = 0;
        i++;
    }
}
/*
int main() {
    // Test the bzero function
    char buffer[10] = "abcdefghi";
    printf("Before bzero: %s\n", buffer);
    
    bzero(buffer, 10);
    
    printf("After bzero: %s\n", buffer);
    
    return 0;
}*/
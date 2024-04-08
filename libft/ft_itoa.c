#include <stdlib.h>
#include <stdio.h>

// malloc missin, have to change it

int     ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

void    ft_strrev(char *str)
{
    int     i;
    int     j;
    char    t;

    i = 0;
    j = ft_strlen(str);
    while(i < j - 1)
    {
        t = str[i];
        str[i] = str[j - 1];
        str[j - 1] = t;
        i++;
        j--;
    }
}

char    *ft_itoa(int n, char *str)
{
    int     i;
    char    c;

    i = 0;
    if (n <= 0)
    {
        str[i] = '-';
        if (n == 0)
            str[i] = '0';
        n = n * -1;
        i++;
    }
    while (n > 0)
    {
        c = (n % 10) + 48;
        n = n / 10;
        str[i] = c;
        i++;
    }
    str[i] = '\0';
    i = 0;
    if (str[0] == '-')
        i = 1;
    ft_strrev(str + i);
    return (str); 
}


int main (int argc, char **argv)
{
    char str[15];
    (void)argc;
    printf("The string: %s\n", ft_itoa(atoi(argv[1]), str));
    return (0);
}
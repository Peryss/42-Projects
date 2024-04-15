#include "./includes/ft_printf.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int x;
	char *str = "char: %c, string: %s, int: %d, pointer: %p, hexup: %X, hexdown: %x, uns: %u %\n";
	char *s = "hello";
	int i = INT_MIN;
	unsigned int u = 0;

	
	x = printf(str, s[0], s, i, s, i, i, u);
	printf("Printf return: %d\n\n", x);

	x = ft_printf(str, s[0], s, i, s, i, i, u);
	ft_printf("Ft_printf return: %d\n\n", x);
	return (0);
}
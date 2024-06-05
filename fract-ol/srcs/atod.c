#include "../include/fractal.h"

int		wrong_for_julia(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] != '.')
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

double	atod(char *str)
{
	int		i;
	int		t;
	int		sign;
	double	x;
	double	temp;

	i = 0;
	x = 0;
	t = 10;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] != '.')
	{
		x = x * 10 + str[i] - 48;
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] != '\0')
	{
		temp = str[i] - 48;
		x = x + temp/t;
		t *= 10;
		i++;
	}
	return (x * sign);
}

/*
#include <stdio.h>
int main()
{
	char str[]="123";
	
	printf("double: %f\n", atod(str));
	return 0;
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:30:33 by pvass             #+#    #+#             */
/*   Updated: 2024/06/12 16:34:40 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

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
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] != '.')
		x = x * 10 + str[i++] - 48;
	i++;
	while (str[i - 1] != '\0' && str[i] != '\0')
	{
		temp = str[i++] - 48;
		x = x + temp / t;
		t *= 10;
	}
	return (x * sign);
}

/* #include <stdio.h>
int main()
{
	char str[]="-123.";
	
	printf("double: %f\n", atod(str));
	return 0;
} */
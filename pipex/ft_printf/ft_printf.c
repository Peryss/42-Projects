/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:25:36 by pvass             #+#    #+#             */
/*   Updated: 2024/04/16 16:42:37 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

static int	ft_print_spec(va_list arg, char c)
{
	int	res;

	res = 0;
	if (c == 'd' || c == 'i')
		res = ft_putnbr2(va_arg(arg, int));
	if (c == 'p')
		res = ft_putpointer(va_arg(arg, uintptr_t));
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(arg, int), 1);
		res = 1;
	}
	if (c == 's')
		res = ft_putstr2(va_arg(arg, char *));
	if (c == 'u')
		res = ft_putunsigned(va_arg(arg, unsigned int));
	if (c == 'x' || c == 'X')
		res = ft_hex(va_arg(arg, long long), c);
	if (c == '%')
	{
		ft_putchar_fd ('%', 1);
		res = 1;
	}
	return (res);
}

static int	solve(const char *str, va_list arg)
{
	size_t	i;
	int		res;

	res = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && ft_strchr("cspiduxX%", str[i + 1]) != NULL)
		{
			res += ft_print_spec (arg, str[i + 1]);
			i = i + 2;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			i++;
			res++;
		}
	}
	return (res);
}

int	ft_printf(const char *format, ...)
{
	int		res;
	va_list	arg;

	if (format == NULL)
		return (-1);
	res = 0;
	va_start(arg, format);
	res = solve(format, arg);
	va_end (arg);
	return (res);
}

/* #include "./includes/ft_printf.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int x;
	char *str = "char: %c, string: %s, int: %d, pointer: %p, 
	hexup: %X, hexdown: %x, uns: %u %% %t\n";
	//char 	*str2 = "%a %b %c %d %e %f %g %h %i %j %k %l %m %n %o %p 
	%q %r %s %t %u %v %w %a %y %z %0 %1 %2 %3\n";
	char *s = "hello";
	int i = INT_MAX;
	unsigned int u = 1;

	x = printf(NULL);
	printf("%d\n", x);

	x = ft_printf(NULL);
	ft_printf("%d\n", x);

	//ft_printf("hello %i", 12);
	//printf("%s %s\n\n", s);
	
	x = printf(str, s[0], s, i, s, i, i, u, s, u);
	printf("Printf return: %d\n\n", x);

	x = ft_printf(str, s[0], s, i, s, i, i, u);
	ft_printf("Ft_printf return: %d\n\n", x);

	x = printf(str, s[0], s, i, s, i, i, u);
	printf("Printf return: %d\n\n", x);

	x = ft_printf(str, s[0], s, i, s, i, i, u);
	ft_printf("Ft_printf return: %d\n\n", x);
	
	x = ft_printf(str2, s);
	x = printf(str2, s);
	return (0);
} */
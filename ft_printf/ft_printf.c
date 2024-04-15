/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:25:36 by pvass             #+#    #+#             */
/*   Updated: 2024/04/15 19:12:38 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "./includes/libft.h"
#include "./includes/ft_printf.h"

/*SOLVE FOR "%gs %:"*/


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
		if (str[i] == '%')
		{
			res += ft_print_spec (arg, str[i + 1]);
			i += 2;
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

	res = 0;
	va_start(arg, format);
	res = solve(format, arg);
	va_end (arg);
	return (res);
}

/* #include <limits.h>
#include <stdlib.h>

int main()
{
	int x;
	
	x = printf(" NULL %s NULL ", (char *)NULL);
	printf("Printf return: %d\n\n", x);
	return (0);
} */
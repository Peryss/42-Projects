/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:25:36 by pvass             #+#    #+#             */
/*   Updated: 2024/04/13 20:42:43 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdarg.h>
#include "libft.h"

int	ft_putpointer (unsigned long long ptr);

int	ft_putunsigned (unsigned int nbr);

int	ft_hex (long long nbr, char c);

int	ft_putnbr2(int nbr);

int ft_putstr2(char *ptr);

static int  count_w(const char *format)
{
    int i;
    int count;

	count = 0;
    i = 0;
    while (format[i] != '\0')
    {
        if(format[i] == '%')
			count++;
		i++;
    }
	return (count);
}

static int	ft_print_spec(va_list arg, char c)
{
	int	res = 0;

	if (c == 'd' || c == 'i')
		res = ft_putnbr2(va_arg(arg, int));
	if (c == 'p')
		res = ft_putpointer(va_arg(arg, unsigned long long));
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
		ft_putchar_fd ('%', 1);
	return (res);
}

static int	solve(const char *str, va_list arg, int wc)
{
	size_t	i;
	int res;

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



int ft_printf(const char *format, ...)
{
	int		res;
    int		wc;
	va_list	arg;
	
    wc = count_w(format);
	va_start(arg, format);
	res = solve(format, arg, wc);
	va_end (arg);
	return (res);
}


#include <stdio.h>
int main()
{
	int x;
	
	x = ft_printf("This is the pointer: %%d\n", 15);
	ft_printf("ft_printf return: %d\n", x);
	return (0);
}
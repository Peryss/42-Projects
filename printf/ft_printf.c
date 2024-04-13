
#include <stdarg.h>
#include "libft.h"

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

static void	solve(const char *str, t_list arg, int wc)
{
	size_t	i;

	i = 0;
}



int ft_printf(const char *format, ...)
{
    int wc;
	va_list	*arg;

    wc = count_w(format);
	va_start(arg, wc);
	solve(format, arg, wc);
	va_end (arg);


}
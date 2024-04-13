#include "libft.h"


static void	ft_puthexup(unsigned long long nbr)
{
	if (nbr >= 16)
	{
		ft_puthexup(nbr / 16);
		ft_puthexup(nbr % 16);
	}
	else 
	{
		if (nbr <= 9)
			ft_putchar_fd(nbr + '0', 1);
		else
			ft_putchar_fd(nbr - 10 + 'A', 1);
	}
}

static void	ft_puthexdown(unsigned long long nbr)
{
	if (nbr >= 16)
	{
		ft_puthexdown(nbr / 16);
		ft_puthexdown(nbr % 16);
	}
	else 
	{
		if (nbr <= 9)
			ft_putchar_fd(nbr + '0', 1);
		else
			ft_putchar_fd(nbr - 10 + 'a', 1);
	}
}

int	ft_hex (long long nbr, char c)
{
	int i;

	i = 0;
	if (c == 'X')
		ft_puthexup(nbr);
	if (c == 'x')
		ft_puthexdown(nbr);
	while (nbr > 0)
	{
		nbr = nbr / 16;
		i++;
	}
	return (i);
}

int main ()
{
	ft_hex(123456789, 'x');
	return (0);
}
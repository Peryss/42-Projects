#include "libft.h"

static void	ft_putun(unsigned int nbr)
{
	if (nbr > 0)
	{
		ft_putun(nbr / 10);
		ft_putun(nbr % 10);
	}
	else 
	{
		ft_putchar_fd(nbr + '0', 1);
	}
}

int	ft_putunsigned (unsigned int nbr)
{
	int i;

	i = 0;
	ft_putun(nbr);
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

int main()
{
	ft_putun
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexupdown.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:25:19 by pvass             #+#    #+#             */
/*   Updated: 2024/04/16 16:39:27 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

static void	ft_puthexup(unsigned int nbr)
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

static void	ft_puthexdown(unsigned int nbr)
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

int	ft_hex(unsigned int nbr, char c)
{
	int	i;

	i = 0;
	if (c == 'X')
		ft_puthexup(nbr);
	if (c == 'x')
		ft_puthexdown(nbr);
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / 16;
		i++;
	}
	return (i);
}

/* int main ()
{
	ft_hex(123456789, 'x');
	return (0);
} */
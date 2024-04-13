/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:25:45 by pvass             #+#    #+#             */
/*   Updated: 2024/04/13 20:25:46 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

static void	ft_putun(unsigned int nbr)
{
	if (nbr >= 10)
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

/* int main()
{
	ft_putunsigned(4568);
	return (0);
} */
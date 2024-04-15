/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countres.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:25:14 by pvass             #+#    #+#             */
/*   Updated: 2024/04/15 18:54:54 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "./includes/ft_printf.h"

int	ft_putnbr2(int nbr)
{
	int		i;

	i = 0;
	ft_putnbr_fd(nbr, 1);
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		i++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

int	ft_putstr2(char *ptr)
{
	if (ptr == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd(ptr, 1);
	return (ft_strlen(ptr));
}

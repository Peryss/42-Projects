/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countres.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:25:14 by pvass             #+#    #+#             */
/*   Updated: 2024/04/13 20:33:40 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr2(int nbr)
{
	int		res;
	char	*ptr;

	res = 0;
	ft_putnbr_fd(nbr, 1);
	ptr = ft_itoa(nbr);
	res = ft_strlen(ptr);
	free (ptr);
	return (res);
}

int ft_putstr2(char *ptr)
{
	ft_putstr_fd(ptr, 1);
	return (ft_strlen(ptr));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:37:22 by pvass             #+#    #+#             */
/*   Updated: 2024/04/09 15:45:37 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_s(int n)
{
	int	s;
	int	m;

	m = n;
	if (m > 0)
	{
		s = 1;
	}
	if (m < 0)
	{
		s = -1;
	}
	if (m == -2147483648)
	{
		s = 0;
	}
	return (s);
}

static void	dec(int nb, char *str)
{
	char	*ptr;

	ptr = str;
	while (nb / 10 > 0)
	{
		*ptr = nb % 10 + 48;
		ptr++;
		nb = nb / 10;
	}
	*ptr = nb + 48;
	*(ptr + 1) = '\0';
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c[12];
	char	*str;
	int		i;

	str = &c[0];
	if (check_s(n) == 0)
	{
		write(fd, "-2147483648", 11);
	}
	else
	{
		if (check_s(n) == -1)
		{
			write(fd, "-", 1);
			n = n * -1;
		}
		dec (n, str);
		i = ft_strlen(str) - 1;
		while (i >= 0)
		{
			write(fd, &c[i], 1);
			i--;
		}
	}
}

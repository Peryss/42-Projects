/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:37:22 by pvass             #+#    #+#             */
/*   Updated: 2024/04/15 18:55:34 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	check_s(int n)
{
	int	s;
	int	m;

	m = n;
	s = 1;
	if (m >= 0)
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
	char	*str;
	int		i;

	str = (char *) malloc (12);
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
			write(fd, str + i, 1);
			i--;
		}
	}
	free (str);
}

/* int	main(void)
{
	int num = 123456789;
	ft_putnbr_fd(num, 1); // Output the number to standard output
	return (0);
} */
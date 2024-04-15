/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:25:59 by pvass             #+#    #+#             */
/*   Updated: 2024/04/15 17:47:01 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "./includes/ft_printf.h"

static void	ft_putp(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		ft_putp(ptr / 16);
		ft_putp(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd(ptr + '0', 1);
		else
			ft_putchar_fd(ptr - 10 + 'a', 1);
	}
}

static int	ptr_len(uintptr_t ptr)
{
	int		i;

	i = 0;
	while (ptr > 0)
	{
		ptr = ptr / 16;
		i++;
	}
	return (i);
}

int	ft_putpointer(uintptr_t ptr)
{
	int	len;

	len = 2;
	if (ptr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	if (ptr == 0)
		return (ft_putchar_fd('0', 1), 3);
	ft_putp(ptr);
	return (len + ptr_len(ptr));
}

/*
int main ()
{
	char *p = "hellobello";

	ft_putpointer(123215469846);
	return (0);
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:54:30 by pvass             #+#    #+#             */
/*   Updated: 2024/12/12 14:20:52 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"



int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nb;

	nb = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	nb = nb * sign;
	if (nb != 0)
		return (nb);
	return (0);
}

static char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char			*temp;
	unsigned int	j;

	j = n;
	temp = dest;
	while (j > 0 && *src != '\0')
	{
		*temp = *src;
		temp++;
		src++;
		j--;
	}
	while (j > 0)
	{
		*temp = '\0';
		temp++;
		j--;
	}
	return (dest);
}

static void	ft_strrev(char *str)
{
	int		i;
	int		j;
	char	t;

	i = 0;
	if (str[0] == '-')
		str++;
	j = ft_strlen(str);
	while (i < j - 1)
	{
		t = str[i];
		str[i] = str[j - 1];
		str[j - 1] = t;
		i++;
		j--;
	}
}

static char	*allo(int n)
{
	int		i;
	char	*ptr;

	i = 0;
	if (n == 0)
		i = 1;
	if (n == -2147483648)
	{
		ptr = ft_calloc(12, 1);
		if (ptr == NULL)
			return (ptr);
		ptr = ft_strncpy(ptr, "-2147483648", 12);
		return (ptr);
	}
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	ptr = ft_calloc(i + 1, 1);
	return (ptr);
}

char	*ft_itoa(int n)
{
	int		i;
	char	c;
	char	*str;

	str = allo(n);
	if (str == NULL || ft_strncmp(str, "-2147483648", 12) == 0)
		return (str);
	i = 0;
	if (n <= 0)
	{
		str[i] = '-';
		if (n == 0)
			str[i] = '0';
		n = n * -1;
		i++;
	}
	while (n > 0)
	{
		c = (n % 10) + 48;
		n = n / 10;
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (ft_strrev(str), str);
}

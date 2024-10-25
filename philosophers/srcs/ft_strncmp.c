/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:37:19 by pvass             #+#    #+#             */
/*   Updated: 2024/10/25 15:09:03 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = n;
	while (i > 0 && (*str1 != '\0' || *str2 != '\0'))
	{
		if (*str1 != *str2)
			return ((unsigned char)*str1 - (unsigned char)*str2);
		i--;
		str1++;
		str2++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "Error: gettimeofday()\n", 23);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (nitems == 0 || size == 0)
		return (malloc(0));
	if (size > SIZE_MAX / nitems)
		return (NULL);
	ptr = (char *) malloc (nitems * size);
	if (ptr == NULL)
		return (NULL);
	while (i < nitems * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

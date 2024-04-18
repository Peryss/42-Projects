/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:19:55 by pvass             #+#    #+#             */
/*   Updated: 2024/04/18 17:12:00 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (char) c)
		return ((char *)str + i);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*ptr2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ptr = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ptr == NULL)
		return (NULL);
	ptr = ft_strncpy(ptr, (char *)s1, ft_strlen(s1));
	ptr2 = ptr + ft_strlen(s1);
	ptr2 = ft_strncpy(ptr2, (char *)s2, ft_strlen(s2));
	ptr[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:31:06 by pvass             #+#    #+#             */
/*   Updated: 2024/04/13 18:11:32 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	nr;

	nr = len + 1;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) > start)
	{
		if (ft_strlen(s + start) <= len)
			nr = ft_strlen(s + start) + 1;
		ptr = (char *) malloc (nr);
		if (ptr == NULL)
			return (NULL);
		ptr = ft_strncpy(ptr, (char *)s + start, nr);
		ptr[nr - 1] = '\0';
	}
	else
	{
		ptr = (char *) malloc (1);
		if (ptr == NULL)
			return (NULL);
		ptr[0] = '\0';
	}
	return (ptr);
}

/*  #include <stdio.h>
int main()
{
	char *s = "0123456789";
	printf("%s\n", ft_substr(s, 9, 10));
	printf("%d\n", ft_strlen(ft_substr(s, 9, 10)));
	return (0);
} */

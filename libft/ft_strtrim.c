/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:52:13 by pvass             #+#    #+#             */
/*   Updated: 2024/04/13 18:58:46 by pvass            ###   ########.fr       */
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

static size_t	ft_endcut(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (set[i] != '\0' && len > 0)
	{
		if (set[i] == s1[len - 1])
		{
			len--;
			i = -1;
		}
		i++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	size_t	len;

	j = 0;
	i = 0;
	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *) s1);
	while (set[i] != '\0')
	{
		if (set[i] == s1[j])
		{
			j++;
			i = -1;
		}
		i++;
	}
	len = ft_endcut(s1 + j, set);
	ptr = (char *) malloc (len + 1);
	if (ptr == NULL)
		return (NULL);
	return (ptr = ft_strncpy(ptr, (char *)s1 + j, len), ptr[len] = '\0', ptr);
}

/*
#include <stdio.h>
int main()
{
	char *s1 = "   a  a   a a bba  ";
    //char *s2 = "Hello \t  Please\n Trim me !";
    char *ret = ft_strtrim(s1, " ab");

	printf("Trimmed string: %s\n", ret);
	return (0);
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:20:32 by pvass             #+#    #+#             */
/*   Updated: 2024/04/09 13:48:59 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen2(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

static int	sep(char c, char charset)
{
	if (charset == c)
		return (1);
	return (0);
}

static char	*ft_strdup2(char *src, char charset)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *) malloc(ft_strlen2(src, charset) + 1);
	if (ptr == NULL)
		return (NULL);
	while (*src != '\0' && sep(*src, charset) == 0)
	{
		ptr[i] = *src;
		src++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static int	count_words(char *str, char s)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (sep(str[i], s) == 0 && (sep(str[i - 1], s) == 1 || i == 0))
			j++;
		i++;
	}
	return (j + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	j = 0;
	i = 0;
	tab = (char **)malloc(sizeof(char *) * count_words((char *)s, c));
	if (tab == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (sep(s[i], c) == 0 && (sep(s[i - 1], c) == 1 || i == 0))
		{
			tab[j] = ft_strdup2((char *)s + i, c);
			i++;
			j++;
		}
		i++;
	}
	tab[j] = 0;
	return (tab);
}

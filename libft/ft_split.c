/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:20:32 by pvass             #+#    #+#             */
/*   Updated: 2024/04/11 16:15:43 by pvass            ###   ########.fr       */
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

static char	*ft_strdup2(char *src, char charset)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *) malloc(ft_strlen2(src, charset) + 1);
	if (ptr == NULL)
		return (NULL);
	while (*src != '\0' && *src != charset)
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
		if (str[i] != s && (i == 0 || str[i - 1] == s))
			j++;
		i++;
	}
	return (j + 1);
}

static void	ft_free_all(char **tab, int i)
{
	int	j;

	j = 0;
	while (i > j)
	{
		free (tab[j]);
		j++;
	}
	free (tab);
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
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			tab[j] = ft_strdup2((char *)s + i, c);
			if (tab[j] == NULL)
				return (ft_free_all(tab, j), NULL);
			i++;
			j++;
		}
		i++;
	}
	tab[j] = 0;
	return (tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:34:52 by pvass             #+#    #+#             */
/*   Updated: 2024/04/08 19:29:27 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	res(char *dst, const char *src, size_t size)
{
	size_t	res;

	res = ft_strlen (src) + ft_strlen(dst);
	if (size == 0)
		return (ft_strlen(src));
	if ((int) size < ft_strlen(dst))
		res = size + ft_strlen(src);
	if ((int) size < 0)
		res = ft_strlen(src) + ft_strlen(dst);
	return (res);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	re;
	int		nt;

	i = 0;
	j = 0;
	re = res(dst, src, size);
	if (size == 0)
		return (re);
	while (dst[i] != '\0')
		i++;
	if (i < size)
		nt = 1;
	while (src[j] != '\0' && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (nt == 1)
		dst[i] = '\0';
	return (re);
}

/*
#include <stdio.h>
int main ()
{
	char dest[30]; memset(dest, 0, 30);
	char * src = (char *)"AAAAAAAAA";
	memset(dest, 'C', 5);
	printf ("%s\n", dest);
	printf("%zu\n", ft_strlcat(dest, src, -1)); 
	printf ("%s\n", dest);
	//&& !strcmp(dest, "CCCCCAAAAAAAAA");
	memset(dest, 0, 30); 
	memset(dest, '1', 10);
	printf ("%s\n", dest);
	printf("%d\n", ft_strlcat(dest, src, 5) == strlen(src) + 5);
	printf ("%s\n", dest);
	return (0);
}
*/
/*
int main() {
    // Test the ft_strlcat function
    char dst[20] = "Hello, ";
    char src[] = "world!";
    size_t size = sizeof(dst);

    size_t result = ft_strlcat(dst, src, size);

    printf("Result: %zu\n", result);
    printf("Concatenated string: %s\n", dst);

    return 0;
}
*/
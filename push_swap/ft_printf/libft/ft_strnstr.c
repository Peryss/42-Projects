/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:38:06 by pvass             #+#    #+#             */
/*   Updated: 2024/04/08 13:40:54 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big,	const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (little[j] != '\0' && i + j < len
			&& ft_strncmp(big + i + j, little + j, 1) == 0)
			j++;
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int main() {
    const char *big = "Hello, world!";
    const char *little = "lo";
    size_t len = 6; // Length of the string "Hello, world!"

    char *result = ft_strnstr(big, little, len);

    if (result != NULL) {
        printf("Substring found at index: %lld\n", result - big);
        printf("Substring: %s\n", result);
    } else {
        printf("Substring not found.\n");
    }

    return 0;
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:31:14 by pvass             #+#    #+#             */
/*   Updated: 2024/04/08 17:25:18 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*ptr;
	const char	*ptrs;
	size_t		i;

	i = 0;
	if (src == NULL && dest == NULL)
		return (NULL);
	ptr = dest;
	ptrs = src;
	while (i < n)
	{
		*(ptr + i) = *(ptrs + i);
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
int main()
{
    char str1[] = "Geeks";
    char str2[] = "Quiz";
 
    puts("str1 before memcpy ");
    puts(str1);
 
    // Copies contents of str2 to str1
    ft_memcpy(str1, str2, sizeof(str2));
	ft_memcpy(((void*)0), ((void*)0), 3);
    puts("\nstr1 after memcpy ");
    puts(str1);
 
    return 0;
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:32:14 by pvass             #+#    #+#             */
/*   Updated: 2024/04/08 17:46:37 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memcpy_rev(void *dest, const void *src, size_t n)
{
	char		*ptr;
	const char	*ptrs;

	ptr = dest;
	ptrs = src;
	if (src == NULL && dest == NULL)
		return (NULL);
	while (n > 0)
	{
		*(ptr + n - 1) = *(ptrs + n - 1);
		n--;
	}
	return (dest);
}

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char		*ptr1;
	const char	*ptr2;

	ptr1 = str1;
	ptr2 = str2;
	if (str2 < str1)
		ft_memcpy_rev(ptr1, ptr2, n);
	else
		ft_memcpy(ptr1, ptr2, n);
	return (ptr1);
}

/*
#include <stdio.h> 

int main() 
{ 
	char str1[] = "Geeks"; // Array of size 100 
	char str2[] = "Quiz"; // Array of size 5 

	puts("str1 before memmove "); 
	puts(str1); 
 
	ft_memmove(str1, str2, sizeof(str2)); 

	puts("\nstr1 after memmove "); 
	puts(str1); 

	return 0; 
}
*/
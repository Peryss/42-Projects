/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:50:17 by pvass             #+#    #+#             */
/*   Updated: 2024/04/09 19:55:38 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	char	*temp;

	temp = dest;
	while (*src != '\0')
	{
		*temp = *src;
		src++;
		temp++;
	}
	*temp = *src;
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*ptr;

	ptr = (char *) malloc(ft_strlen(src) + 1);
	if (ptr == NULL)
		return (NULL);
	ptr = ft_strcpy(ptr, src);
	return (ptr);
}
/*
#include <stdio.h>
int main() {
   char *str = "Helloworld";
   char *result;
   result = ft_strdup(str);
   printf("The string : %s", result);
   return 0;
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:37:19 by pvass             #+#    #+#             */
/*   Updated: 2024/04/08 17:38:56 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = n;
	while (i > 0 && (*str1 != '\0' || *str2 != '\0'))
	{
		if (*str1 != *str2)
			return ((unsigned char)*str1 - (unsigned char)*str2);
		i--;
		str1++;
		str2++;
	}
	return (0);
}
/*
#include <stdio.h>
int main () {
   char str1[15];
   char str2[15];
   int ret;

   strcpy(str1, "\200");
   strcpy(str2, "\0");

   ret = ft_strncmp(str1, str2, 1);

   printf("return value: %d\n", ret);
   printf("should return: %d\n", strncmp(str1, str2, 1));
   return(0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:41:06 by pvass             #+#    #+#             */
/*   Updated: 2024/04/13 18:09:42 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i + 1] == (char) c)
		return (str + i + 1);
	while (i >= 0)
	{
		if (str[i] == (char) c)
			return (str + i);
		i--;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main () {
   char str[] = "https://www.tutorialspoint.com";
   char ch = '.';
   char *ret;

   ret = ft_strrchr(str, ch);

   printf("String after |%c| is - |%s|\n", ch, ret);
   
   return(0);
}
*/

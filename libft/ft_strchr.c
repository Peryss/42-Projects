/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:34:22 by pvass             #+#    #+#             */
/*   Updated: 2024/04/08 18:02:47 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;

	i = 0;
	if (c > 127)
		c = c % 128;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == c)
		return ((char *)str + i);
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int main () {
    char str[] = "teste";
    char ch = 'e';
    char *ret;

   ret = ft_strchr(str, ch);

   printf("String after |%c| ,%p; is - |%s| ,%p\n", ch, &ch, ret, &ret);
   
   return(0);
}
*/
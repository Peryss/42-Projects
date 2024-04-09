/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:53:24 by pvass             #+#    #+#             */
/*   Updated: 2024/04/08 18:20:38 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
/*
int main() {
    // Test the bzero function
    char buffer[10] = "abcdefghi";
    printf("Before bzero: %s\n", buffer);
    
    bzero(buffer, 10);
    
    printf("After bzero: %s\n", buffer);
    
    return 0;
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:42:05 by pvass             #+#    #+#             */
/*   Updated: 2024/04/08 13:42:07 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int ch)
{
	if (ft_isalpha(ch) == 2)
		ch = ch - 32;
	return (ch);
}
/*
int main()
{
    int a = 'a';
    int b = '+';
    
    printf ("a: %c\n", (char) ft_toupper(a));
    printf ("+: %c\n", (char) ft_toupper(b));
    return (0);
}
*/
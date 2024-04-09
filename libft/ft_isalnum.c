/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:23:05 by pvass             #+#    #+#             */
/*   Updated: 2024/04/08 13:25:55 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int arg)
{
	if (ft_isalpha(arg) != 0 || ft_isdigit(arg) != 0)
		return (1);
	return (0);
}
/*
int main()
{
    int i = '1';
    int j = 'a';
    int x = '+';

    printf("1: %d\n", ft_isalnum(i));
    printf("a: %d\n", ft_isalnum(j));
    printf("+: %d\n", ft_isalnum(x));
    return (0);
}
*/
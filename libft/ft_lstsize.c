/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:27:44 by pvass             #+#    #+#             */
/*   Updated: 2024/04/13 17:27:05 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	count;
	t_list	*i;

	if (lst == NULL)
		return (0);
	i = lst;
	count = 0;
	while (i != NULL)
	{
		i = i -> next;
		count++;
	}
	return (count);
}

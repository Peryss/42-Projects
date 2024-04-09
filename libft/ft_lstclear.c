/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:19:36 by pvass             #+#    #+#             */
/*   Updated: 2024/04/09 17:28:09 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*i;
	t_list	*temp;

	i = *lst;
	if (*lst == NULL)
		return ;
	while (i != NULL)
	{
		temp = i -> next;
		ft_lstdelone(i, del);
		i = temp;
	}
	*lst = NULL;
}

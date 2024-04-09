/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:11:07 by pvass             #+#    #+#             */
/*   Updated: 2024/04/09 19:51:03 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*temp;
	t_list	*save;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	save = ft_lstnew(f(lst -> content));
	if (save == NULL)
		return (ft_lstclear(&save, del), NULL);
	new_lst = save;
	lst = lst -> next;
	while (lst != NULL)
	{
		temp = ft_lstnew(f(lst -> content));
		if (temp == NULL)
			return (ft_lstclear(&save, del), NULL);
		ft_lstadd_back(&new_lst, temp);
		lst = lst -> next;
	}
	return (save);
}

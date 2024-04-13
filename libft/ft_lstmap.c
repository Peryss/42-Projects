/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:11:07 by pvass             #+#    #+#             */
/*   Updated: 2024/04/11 16:28:49 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*temp;
	void	*t;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_lst = NULL;
	while (lst != NULL)
	{
		t = f(lst -> content);
		temp = ft_lstnew(t);
		if (temp == NULL)
			return (ft_lstclear(&new_lst, del), del(t), NULL);
		ft_lstadd_back(&new_lst, temp);
		lst = lst -> next;
	}
	return (new_lst);
}

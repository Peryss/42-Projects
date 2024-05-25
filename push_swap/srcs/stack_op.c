/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:43:24 by pvass             #+#    #+#             */
/*   Updated: 2024/05/18 15:10:25 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacksize(t_stack *lst)
{
	size_t	count;
	t_stack	*i;

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

void	ft_stackadd_bot(t_stack **lst, t_stack *new)
{
	t_stack	*i;

	i = *lst;
	if (new == NULL || lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (i -> next != NULL)
	{
		i = i -> next;
	}
	i -> next = new;
}

void	ft_stackadd_top(t_stack **lst, t_stack *new)
{
	if (lst == NULL)
		return ;
	new -> next = *lst;
	*lst = new;
}

t_stack	*ft_stacklast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}

t_stack	*ft_stacknew(int content)
{
	t_stack	*new;

	new = (t_stack *) malloc (sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new -> nr = content;
	new -> next = NULL;
	return (new);
}

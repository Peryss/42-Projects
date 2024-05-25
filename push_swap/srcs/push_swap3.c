/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:31:40 by pvass             #+#    #+#             */
/*   Updated: 2024/05/18 15:22:50 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (a == NULL || *a == NULL || (*a)-> next == NULL)
		return ;
	temp = ft_stacklast(*a);
	temp2 = *a;
	while (temp2 -> next != temp)
		temp2 = temp2 -> next;
	temp2 -> next = NULL;
	ft_stackadd_top(a, temp);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (b == NULL || *b == NULL || (*b)-> next == NULL)
		return ;
	temp = ft_stacklast(*b);
	temp2 = *b;
	while (temp2 -> next != temp)
		temp2 = temp2 -> next;
	temp2 -> next = NULL;
	ft_stackadd_top(b, temp);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (a == NULL || *a == NULL || b == NULL || *b == NULL)
		return ;
	if (ft_stacksize(*a) > 1)
	{
		temp = ft_stacklast(*a);
		temp2 = *a;
		while (temp2 -> next != temp)
			temp2 = temp2 -> next;
		temp2 -> next = NULL;
		ft_stackadd_top(a, temp);
	}
	if (ft_stacksize(*b) > 1)
	{
		temp = ft_stacklast(*b);
		temp2 = *b;
		while (temp2 -> next != temp)
			temp2 = temp2 -> next;
		temp2 -> next = NULL;
		ft_stackadd_top(b, temp);
	}
	ft_printf("rrr\n");
}

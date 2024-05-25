/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:03:10 by pvass             #+#    #+#             */
/*   Updated: 2024/05/18 15:18:42 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (a == NULL || *a == NULL)
		return ;
	if (ft_stacksize(*a) < 2)
		return ;
	temp = *a;
	temp2 = temp -> next;
	temp -> next = temp2 -> next;
	temp2 -> next = temp;
	*a = temp2;
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (b == NULL || *b == NULL)
		return ;
	if (ft_stacksize(*b) < 2)
		return ;
	temp = *b;
	temp2 = temp -> next;
	temp -> next = temp2 -> next;
	temp2 -> next = temp;
	*b = temp2;
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (a == NULL || *a == NULL)
		return ;
	if (ft_stacksize(*a) < 2)
		return ;
	if (b == NULL || *b == NULL)
		return ;
	if (ft_stacksize(*b) < 2)
		return ;
	temp = *a;
	temp2 = temp -> next;
	temp -> next = temp2 -> next;
	temp2 -> next = temp;
	*a = temp2;
	temp = *b;
	temp2 = temp -> next;
	temp -> next = temp2 -> next;
	temp2 -> next = temp;
	*b = temp2;
	ft_printf("ss\n");
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (b == NULL || *b == NULL)
		return ;
	temp = *b;
	*b = temp -> next;
	ft_stackadd_top(a, temp);
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (a == NULL || *a == NULL)
		return ;
	temp = *a;
	*a = temp -> next;
	ft_stackadd_top(b, temp);
	ft_printf("pb\n");
}

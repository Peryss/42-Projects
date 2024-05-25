/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:30:40 by pvass             #+#    #+#             */
/*   Updated: 2024/05/18 17:34:07 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*temp;

	if (a == NULL || *a == NULL || (*a)-> next == NULL)
		return ;
	temp = *a;
	*a = temp -> next;
	temp -> next = NULL;
	ft_stackadd_bot(a, temp);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	t_stack	*temp;

	if (b == NULL || *b == NULL || (*b)-> next == NULL)
		return ;
	temp = *b;
	*b = temp -> next;
	temp -> next = NULL;
	ft_stackadd_bot(b, temp);
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (a == NULL || *a == NULL)
		return ;
	if (b == NULL || *b == NULL)
		return ;
	if (ft_stacksize(*a) > 1)
	{
		temp = *a;
		*a = temp -> next;
		temp -> next = NULL;
		ft_stackadd_bot(a, temp);
	}
	if (ft_stacksize(*b) > 1)
	{
		temp = *b;
		*b = temp -> next;
		temp -> next = NULL;
		ft_stackadd_bot(b, temp);
	}
	ft_printf("rr\n");
}

void	errormsg(void)
{
	ft_printf("Error\n");
}

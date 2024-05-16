/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:03:10 by pvass             #+#    #+#             */
/*   Updated: 2024/05/16 17:33:30 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack *temp;
	t_stack *temp2;

	if (a == NULL || *a == NULL)
		return ;
	if (ft_stacksize(*a) < 2)
		return;
	temp = *a;
	temp2 = temp -> next;
	temp -> next = temp2 -> next;
	temp2 -> next = temp;
	*a = temp2;
	printf("sa\n");
}

void	sb(t_stack **b)
{
	t_stack *temp;
	t_stack *temp2;

	if (b == NULL || *b == NULL)
		return ;
	if (ft_stacksize(*b) < 2)
		return;
	temp = *b;
	temp2 = temp -> next;
	temp -> next = temp2 -> next;
	temp2 -> next = temp;
	*b = temp2;
	printf("sb\n");
}

void 	ss(t_stack **a, t_stack **b)
{
	t_stack *temp;
	t_stack *temp2;

	if (a == NULL || *a == NULL)
		return ;
	if (ft_stacksize(*a) < 2)
		return;
	if (b == NULL || *b == NULL)
		return ;
	if (ft_stacksize(*b) < 2)
		return;
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
	printf("ss\n");
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack *temp;
	
	if (b == NULL || *b == NULL)
		return;
	temp = *b;
	*b = temp -> next;
	ft_stackadd_top(a, temp);
	printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack *temp;
	
	if (a == NULL || *a == NULL)
		return;
	temp = *a;
	*a = temp -> next;
	ft_stackadd_top(b, temp);
	printf("pb\n");
}

void	ra(t_stack **a)
{
	t_stack *temp;
	
	if (a == NULL ||*a == NULL || (*a) -> next == NULL)
		return ;
	temp = *a;
	*a = temp -> next;
	temp ->  next = NULL;
	ft_stackadd_bot(a, temp);
	printf("ra\n");
}

void	rb(t_stack **b)
{
	t_stack *temp;
	
	if (b == NULL ||*b == NULL || (*b) -> next == NULL)
		return ;
	temp = *b;
	*b = temp -> next;
	temp ->  next = NULL;
	ft_stackadd_bot(b, temp);
	printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	t_stack *temp;
	
	if (a == NULL ||*a == NULL)
		return ;
	if (b == NULL ||*b == NULL)
		return ;
	if(ft_stacksize (*a) > 1)
	{
		temp = *a;
		*a = temp -> next;
		temp ->  next = NULL;
		ft_stackadd_bot(a, temp);
	}
	if (ft_stacksize(*b) > 1)
	{
		temp = *b;
		*b = temp -> next;
		temp ->  next = NULL;
		ft_stackadd_bot(b, temp);
	}
	printf("rr\n");
}

void	rra(t_stack **a)
{
	t_stack *temp;
	t_stack	*temp2;

	if (a == NULL || *a == NULL || (*a) -> next == NULL)
		return ;
	temp = ft_stacklast(*a);
	temp2 = *a;
	while (temp2 -> next != temp)
		temp2 = temp2 -> next;
	temp2 -> next = NULL;
	ft_stackadd_top(a, temp);
	printf("rra\n");
}

void	rrb(t_stack **b)
{
	t_stack *temp;
	t_stack	*temp2;

	if (b == NULL || *b == NULL || (*b) -> next == NULL)
		return ;
	temp = ft_stacklast(*b);
	temp2 = *b;
	while (temp2 -> next != temp)
		temp2 = temp2 -> next;
	temp2 -> next = NULL;
	ft_stackadd_top(b, temp);
	printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	t_stack *temp;
	t_stack	*temp2;

	if (a == NULL || *a == NULL)
		return ;
	if (b == NULL || *b == NULL)
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
	printf("rrr\n");
}
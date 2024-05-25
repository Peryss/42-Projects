/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:41:37 by pvass             #+#    #+#             */
/*   Updated: 2024/05/25 14:03:08 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sorted_des(t_stack **b)
{
	t_stack	*temp;

	if (b == NULL)
		return (1);
	temp = *b;
	if (temp->nr == ft_stack_max(b))
		return (1);
	return (0);
}

void	right_order(t_stack **b)
{
	t_stack	*temp;
	int		count;
	int		i;

	temp = *b;
	count = 0;
	i = 0;
	if (*b == NULL)
		return ;
	while (temp->nr != ft_stack_min(b))
	{
		temp = temp->next;
		i++;
	}
	if (i < ft_stacksize(*b) - i)
		while (sorted_des(b) != 1)
			rb(b);
	else
		while (sorted_des(b) != 1)
			rrb(b);
}

void	sort3(t_stack **b)
{
	if ((*b)->nr < (*b)->next->nr && (*b)->nr < (*b)->next->next->nr)
		if ((*b)->next->nr < (*b)->next->next->nr)
			sb(b);
	if ((*b)->nr > (*b)->next->nr && (*b)->nr > (*b)->next->next->nr)
		if ((*b)->next->nr < (*b)->next->next->nr)
			sb(b);
	if ((*b)->nr < (*b)->next->nr && (*b)->nr > (*b)->next->next->nr)
		sb(b);
}

void	do_moves(t_move *move, t_stack **a, t_stack **b)
{
	while (move->rr-- > 0)
		rr(a, b);
	while (move->rrr-- > 0)
		rrr(a, b);
	while (move->ra-- > 0)
		ra(a);
	while (move->rra-- > 0)
		rra(a);
	while (move->rb-- > 0)
		rb(b);
	while (move->rrb-- > 0)
		rrb(b);
	pb(a, b);
}

void	free_stack(t_stack *a)
{
	t_stack	*temp;

	while (a != NULL)
	{
		temp = a -> next;
		free(a);
		a = temp;
	}
}

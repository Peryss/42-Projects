/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 09:48:35 by pvass             #+#    #+#             */
/*   Updated: 2024/05/25 14:36:23 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		min;

	if (*a == NULL)
		return (1);
	if (*b != NULL)
		return (0);
	min = (*a)->nr;
	temp = (*a)->next;
	while (temp != NULL)
	{
		if (min >= temp->nr)
		{
			pb(a, b);
			return (0);
		}
		min = temp->nr;
		temp = temp ->next;
	}
	return (1);
}

/* void	print_stack(t_stack *a)
{
	while (a != NULL)
	{
		ft_printf("%d\n", a->nr);
		a = a->next;
	}
} */

static void	sort3a(t_stack **a)
{
	if ((*a)->nr < (*a)->next->nr && (*a)->nr < (*a)->next->next->nr)
		if ((*a)->next->nr > (*a)->next->next->nr)
			return (rra(a), sa(a));
	if ((*a)->nr > (*a)->next->nr && (*a)->nr > (*a)->next->next->nr)
	{
		if ((*a)->next->nr < (*a)->next->next->nr)
			return (ra(a));
		if ((*a)->next->nr > (*a)->next->next->nr)
			return (ra(a), sa(a));
	}
	if ((*a)->nr < (*a)->next->nr && (*a)->nr > (*a)->next->next->nr)
		return (rra(a));
	if ((*a)->nr > (*a)->next->nr && (*a)->nr < (*a)->next->next->nr)
		return (sa(a));
}

static void	last_moves2(t_stack **a, t_stack **b, int y, int x)
{
	ra(a);
	ra(a);
	while ((*b) != NULL && (*b)->nr > y)
		pa(a, b);
	rra(a);
	while ((*b) != NULL && (*b)->nr > x)
		pa(a, b);
	rra(a);
	while ((*b) != NULL)
		pa(a, b);
}

void	last_moves(t_stack **a, t_stack **b)
{
	int	i;
	int	x;
	int	y;
	int	z;

	sort3a(a);
	x = (*a)->nr;
	y = (*a)->next->nr;
	z = (*a)->next->next->nr;
	i = 0;
	while ((*b) != NULL && (*b)->nr > z)
	{
		pa(a, b);
		i++;
	}
	while (i > 0)
	{
		ra(a);
		i--;
	}
	if ((*b) == NULL)
		return ;
	last_moves2(a, b, y, x);
}

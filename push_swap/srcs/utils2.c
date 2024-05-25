/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:36:09 by pvass             #+#    #+#             */
/*   Updated: 2024/05/18 15:31:16 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos_max(int max_b, t_stack **b)
{
	t_stack	*temp;
	int		pos;

	temp = *b;
	pos = 0;
	while (temp -> nr != max_b && temp != NULL)
	{
		pos++;
		temp = temp -> next;
	}
	return (pos);
}

int	get_pos_min(int min_b, t_stack **b)
{
	t_stack	*temp;
	int		pos;

	temp = *b;
	pos = 0;
	if (ft_stacklast(temp)->nr == min_b)
		return (pos);
	pos++;
	while (temp -> nr != min_b && temp != NULL)
	{
		pos++;
		temp = temp -> next;
	}
	return (pos);
}

int	get_pos(int nr, t_stack **b)
{
	t_stack	*temp;
	int		pos;

	temp = *b;
	pos = 0;
	if (nr > temp->nr && nr < ft_stacklast(temp)->nr)
		return (pos);
	while (temp != NULL && temp->next != NULL)
	{
		pos++;
		if (nr > temp->next->nr && nr < temp->nr)
			return (pos);
		temp = temp -> next;
	}
	return (pos);
}

int	place_in_b(t_stack *temp, t_stack **b, int pos_a)
{
	int		max_b;
	int		min_b;
	int		place;

	while (pos_a > 0)
	{
		temp = temp->next;
		pos_a--;
	}
	max_b = ft_stack_max(b);
	min_b = ft_stack_min(b);
	if (temp->nr > max_b)
		place = get_pos_max(max_b, b);
	else if (temp->nr < min_b)
		place = get_pos_min(min_b, b);
	else
		place = get_pos(temp->nr, b);
	return (place);
}

t_move	*min_move(t_move *move)
{
	t_move	*mimove;

	mimove = move;
	while (move != NULL)
	{
		if (move->sum < mimove->sum)
			mimove = move;
		move = move -> next;
	}
	return (mimove);
}

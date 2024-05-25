/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:16:26 by pvass             #+#    #+#             */
/*   Updated: 2024/05/25 14:36:12 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_move	*find_best_move2(t_stack *temp, t_stack *b, int pos_a)
{
	t_move	*move;
	t_move	*temp_move;

	move = rrr_ra(temp, b, pos_a);
	if (move == NULL)
		return (free_moves(&move), NULL);
	temp_move = rrr_rb(temp, b, pos_a);
	if (temp_move == NULL)
		return (free_moves(&move), NULL);
	ft_moveadd_top(&move, temp_move);
	temp_move = rrr_rra(temp, b, pos_a);
	if (temp_move == NULL)
		return (free_moves(&move), NULL);
	ft_moveadd_top(&move, temp_move);
	temp_move = rrr_rrb(temp, b, pos_a);
	if (temp_move == NULL)
		return (free_moves(&move), NULL);
	ft_moveadd_top(&move, temp_move);
	return (move);
}

static t_move	*find_best_move(t_stack *temp, t_stack *b, int pos_a)
{
	t_move	*move;
	t_move	*temp_move;

	move = rr_ra(temp, b, pos_a);
	if (move == NULL)
		return (free_moves(&move), NULL);
	temp_move = rr_rb(temp, b, pos_a);
	if (temp_move == NULL)
		return (free_moves(&move), NULL);
	ft_moveadd_top(&move, temp_move);
	temp_move = rr_rra(temp, b, pos_a);
	if (temp_move == NULL)
		return (free_moves(&move), NULL);
	ft_moveadd_top(&move, temp_move);
	temp_move = rr_rrb(temp, b, pos_a);
	if (temp_move == NULL)
		return (free_moves(&move), NULL);
	ft_moveadd_top(&move, temp_move);
	temp_move = find_best_move2(temp, b, pos_a);
	if (temp_move == NULL)
		return (free_moves(&move), NULL);
	ft_moveadd_top(&move, temp_move);
	return (move);
}

static t_move	*look_for_next(t_stack *temp, t_stack **b)
{
	t_move	*next_move;
	t_move	*temp_move;
	int		pos_a;

	pos_a = 0;
	next_move = find_best_move(temp, *b, pos_a);
	if (next_move == NULL)
		return (NULL);
	while (pos_a < ft_stacksize(temp))
	{
		temp_move = find_best_move(temp, *b, pos_a);
		if (temp_move == NULL)
			return (free_moves(&next_move), NULL);
		if (min_move(temp_move)->sum < min_move(next_move)->sum)
		{
			free_moves(&next_move);
			next_move = temp_move;
		}
		else
			free_moves(&temp_move);
		pos_a++;
	}
	return (next_move);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_move	*next_move;

	if (ft_stacksize(*a) == 2 && (*a)->nr > ((*a)->next->nr))
		return (sa(a));
	if (ft_stacksize(*a) <= 2)
		return ;
	while (ft_stacksize(*a) > 3)
	{
		if (sorted(a, b) == 1)
			return ;
		if (ft_stacksize(*a) == 3)
			break ;
		temp = *a;
		next_move = look_for_next(temp, b);
		if (next_move == NULL)
			return (errormsg());
		do_moves(min_move(next_move), a, b);
		free_moves(&next_move);
		if (ft_stacksize(*b) == 3)
			sort3(b);
	}
	right_order(b);
	last_moves(a, b);
}

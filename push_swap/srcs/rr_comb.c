/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_comb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:02:57 by pvass             #+#    #+#             */
/*   Updated: 2024/05/25 12:51:08 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

t_move	*rr_ra(t_stack *temp, t_stack *b, int pos_a)
{
	t_move	*move;
	int		rr;

	move = (t_move *) malloc (sizeof(t_move));
	if (move == NULL)
		return (NULL);
	move -> next = NULL;
	move->pos = pos_a;
	move->rrr = 0;
	move->rra = 0;
	move->rrb = 0;
	move->rb = 0;
	rr = place_in_b(temp, &b, pos_a) % ft_stacksize(b);
	move->rr = rr;
	move->ra = ft_abs((ft_stacksize(temp) - place_in_b(temp, &b, pos_a) + pos_a)
			% ft_stacksize(temp));
	move->sum = move->rr + move->ra;
	return (move);
}

t_move	*rr_rb(t_stack *temp, t_stack *b, int pos_a)
{
	t_move	*move;

	move = (t_move *) malloc (sizeof(t_move));
	if (move == NULL)
		return (NULL);
	move -> next = NULL;
	move->pos = pos_a;
	move->rrr = 0;
	move->rra = 0;
	move->rrb = 0;
	move->ra = 0;
	move->rr = pos_a;
	move->rb = ft_abs((ft_stacksize(b) + place_in_b(temp, &b, pos_a) - pos_a)
			% ft_stacksize(b));
	move->sum = move->rr + move->rb;
	return (move);
}

t_move	*rr_rra(t_stack *temp, t_stack *b, int pos_a)
{
	t_move	*move;
	int		rr;

	move = (t_move *) malloc (sizeof(t_move));
	if (move == NULL)
		return (NULL);
	move -> next = NULL;
	move->pos = pos_a;
	move->rrr = 0;
	move->ra = 0;
	move->rrb = 0;
	move->rb = 0;
	rr = place_in_b(temp, &b, pos_a) % ft_stacksize(b);
	move->rr = rr;
	move->rra = pos_a + rr;
	move->sum = move->rr + move->rra;
	return (move);
}

t_move	*rr_rrb(t_stack *temp, t_stack *b, int pos_a)
{
	t_move	*move;

	move = (t_move *) malloc (sizeof(t_move));
	if (move == NULL)
		return (NULL);
	move -> next = NULL;
	move->pos = pos_a;
	move->rrr = 0;
	move->rra = 0;
	move->rb = 0;
	move->ra = 0;
	move->rr = pos_a;
	move->rrb = ft_abs((ft_stacksize(b) - place_in_b(temp, &b, pos_a) + pos_a)
			% ft_stacksize(b));
	move->sum = move->rr + move->rrb;
	return (move);
}

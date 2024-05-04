/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_comb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:25:55 by pvass             #+#    #+#             */
/*   Updated: 2024/05/04 17:54:03 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_moveadd_top(t_move **lst, t_move *new)
{
	t_move	*i;

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

t_move *rrr_ra(t_stack *temp, t_stack *b, int pos_a)
{
	t_move	*move;
	int		rrr;
	
	move = (t_move *) malloc (sizeof(t_move));
	if (move == NULL)
		return (NULL);
	move -> next = NULL;
	move->name = "rrr_ra";
	move->pos = pos_a;
	move->rr = 0;
	move->rra = 0;
	move->rrb = 0;
	move->rb = 0;
	rrr = (ft_stacksize(b) - place_in_b(temp, &b)) % ft_stacksize(b);
	move->rrr = rrr;
	move->ra = ft_abs((rrr + pos_a) % ft_stacksize(temp));
	move->sum = move->rrr + move->ra;
	return (move);
}

t_move *rrr_rb(t_stack *temp, t_stack *b, int pos_a)
{
	t_move	*move;
	int		rrr;
	
	move = (t_move *) malloc (sizeof(t_move));
	if (move == NULL)
		return (NULL);
	move -> next = NULL;
	move->name = "rrr_rb";
	move->pos = pos_a;
	move->rr = 0;
	move->rra = 0;
	move->rrb = 0;
	move->ra = 0;
	rrr = (ft_stacksize(temp) - pos_a) % ft_stacksize(temp);
	move->rrr = rrr;
	move->rb = ft_abs((rrr + place_in_b(temp, &b)) % ft_stacksize(b));
	move->sum = move->rrr + move->rb;
	return (move);
}

t_move *rrr_rra(t_stack *temp, t_stack *b, int pos_a)
{
	t_move	*move;
	int		rrr;
	
	move = (t_move *) malloc (sizeof(t_move));
	if (move == NULL)
		return (NULL);
	move -> next = NULL;
	move->name = "rrr_rra";
	move->pos = pos_a;
	move->rr = 0;
	move->ra = 0;
	move->rrb = 0;
	move->rb = 0;
	rrr = (ft_stacksize(b) - place_in_b(temp, &b)) % ft_stacksize(b);
	move->rrr = rrr;
	move->rra = ft_abs((pos_a - rrr) % ft_stacksize(temp));
	move->sum = move->rrr + move->rra;
	return (move);
}

t_move *rrr_rrb(t_stack *temp, t_stack *b, int pos_a)
{
	t_move	*move;
	int		rrr;
	
	move = (t_move *) malloc (sizeof(t_move));
	if (move == NULL)
		return (NULL);
	move -> next = NULL;
	move->name = "rrr_rrb";
	move->pos = pos_a;
	move->rr = 0;
	move->rra = 0;
	move->rb = 0;
	move->ra = 0;
	rrr = (ft_stacksize(temp) - pos_a) % ft_stacksize(temp);
	move->rrr = rrr;
	move->rrb = ft_abs((place_in_b(temp, &b) - rrr) % ft_stacksize(b));
	move->sum = move->rrr + move->rrb;
	return (move);
}
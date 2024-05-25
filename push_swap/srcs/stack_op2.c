/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:33:38 by pvass             #+#    #+#             */
/*   Updated: 2024/05/18 15:23:29 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_min(t_stack **b)
{
	t_stack	*temp;
	int		min;

	temp = *b;
	min = temp -> nr;
	while (temp != NULL)
	{
		if (temp -> nr < min)
			min = temp -> nr;
		temp = temp -> next;
	}
	return (min);
}

int	ft_stack_max(t_stack **b)
{
	t_stack	*temp;
	int		max;

	temp = *b;
	max = temp -> nr;
	while (temp != NULL)
	{
		if (temp -> nr > max)
			max = temp -> nr;
		temp = temp -> next;
	}
	return (max);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:16:26 by pvass             #+#    #+#             */
/*   Updated: 2024/05/03 21:33:47 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack *a, t_stack *b)
{
	t_stack	*temp;
	
	while (b != NULL)
	{
		temp = b -> next;
		free(b);
		b = temp;
	}
	while (a != NULL)
	{
		temp = a -> next;
		free(a);
		a = temp;
	}
}

void	print_stack(t_stack *a)
{
	if (a == NULL)
		return ;
	while (a != NULL)
	{
		printf("%d\n", a -> nr);
		a = a -> next;
	}
}

/* static int	sorted1(t_stack *a)
{
	if (ft_stacksize(a) < 2)
		return (1);
	while (a -> next != NULL)
	{
		if (a -> nr > a -> next -> nr)
			return(0);
		a = a -> next;
	}
	return (1);
}

static int	sorted2(t_stack *a)
{
	if (ft_stacksize(a) < 2)
		return (1);
	while (a -> next != NULL)
	{
		if (a -> nr < a -> next -> nr)
			return(0);
		a = a -> next;
	}
	return (1);
} */

static int	ps2(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	if (*b != NULL && ((*b)->nr > (*a)->nr))
	{
		ra(a);
		pa(a, b);
		rra(a);
		ps2(a, b);
		i = i + 3;
	}
	return (i);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int	i = 0;
	int	size;
	
	//sorted1(*a) == 0 && sorted2(*a) == 0
	while (*a != NULL)
	{
		i = i + ps2(a, b);
		pb(a, b);
		i++;
	}
	/* size = ft_stacksize(*a);
	 if (sorted2(*a) == 1)
	{
		while (size-- > 1)
		{
			rra(a);
			pb(a, b);
			i += 2;
		}
		pb(a, b);
		i++;
		size = 0;
	} */
	while (*b != NULL)
	{
			pa(a, b);
			i++;
	}
	/* if(sorted1(*a) == 0)
	{
		i += size;
		while (size-- > 0)
			rra(a);
	} */
	printf("Total moves: %d\n", i);
}

/* void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int	i = 0;
	
	while (*a != NULL)
	{
		while (*b != NULL && ((*b)->nr > (*a)->nr))
		{
			ra(a);
			pa(a, b);
			rra(a);
			i = i + 3;
		}
		pb(a, b);
		i++;
	}
	while (*b != NULL)
	{
			pa(a, b);
			i++;
	}
	printf("Total moves: %d\n", i);
} */
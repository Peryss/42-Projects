/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:16:26 by pvass             #+#    #+#             */
/*   Updated: 2024/05/04 18:52:35 by pvass            ###   ########.fr       */
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

int		get_pos_max(int max_b, t_stack **b)
{
	t_stack *temp;
	int		pos;

	temp = *b;
	pos = 0;
	while (temp -> nr != max_b)
	{
		pos++;
		temp = temp -> next;
	}
	return(pos);
}

int		get_pos_min(int min_b, t_stack **b)
{
	t_stack *temp;
	int		pos;

	temp = *b;
	pos = 1;
	while (temp -> nr != min_b)
	{
		pos++;
		temp = temp -> next;
	}
	if (pos > ft_stacksize(*b))
		return (0);
	return(pos);
}

int		get_pos(int	nr, t_stack **b)
{
	t_stack *temp;
	int		pos;

	temp = *b;
	pos = 1;
	if (nr < temp->nr && nr > ft_stacklast(temp)->nr)
		return (0);
	while (nr > temp->nr)
	{
		pos++;
		temp = temp -> next;
	}
	return (pos);
}

int		place_in_b(t_stack *temp, t_stack **b)
{
	int		max_b;
	int		min_b;

	max_b = ft_stack_max(b);
	min_b = ft_stack_min(b);
	if(temp->nr > max_b)
		return(get_pos_max(max_b, b));
	if(temp->nr < min_b)
		return(get_pos_min(min_b, b));
	return(get_pos(temp->nr, b));
}

/* int		rotations_b(t_stack *temp, t_stack **b)
{
	int		pos;
	int		size;
	int		rotb;
	
	pos = place_in_b(temp, b);
	size = ft_stacksize(*b);
	if (pos <= size / 2)
		return (pos);
	return(pos - size);
} */
/* 
t_move *rr_ra(t_stack *temp, t_stack *b, int pos_a)
{
	t_move	*move;
	int		new_pos;
	int		rr;
	
	rr = place_in_b(temp, &b);
	move->pos = pos_a;
	move->rrr = 0;
	move->rra = 0;
	move->rrb = 0;
	move->rb = 0;
	rr = place_in_b(temp, &b);
	move->rr = rr;
	while(rr != 0)
	{
		while (pos_a != 0 && rr != 0)
		{
			pos_a--;
			rr--;
		}
		pos_a = ft_stacksize(temp) - 1;
		rr--;
	}
	move->ra = pos_a;
	move->sum = move->rr + move->ra;
	return (move);
} */

t_move	*find_best_move(t_stack *temp, t_stack *b, int pos_a)
{
	t_move	*move;
	t_move	*temp_move;
/* move_new with malloc, check for malloc fails */
	move = rr_ra(temp, b, pos_a);
	temp_move = rr_rb(temp, b, pos_a);
	ft_moveadd_top(&move, temp_move);
	temp_move = rr_rra(temp, b, pos_a);
	ft_moveadd_top(&move, temp_move);
	temp_move = rr_rrb(temp, b, pos_a);
	ft_moveadd_top(&move, temp_move);
	temp_move = rrr_ra(temp, b, pos_a);
	ft_moveadd_top(&move, temp_move);
	temp_move = rrr_rb(temp, b, pos_a);
	ft_moveadd_top(&move, temp_move);
	temp_move = rrr_rra(temp, b, pos_a);
	ft_moveadd_top(&move, temp_move);
	temp_move = rrr_rrb(temp, b, pos_a);
	ft_moveadd_top(&move, temp_move);
	return (move);
}

t_move *min_move(t_move *move)
{
	t_move *mimove;
	
	mimove = move;
	while (move != NULL)
	{
		if (move->sum < mimove->sum)
			mimove = move;
		move = move -> next;
	}
	return (mimove);
}

t_move	*look_for_next(t_stack *temp, t_stack **b)
{
	t_move	*next_move;
	t_move	*temp_move;
	int		type;
	int		pos_a;
	
	pos_a = 0;
	next_move = find_best_move(temp, *b, pos_a);
	while (pos_a != ft_stacksize(temp))
	{
		temp_move = find_best_move(temp, *b, pos_a);
		if (min_move(temp_move)->sum < min_move(next_move)->sum)
		{
			free(next_move);
			next_move = temp_move;
		}
		pos_a++;
	}
	return(next_move);
}

void	do_moves(t_move *move, t_stack **a, t_stack **b)
{
	printf("Move: name: %s, rr%d, rrr%d, ra%d, rra%d, rb%d, rrb%d, number:%d, sum:%d\n\n", move->name, move->rr, move->rrr, move->ra, move->rra, move->rb, move->rrb, move->pos, move->sum);
	while (move->rr-- > 0)
		rr(a,b);
	while (move->rrr-- > 0)
		rrr(a,b);
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

int		right_order(t_stack **b)
{
	t_stack	*temp;
	int		count;
	int		i;

	temp = *b;
	count = 0;
	i = 0;
	while (temp->nr != ft_stack_max(b))
	{
		temp = temp->next;
		i++;
	}
	if(i < ft_stacksize(*b) / 2)
		while (i > 0)
		{
			rb(b);
			count++;
			i--;
		}
	else
	{
		count = ft_stacksize(*b);
		while (i < ft_stacksize(*b))
		{
			rrb(b);
			i++;
		}
	}
	return (count);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack *temp;
	t_move	*next_move;
	int	i = 0;
	
	while (*a != NULL)
	{
		if (*b == NULL)
		{
			pb(a, b);
			pb(a, b);
			i += 2;
		}
		temp = *a;
		next_move = look_for_next(temp, b);
		do_moves(min_move(next_move), a, b);
		i = i + 1 + next_move->sum;
		if(ft_stacksize(*b) == 3)
		{
			if((*b)->nr > (*b)->next->nr && (*b)->nr > (*b)->next->next->nr)
			{
				if((*b)->next->nr > (*b)->next->next->nr)
				{
					sb(b);
					rrb(b);
					i += 2;
				}
				if((*b)->next->nr < (*b)->next->next->nr)
				{
					rb(b);
					i++;
				}
			} 
			else if ((*b)->nr < (*b)->next->nr && (*b)->nr < (*b)->next->next->nr)
			{
				if((*b)->next->nr > (*b)->next->next->nr)
				{
					sb(b);
					rb(b);
					i += 2;
				}
			}
			else if ((*b)->nr > (*b)->next->nr && (*b)->nr < (*b)->next->next->nr)
			{
				sb(b);
				i++;
			}
			else if ((*b)->nr < (*b)->next->nr && (*b)->nr > (*b)->next->next->nr)
			{
				rrb(b);
				i++;
			}
		}
		printf("STACK A:\n");
		print_stack(*a);
		printf("\n\n");
		printf("STACK B:\n");
		print_stack(*b);
		printf("\n\n");
		/*FREE THE MOVES LIST*/
	}
	right_order(b);
	while (*b != NULL)
	{
		pa(a, b);
		i++;
	}
	printf("Total moves: %d\n", i);
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

/* static int	ps2(t_stack **a, t_stack **b)
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
} */

/*void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int	i = 0;
	int	size;
	
	sorted1(*a) == 0 && sorted2(*a) == 0
	while (*a != NULL)
	{
		i = i + ps2(a, b);
		pb(a, b);
		i++;
	}
	 size = ft_stacksize(*a);
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
	} 
	while (*b != NULL)
	{
			pa(a, b);
			i++;
	}
	 if(sorted1(*a) == 0)
	{
		i += size;
		while (size-- > 0)
			rra(a);
	} 
	printf("Total moves: %d\n", i);
} */

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
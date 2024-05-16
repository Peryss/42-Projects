/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:16:19 by pvass             #+#    #+#             */
/*   Updated: 2024/05/16 14:53:45 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct s_stack
{
	int				nr;
	struct s_stack	*next;
}	t_stack;

typedef struct s_move
{
	int				sum;
	int				pos;
	int				rrr;
	int				rr;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	char			*name;
	struct s_move	*next;
}	t_move;

t_stack	*ft_stacknew(int content);

int		ft_stacksize(t_stack *lst);

void	ft_stackadd_top(t_stack **lst, t_stack *new);

void	ft_stackadd_bot(t_stack **lst, t_stack *new);

int		ft_stack_min(t_stack **b);

int		ft_stack_max(t_stack **b);

void	sa(t_stack **a);

void	sb(t_stack **b);

void 	ss(t_stack **a, t_stack **b);

void	pa(t_stack **a, t_stack **b);

void	pb(t_stack **a, t_stack **b);

void	ra(t_stack **a);

void	rb(t_stack **b);

void	rr(t_stack **a, t_stack **b);

void	rra(t_stack **a);

void	rrb(t_stack **b);

void	rrr(t_stack **a, t_stack **b);

t_stack	*ft_stacklast(t_stack *lst);

void	free_all(t_stack *a, t_stack *b);

void	print_stack(t_stack *a);

void	push_swap(t_stack **a, t_stack **b);

int		place_in_b(t_stack *temp, t_stack **b, int pos_a);

t_move *rr_ra(t_stack *temp, t_stack *b, int pos_a);

t_move *rr_rb(t_stack *temp, t_stack *b, int pos_a);

t_move *rr_rra(t_stack *temp, t_stack *b, int pos_a);

t_move *rr_rrb(t_stack *temp, t_stack *b, int pos_a);

void	ft_moveadd_top(t_move **lst, t_move *new);

t_move	*rrr_ra(t_stack *temp, t_stack *b, int pos_a);

t_move	*rrr_rb(t_stack *temp, t_stack *b, int pos_a);

t_move	*rrr_rra(t_stack *temp, t_stack *b, int pos_a);

t_move	*rrr_rrb(t_stack *temp, t_stack *b, int pos_a);

int		ft_abs(int x);

#endif
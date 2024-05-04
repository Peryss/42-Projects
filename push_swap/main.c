/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:52:09 by pvass             #+#    #+#             */
/*   Updated: 2024/05/04 15:50:19 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int		i;
	int		*tab;
	t_stack *a;
	t_stack *b;
	t_stack	*temp;

	b = NULL;
	a = NULL;
	i = 0;
	tab = malloc (sizeof(int) * argc);
	if (tab == NULL)
		return (0);
	while (i++ < argc - 1)
	{
		temp = ft_stacknew(atoi(argv[i]));
		ft_stackadd_bot(&a, temp);
		if (ft_stacksize(a) != i)
			free_all(a, b);
	}
	print_stack(a);
	push_swap(&a, &b);
	print_stack(a);
	return (0);
}

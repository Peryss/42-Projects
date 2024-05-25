/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:52:09 by pvass             #+#    #+#             */
/*   Updated: 2024/05/25 14:10:55 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	i = 0;
	if (argc < 1)
		return (ft_printf("Error\n"), 0);
	if (argc == 1 || (argc == 2 && ft_strlen(argv[1]) == 0))
		return (0);
	if (argc == 2)
		a = check_input(argv[1]);
	if (argc > 2)
		a = check_input2(argv, argc);
	if (a == NULL)
		return (ft_printf("Error\n"), 0);
	if (check_duplicates(a) != 0)
		return (ft_printf("Error\n"), 0);
	push_swap(&a, &b);
	free_all(a, b);
	return (0);
}

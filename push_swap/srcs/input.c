/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 11:38:35 by pvass             #+#    #+#             */
/*   Updated: 2024/06/13 19:02:43 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	check_check(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str [i] > '9')
			return (1);
		i++;
	}
	return (0);
}

t_stack	*check_input(char *str)
{
	int		i;
	char	**tab;
	t_stack	*temp;
	t_stack	*a;

	a = NULL;
	tab = ft_split(str, ' ');
	if (tab == NULL || ft_strlen(str) == 0)
		return (NULL);
	printf("%d\n", check_alphhh(str) == 1);
	if (check_size(tab) == 1 || check_alphhh(str) == 1)
		return (free_tab(tab), NULL);
	i = 0;
	while (tab[i] != NULL)
	{
		if (check_check(tab[i]) == 1)
			return (free_stack(a), free(tab), NULL);
		temp = ft_stacknew(ft_atoi(tab[i]));
		if (temp == NULL)
			return (free_stack(a), free_tab(tab), NULL);
		ft_stackadd_bot(&a, temp);
		i++;
	}
	free_tab(tab);
	return (a);
}

t_stack	*check_input2(char **argv, int argc)
{
	int		i;
	t_stack	*a;
	t_stack	*temp;

	i = 0;
	a = NULL;
	if (check_size(argv + 1) == 1)
		return (NULL);
	while (i++ < argc - 1)
	{
		if (check_check(argv[i]) == 1)
			return (free_stack(a), NULL);
		temp = ft_stacknew(ft_atoi(argv[i]));
		if (temp == NULL)
			return (free_stack(a), NULL);
		ft_stackadd_bot(&a, temp);
	}
	return (a);
}

int	check_duplicates(t_stack *a)
{
	int	i;
	int	*tab;
	int	j;

	i = 0;
	tab = malloc(ft_stacksize(a) * sizeof(int));
	if (tab == NULL)
		return (1);
	while (a != NULL)
	{
		j = 0;
		while (j < i)
		{
			if (tab[j] == a->nr)
				return (free(tab), 1);
			j++;
		}
		tab[i] = a->nr;
		a = a->next;
		i++;
	}
	free(tab);
	return (0);
}

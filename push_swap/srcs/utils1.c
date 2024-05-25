/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:16:45 by pvass             #+#    #+#             */
/*   Updated: 2024/05/18 15:15:48 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_neg(char *str)
{
	int		i;
	char	*intmin;

	i = 0;
	if (ft_strlen(str) > 11)
		return (1);
	intmin = malloc(12);
	if (intmin == NULL)
		return (1);
	ft_strlcpy(intmin, "-2147483648", 12);
	while (str[i] != '\0')
	{
		if (str[i] - intmin[i] > 0)
			return (free(intmin), 1);
		if (str[i] - intmin[i] < 0)
			return (free(intmin), 0);
		i++;
	}
	free(intmin);
	return (0);
}

static int	check_pos(char *str)
{
	int		i;
	char	*intmax;

	i = 0;
	if (str[0] == '+')
		str++;
	if (ft_strlen(str) > 10)
		return (1);
	intmax = malloc(11);
	if (intmax == NULL)
		return (1);
	ft_strlcpy(intmax, "2147483647", 11);
	while (str[i] != '\0')
	{
		if (str[i] - intmax[i] > 0)
			return (free(intmax), 1);
		if (str[i] - intmax[i] < 0)
			return (free(intmax), 0);
		i++;
	}
	free(intmax);
	return (0);
}

int	check_size(char **tab)
{
	int	i;
	int	wrong;

	wrong = 0;
	i = 0;
	while (tab[i] != NULL)
	{
		if (tab[i][0] == '-' && ft_strlen(tab[i]) >= 11)
			wrong = check_neg(tab[i]);
		if (tab[i][0] != '-' && ft_strlen(tab[i]) >= 10)
			wrong = check_pos(tab[i]);
		if (wrong == 1)
			return (1);
		i++;
	}
	return (0);
}

void	free_moves(t_move **move)
{
	t_move	*mov;
	t_move	*temp;

	if (move == NULL)
		return ;
	mov = *move;
	while (mov != NULL)
	{
		temp = mov -> next;
		free(mov);
		mov = temp;
	}
}

void	free_all(t_stack *a, t_stack *b)
{
	t_stack	*temp;

	while (a != NULL)
	{
		temp = a -> next;
		free(a);
		a = temp;
	}
	while (b != NULL)
	{
		temp = b -> next;
		free(b);
		b = temp;
	}
}

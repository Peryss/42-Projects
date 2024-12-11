/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:03:59 by pvass             #+#    #+#             */
/*   Updated: 2024/12/11 19:39:32 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	wrong_input(char *str)
{
	char	*new;

	new = ft_itoa(ft_atoi(str));
	if (new == 0)
		return (0);
	if (ft_strncmp(new, str, ft_strlen(str)) == 0)
		return (free(new), 0);
	return (free(new), 1);
}

int	invalid_args(char **argv)
{
	if (ft_atoi(argv[1]) > 200
		|| ft_atoi(argv[1]) < 1 || wrong_input(argv[1]) == 1)
		return (write(2, "Invalid number of philosophers\n", 32), 1);
	if (ft_atoi(argv[2]) < 1 || wrong_input(argv[2]) == 1)
		return (write(2, "Invalid time to die\n", 21), 1);
	if (ft_atoi(argv[3]) < 1 || wrong_input(argv[3]) == 1)
		return (write(2, "Invalid time to eat\n", 21), 1);
	if (ft_atoi(argv[4]) < 1 || wrong_input(argv[4]) == 1)
		return (write(2, "Invalid time to sleep\n", 23), 1);
	if (argv[5] != NULL && (ft_atoi(argv[3]) < 1 || wrong_input(argv[3]) == 1))
		return (write(2, "Invalid number of must eat\n", 21), 1);
	return (0);
}

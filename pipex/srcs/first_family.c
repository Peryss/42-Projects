/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_family.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:28:27 by pvass             #+#    #+#             */
/*   Updated: 2024/06/20 17:03:58 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	f_cmd_child(int *p, char **argv, char **env, int stdout_copy)
{
	close(p[0]);
	if (dup2(p[1], 1) == -1)
	{
		close(p[1]);
		if (dup2(stdout_copy, 1) == -1)
		{
			close(stdout_copy);
			ft_putendl_fd("dup2 failed", 2);
			return ;
		}
		close(stdout_copy);
		ft_putendl_fd("dup2 failed", 2);
		return ;
	}
	close(p[1]);
	do_command(argv[2], env, stdout_copy);
}

void	f_cmd_parent(int *p, pid_t p_id, int stdout_copy)
{
	close(p[1]);
	if (dup2(p[0], 0) == -1)
	{
		close(p[0]);
		if (dup2(stdout_copy, 1) == -1)
		{
			close(stdout_copy);
			ft_putendl_fd("dup2 failed", 2);
			waitpid(p_id, NULL, 0);
			return ;
		}
		close(stdout_copy);
		ft_putendl_fd("dup2 failed", 2);
		waitpid(p_id, NULL, 0);
		return ;
	}
	close(p[0]);
	waitpid(p_id, NULL, 0);
}

void	last_parent(int *p, pid_t p_id)
{
	close(p[0]);
	close(p[1]);
	waitpid(p_id, NULL, 0);
}

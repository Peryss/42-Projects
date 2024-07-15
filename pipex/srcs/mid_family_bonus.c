/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_family.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:53:34 by pvass             #+#    #+#             */
/*   Updated: 2024/06/20 17:04:09 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	m_cmd_ex1(int stdout_copy)
{
	if (dup2(stdout_copy, 1) == -1)
	{
		close(stdout_copy);
		ft_putendl_fd("dup2 failed", 2);
		return ;
	}
	close(stdout_copy);
	ft_putendl_fd("pipe failed", 2);
	return ;
}

static void	m_cmd_ex2(int *p, int stdout_copy)
{
	close(p[1]);
	close(p[0]);
	if (dup2(stdout_copy, 1) == -1)
	{
		close(stdout_copy);
		ft_putendl_fd("dup2 failed", 2);
		return ;
	}
	close(stdout_copy);
	ft_putendl_fd("fork failed", 2);
	return ;
}

static void	m_cmd_ex3(int *p, int stdout_copy)
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

static void	m_cmd_ex4(int *p, pid_t p_id, int stdout_copy)
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

void	mid_cmd(int i, char **argv, char **env, int stdout_copy)
{
	int		p[2];
	pid_t	p_id;

	if (pipe(p) == -1)
		return (m_cmd_ex1(stdout_copy));
	p_id = fork();
	if (p_id == -1)
		return (m_cmd_ex2(p, stdout_copy));
	if (p_id == 0)
	{
		close(p[0]);
		if (dup2(p[1], 1) == -1)
			return (m_cmd_ex3(p, stdout_copy));
		close(p[1]);
		do_command(argv[i], env, stdout_copy);
	}
	else
	{
		close(p[1]);
		if (dup2(p[0], 0) == -1)
			return (m_cmd_ex4(p, p_id, stdout_copy));
		close(p[0]);
		waitpid(p_id, NULL, 0);
	}
}

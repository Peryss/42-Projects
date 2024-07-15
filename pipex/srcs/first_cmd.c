/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:20:14 by pvass             #+#    #+#             */
/*   Updated: 2024/06/20 17:03:43 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	f_cmd_ex1(int stdout_copy)
{
	if (dup2(stdout_copy, 1) == -1)
	{
		close(stdout_copy);
		ft_putendl_fd("dup2 failed", 2);
		return ;
	}
	close(stdout_copy);
	ft_putendl_fd("pipe failed", 2);
}

static void	f_cmd_ex2(int *p, int stdout_copy)
{
	if (dup2(stdout_copy, 1) == -1)
	{
		close(stdout_copy);
		ft_putendl_fd("dup2 failed", 2);
		return ;
	}
	close(stdout_copy);
	ft_putendl_fd("Open failed", 2);
	close(p[1]);
	if (dup2(p[0], 0) == -1)
	{
		close(p[0]);
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
	close(p[0]);
	return ;
}

static void	f_cmd_ex3(int *p, int stdout_copy)
{
	if (dup2(stdout_copy, 1) == -1)
	{
		close(stdout_copy);
		ft_putendl_fd("dup2 failed", 2);
		return ;
	}
	close(stdout_copy);
	ft_putendl_fd("dup2 failed", 2);
	close(p[1]);
	if (dup2(p[0], 0) == -1)
	{
		close(p[0]);
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
	close(p[0]);
	return ;
}

static void	f_cmd_ex4(int *p, int stdout_copy)
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

void	first_cmd(int argc, char **argv, char **env, int stdout_copy)
{
	int		in_fd;
	int		p[2];
	pid_t	p_id;

	(void)argc;
	if (pipe(p) == -1)
		return (f_cmd_ex1(stdout_copy));
	in_fd = open_file(argv[1], 0);
	if (in_fd == -1)
		return (f_cmd_ex2(p, stdout_copy));
	if (dup2 (in_fd, 0) == -1)
		return (f_cmd_ex3(p, stdout_copy));
	close (in_fd);
	p_id = fork();
	if (p_id == -1)
		return (f_cmd_ex4(p, stdout_copy));
	if (p_id == 0)
		f_cmd_child(p, argv, env, stdout_copy);
	else
		f_cmd_parent(p, p_id, stdout_copy);
}

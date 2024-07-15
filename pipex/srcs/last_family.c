/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_family.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:06:07 by pvass             #+#    #+#             */
/*   Updated: 2024/06/20 18:05:50 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	l_cmd_ex1(int stdout_copy)
{
	dup2(stdout_copy, 1);
	close(stdout_copy);
	ft_putendl_fd("Open failed", 2);
}

static void	l_cmd_ex2(int stdout_copy)
{
	if (dup2(stdout_copy, 1) == -1)
	{
		close(stdout_copy);
		ft_putendl_fd("dup2 failed", 2);
		return ;
	}
	close(stdout_copy);
	ft_putendl_fd("dup2 failed", 2);
}

static void	l_cmd_ex3(int stdout_copy)
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

static void	l_cmd_ex4(int *p, int stdout_copy)
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

void	last_cmd(int argc, char **argv, char **env, int stdout_copy)
{
	int		out_fd;
	int		p[2];
	pid_t	p_id;

	out_fd = create_output(argc, argv);
	if (out_fd == -1)
		return (l_cmd_ex1(stdout_copy));
	if (dup2(out_fd, 1) == -1)
		return (l_cmd_ex2(stdout_copy));
	close(out_fd);
	if (pipe(p) == -1)
		return (l_cmd_ex3(stdout_copy));
	p_id = fork();
	if (p_id == -1)
		return (l_cmd_ex4(p, stdout_copy));
	if (p_id == 0)
	{
		close(p[0]);
		close(p[1]);
		do_command(argv[argc - 2], env, stdout_copy);
	}
	else
		last_parent(p, p_id);
}

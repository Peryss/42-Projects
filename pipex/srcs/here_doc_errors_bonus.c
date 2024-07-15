/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:41:29 by pvass             #+#    #+#             */
/*   Updated: 2024/06/20 16:53:30 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_ex1(int stdout_copy)
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

void	here_ex2(int *p, int stdout_copy)
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
}

void	here_ex3(int *p, int stdout_copy)
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
}

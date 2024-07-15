/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:39:16 by pvass             #+#    #+#             */
/*   Updated: 2024/06/20 17:02:59 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_input(char **argv, int *p)
{
	char	*output;

	close (p[0]);
	while (1)
	{
		output = get_next_line(0);
		if (ft_strncmp(argv[2], output, ft_strlen(argv[2])) == 0)
		{
			free(output);
			close(p[1]);
			get_next_line(-1);
			exit (0);
		}
		ft_putstr_fd(output, p[1]);
		free(output);
	}
}

void	here_doc_first(int argc, char **argv, char **env, int stdout_copy)
{
	int		p[2];
	pid_t	p_id;

	(void)argc;
	(void)env;
	if (pipe(p) == -1)
		return (here_ex1(stdout_copy));
	p_id = fork();
	if (p_id == -1)
		return (here_ex2(p, stdout_copy));
	if (p_id == 0)
	{
		close(stdout_copy);
		get_input(argv, p);
	}
	else
	{
		close(p[1]);
		if (dup2(p[0], 0) == -1)
			return (waitpid(p_id, NULL, 0), here_ex3(p, stdout_copy));
		close(p[0]);
		waitpid(p_id, NULL, 0);
	}
}

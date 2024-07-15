/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:35:25 by pvass             #+#    #+#             */
/*   Updated: 2024/06/20 18:10:22 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	create_output(int argc, char **argv)
{
	int	out_fd;

	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		out_fd = open_file(argv[argc - 1], 2);
	else
		out_fd = open_file(argv[argc - 1], 1);
	return (out_fd);
}

static void	do_pipex(int argc, char **argv, char **env, int i)
{
	int	stdout_copy;

	stdout_copy = dup(1);
	if (stdout_copy == -1)
		return (ft_putendl_fd("dup failed", 2));
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		if (argc < 6)
			ft_putendl_fd ("Not enough arguments", 2);
		here_doc_first(argc, argv, env, stdout_copy);
		i = 4;
	}
	else
	{
		first_cmd(argc, argv, env, stdout_copy);
		i = 3;
	}
	while (i < argc - 2)
	{
		mid_cmd(i, argv, env, stdout_copy);
		i++;
	}
	last_cmd(argc, argv, env, stdout_copy);
	close(stdout_copy);
}

int	main(int argc, char **argv, char **env)
{
	int	i;
	int	out_fd;

	i = 0;
	out_fd = create_output(argc, argv);
	if (out_fd == -1)
		return (ft_putendl_fd("./pipex: permission denied for output", 2), 2);
	close(out_fd);
	if (argc >= 5)
	{
		out_fd = create_output(argc, argv);
		if (out_fd == -1)
			return (ft_putendl_fd("./pipex: permission denied: outf", 2), 2);
		close(out_fd);
		do_pipex(argc, argv, env, i);
	}
	else
		ft_putendl_fd ("Not enough arguments", 2);
}

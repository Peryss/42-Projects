/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:16:12 by pvass             #+#    #+#             */
/*   Updated: 2024/06/20 18:10:52 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	create_output(int argc, char **argv)
{
	int	out_fd;

	out_fd = open_file(argv[argc - 1], 1);
	return (out_fd);
}

static void	do_pipex(int argc, char **argv, char **env)
{
	int	stdout_copy;

	stdout_copy = dup(1);
	if (stdout_copy == -1)
		return (ft_putendl_fd("dup failed", 2));
	first_cmd(argc, argv, env, stdout_copy);
	last_cmd(argc, argv, env, stdout_copy);
	close(stdout_copy);
}

int	main(int argc, char **argv, char **env)
{
	int	i;
	int	out_fd;

	i = 0;
	if (argc == 5)
	{
		out_fd = create_output(argc, argv);
		if (out_fd == -1)
			return (ft_putendl_fd("./pipex: permission deniedL outf", 2), 2);
		close(out_fd);
		do_pipex(argc, argv, env);
	}
	else
		ft_putendl_fd ("5 arguments needed", 2);
}

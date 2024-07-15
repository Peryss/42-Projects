/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:13:08 by pvass             #+#    #+#             */
/*   Updated: 2024/06/20 16:50:47 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(argv, O_RDONLY, 0777);
	if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (i == 2)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	return (file);
}

static void	do_cmd_ex1(char *cmd, int stdout_copy)
{
	dup2(stdout_copy, 1);
	close(stdout_copy);
	ft_putstr_fd("./pipex: command not found: ", 2);
	ft_putendl_fd(cmd, 2);
	return (exit(0));
}

static void	do_cmd_ex2(char *cmd, int stdout_copy)
{
	dup2(stdout_copy, 1);
	close(stdout_copy);
	ft_putstr_fd("./pipex: command not found: ", 2);
	ft_putendl_fd(cmd, 2);
	return (exit(0));
}

static void	do_cmd_ex3(char *cmd_path, int stdout_copy)
{
	dup2(stdout_copy, 1);
	close(stdout_copy);
	ft_putendl_fd("Malloc failed", 2);
	return (free(cmd_path), exit(0));
}

void	do_command(char *command, char **env, int stdout_copy)
{
	char	*cmd_path;
	char	**newargv;

	if (check_empty(command) == 1)
		do_cmd_ex1(command, stdout_copy);
	cmd_path = comm(env, command);
	if (cmd_path == NULL)
		do_cmd_ex2(command, stdout_copy);
	newargv = ft_split(command, ' ');
	if (newargv == NULL)
		do_cmd_ex3(cmd_path, stdout_copy);
	free(newargv[0]);
	newargv[0] = cmd_path;
	close(stdout_copy);
	if (execve(cmd_path, newargv, env) == -1)
	{
		free_all(newargv, get_tab_size(newargv));
		exit (0);
	}
}

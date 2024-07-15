/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:19:52 by pvass             #+#    #+#             */
/*   Updated: 2024/06/20 18:09:34 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./../ft_printf/ft_printf.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

/*HERE_DOC*/

void	here_doc_first(int argc, char **argv, char **env, int stdout_copy);

void	get_input(char **argv, int *p);

void	here_ex1(int stdout_copy);

void	here_ex2(int *p, int stdout_copy);

void	here_ex3(int *p, int stdout_copy);

/*INPUT HANDLING*/

void	free_all(char **paths, int size);

int		get_tab_size(char **tab);

char	*get_paths(char **env);

char	**join_more(char **paths, char *cmd);

char	**path(char **env);

char	*first_word_pip(char *str);

char	*comm(char **env, char *cmd);

int		check_empty(char *cmd);

/*DO COMMAND*/

void	do_command(char *command, char **env, int stdout_copy);

/*OPEN FILE*/

int		open_file(char *argv, int i);

/*Family*/

void	first_cmd(int argc, char **argv, char **env, int stdout_copy);

void	f_cmd_child(int *p, char **argv, char **env, int stdout_copy);

void	f_cmd_parent(int *p, pid_t p_id, int stdout_copy);

void	mid_cmd(int i, char **argv, char **env, int stdout_copy);

void	last_parent(int *p, pid_t p_id);

void	last_cmd(int argc, char **argv, char **env, int stdout_copy);

int		create_output(int argc, char **argv);

#endif
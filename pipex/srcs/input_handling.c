/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:56:20 by pvass             #+#    #+#             */
/*   Updated: 2024/06/20 16:51:48 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*first_word_pip(char *str)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	word = malloc (i + 1);
	if (word == NULL)
		exit (0);
	ft_strlcpy (word, str, i + 1);
	return (word);
}

static char	*comm_util(char **full_paths, int i)
{
	char	*res;

	res = NULL;
	while (full_paths[i] != NULL)
	{
		if (access(full_paths[i], F_OK | X_OK) == 0)
		{
			res = ft_strdup(full_paths[i]);
			if (res == NULL)
				return (free_all(full_paths, get_tab_size(full_paths)), NULL);
			return (free_all(full_paths, get_tab_size(full_paths)), res);
		}
		i++;
	}
	return (free_all(full_paths, get_tab_size(full_paths)), NULL);
}

char	*comm(char **env, char *cmd)
{
	char	**paths;
	char	**full_paths;
	char	*command;
	int		i;

	i = 0;
	command = first_word_pip(cmd);
	if (command == NULL)
		return (exit(0), NULL);
	paths = path(env);
	if (paths == NULL)
		return (free(command), exit(0), NULL);
	full_paths = join_more(paths, command);
	free(command);
	if (full_paths == NULL)
		return (NULL);
	return (comm_util(full_paths, i));
}

int	check_empty(char *cmd)
{
	if (cmd[0] == '\0' || cmd[0] == ' ')
		return (1);
	else
		return (0);
}

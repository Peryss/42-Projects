/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:53:04 by pvass             #+#    #+#             */
/*   Updated: 2024/06/20 17:03:32 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(char **paths, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (paths[i] != NULL)
			free(paths[i]);
		i++;
	}
	free(paths);
}

int	get_tab_size(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return (0);
	while (tab[i] != NULL)
		i++;
	return (i);
}

char	*get_paths(char **env)
{
	int		i;
	int		j;
	char	*path;	

	i = 0;
	j = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			while (env[i][j + 5] != '\n' && env[i][j + 5] != '\0')
				j++;
			path = malloc(j + 1);
			if (path == NULL)
				return (NULL);
			ft_strlcpy(path, env[i] + 5, j + 1);
			return (path);
		}
		i++;
	}
	return (NULL);
}

char	**join_more(char **paths, char *cmd)
{
	int		i;
	int		size;
	char	**new;

	i = 0;
	size = 0;
	while (paths[size] != NULL)
		size++;
	if (paths == NULL)
		return (free_all(paths, size), NULL);
	new = malloc ((size + 1) * sizeof(char *));
	if (new == NULL)
		return (free_all(paths, size), NULL);
	while (paths[i] != NULL)
	{
		new[i] = ft_strjoin(paths[i], cmd);
		if (new[i] == NULL)
			return (free_all(paths, size), free_all(new, i), NULL);
		i++;
	}
	new[i] = NULL;
	free_all(paths, size);
	return (new);
}

char	**path(char **env)
{
	char	*path_long;
	char	**paths;

	paths = NULL;
	path_long = get_paths(env);
	if (path_long == NULL)
		return (NULL);
	paths = ft_split(path_long, ':');
	if (paths == NULL)
		return (free(path_long), NULL);
	paths = join_more(paths, "/");
	if (paths == NULL)
		return (free(path_long), NULL);
	return (free(path_long), paths);
}

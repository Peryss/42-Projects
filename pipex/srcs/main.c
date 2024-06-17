/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:35:25 by pvass             #+#    #+#             */
/*   Updated: 2024/06/17 16:59:20 by pvass            ###   ########.fr       */
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
		return(0);
	while (tab[i] != NULL)
		i++;
	return (i);
}

char *get_paths(char **env)
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
			while(env[i][j+5] != '\n' && env[i][j+5] != '\0')
				j++;
			path = malloc(j+1);
			if (path == NULL)
				return (NULL);
			ft_strlcpy(path, env[i] + 5, j+1);
			return (path);
		}
		i++;
	}
	return (NULL);
}

char **join_more(char **paths, char *cmd)
{
	int	i;
	int	size;
	char **new;

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

void ptab(char **tab)
{
	int i;

	i=0;
	while (tab[i] != NULL)
	{
		ft_printf("%s\n",tab[i]);
		i++;
	}
}

char **path(char **env)
{
	char	*path_long;
	char	**paths;
	int		i;

	i = 0;
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

char *first_word(char *str)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	word = malloc (i+1);
	if (word == NULL)
		exit (0);
	ft_strlcpy (word, str, i + 1);
	return (word);
}

char *comm(char **env, char *cmd)
{
	char	**paths;
	char	**full_paths;
	char	*command;
	char	*res;
	int		i = 0;
	
	res = NULL;
	command = first_word(cmd);
	if (command == NULL)
		return (exit(0), NULL);
	paths = path(env);
	if (paths == NULL)
		return (free(command), exit(0), NULL);
	full_paths = join_more(paths, command);
	free(command);
	if (full_paths == NULL)
		return (NULL);
	while (full_paths[i] != NULL)
	{
		//printf("11111111HAAA:%s\n", full_paths[i]);
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

void	do_command(char *command, char **env)
{
	char *cmd_path;
	char **newargv;

	cmd_path = comm(env, command);
	//cmd_path = "/usr/bin/cat";
	if (cmd_path == NULL)
	{
		ft_printf("pipex: command not found: %s\n", command);
		return (exit(0));
	}
	newargv = ft_split(command, ' ');
	if (newargv == NULL)
	{
		ft_printf("pipex: command not found: %s\n", command);
		return (free(cmd_path), exit(0));
	}
	free(newargv[0]);
	newargv[0] = cmd_path;

	/* free_all(newargv, get_tab_size(newargv));
	exit(0); */
	
	if (execve(cmd_path, newargv, env) == -1)
	{
		//ft_printf("pipex: command not found: %s\n", command);
		free_all(newargv, get_tab_size(newargv));
		//free(cmd_path);
		exit (0);
	}
}

void create_pipe(int *p, char *command, char **env)
{
	pid_t	pipe_id;
	int		pip[2];
	(void) p;
	//int		status;
	
	if (pipe(pip) == -1)
		exit (0);
	pipe_id = fork();
	if (pipe_id == -1)
		exit (0);
	if (pipe_id == 0)
	{
		close(pip[0]);
		dup2(pip[1], 1);
		do_command(command, env);
	}
	else
	{
		close(pip[1]);
		dup2(pip[0], 0);
		waitpid(pipe_id, NULL, 0);
	}
}

void solve(int *p, int argc, char **env, char **argv)
{
	int		i;
	
	i = 2;
	while (i < argc - 2)
	{
		create_pipe(p, argv[i], env);
		//close(p[0]);
		i++;
	}
	//close(p[1]);
	//close(p[0]);
}

/*valgrind --trace-children=yes --track-fds=yes --leak-check=full --show-leak-kinds=all ./pipex file1 "cat" cat file2*/

int	main(int argc, char **argv, char **env)
{
	int	p[2];

	if (argc < 5)
		return (ft_putendl_fd("./pipex file1 cmd1 cmd2 ... cmdn file2", 1), 0);
	p[1] = open(argv[1], O_RDONLY, 0777);
	if (p[1]== -1)
		return (ft_putendl_fd("Error", 2), 0);
	p[0] = open(argv[argc - 1], O_WRONLY, 0777);
	if (p[0] == -1)
		return (ft_putendl_fd("Error", 2), 0);
	if(dup2(p[1], 0) == -1)
		exit(0);
	solve (p, argc, env, argv);
	if(dup2(p[0], 1) == -1)
		exit(0);
	//close(p[1]);
	do_command(argv[argc - 2], env);
	return (0);
}
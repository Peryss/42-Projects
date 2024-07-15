/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:13:28 by pvass             #+#    #+#             */
/*   Updated: 2024/04/23 13:13:52 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_string(int fd, char *str)
{
	char	*buffer;
	char	*new;
	int		pos;

	pos = -2;
	if (str == NULL)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (free(str), NULL);
	buffer[0] = '\0';
	while ((ft_strchr(str, '\n') == NULL) && pos != 0)
	{
		pos = read(fd, buffer, BUFFER_SIZE);
		if (pos < 0 || (ft_strlen(str) == 0 && pos == 0))
			return (free(str), free(buffer), NULL);
		buffer[pos] = '\0';
		new = ft_strjoin(str, buffer);
		if (new == NULL)
			return (free(str), free(buffer), NULL);
		free(str);
		str = new;
	}
	return (free(buffer), str);
}

static char	*get_lin(char *str)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (line == NULL)
		return (free(str), NULL);
	while (j < i)
	{
		line[j] = str[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*left(char *r_str)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	if (r_str == NULL)
		return (NULL);
	while (r_str[i] != '\0' && r_str[i] != '\n')
		i++;
	if (r_str[i] == '\n')
		i++;
	ptr = malloc (ft_strlen(r_str) - i + 1);
	if (ptr == NULL)
		return (free(r_str), NULL);
	while (r_str[i] != '\0')
	{
		ptr[j] = r_str[i];
		i++;
		j++;
	}
	ptr[j] = '\0';
	free(r_str);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*r_str;
	static int	count;
	char		*string;

	if (count == 0)
	{
		r_str = (char *) malloc (1);
		if (r_str == NULL)
			return (NULL);
		r_str[0] = '\0';
		count++;
	}
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (count = 0, free (r_str), NULL);
	r_str = read_string(fd, r_str);
	if (r_str == NULL)
		return (count = 0, NULL);
	string = get_lin(r_str);
	if (string == NULL)
		return (count = 0, NULL);
	r_str = left(r_str);
	if (r_str == NULL)
		return (count = 0, free(string), NULL);
	return (string);
}

/* int main(void)
{
	int fd;

	fd = open("1char.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	char *str = get_next_line(fd);
	int len = ft_strlen(str);
	printf("First line: %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("Second line: %s\n", str);
	close(fd);
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	
	str = get_next_line(fd);
	printf("Third line: %s\n", str);
	free(str);
	
	//close (fd);
	fd = open("1char.txt", O_RDONLY);
	
	str = get_next_line(fd);
	printf("Forth line: %s\n", str);

	close (fd);
	str = get_next_line(fd);
	
	printf("Fifth line: %s\n", str);
	
	free(str);
	fd = open("1char.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("sixthline: %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("seventh line: %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("eighth line: %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("9line: %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("10line: %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("11line: %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("12line: %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("13line: %s\n", str);
	free(str);
	close(fd);
	printf("%d\n", fd);
	return (0);
} */
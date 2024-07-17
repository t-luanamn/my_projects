/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:58:17 by tluanamn          #+#    #+#             */
/*   Updated: 2023/12/16 14:35:22 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *cmd, char **env)
{
	char	**paths;
	char	*path;
	int		i;
	char	*temp;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, 0) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

void	execute(char *av, char **env)
{
	char	**cmd;
	int		i;
	char	*path;

	i = -1;
	cmd = ft_split(av, ' ');
	path = find_path(cmd[0], env);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		perror("Error");
		exit(1);
	}
	if (execve(path, cmd, env) == -1)
	{
		perror("Error");
		exit(1);
	}
	free(cmd);
	free(path);
	exit(1);
}

void	err_msg(int e)
{
	ft_putstr_fd("Error", 2);
	exit(e);
}

int	open_file(char *av, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(av, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		file = open(av, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		file = open(av, O_RDONLY, 0777);
	if (file == -1)
		err_msg(1);
	return (file);
}

int	get_next_line(char **line)
{
	char	*temp;
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	temp = (char *)malloc(10000);
	if (!temp)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			temp[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	temp[i] = '\n';
	temp[++i] = '\0';
	*line = temp;
	free(temp);
	return (r);
}

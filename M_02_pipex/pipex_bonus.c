/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:12:20 by tluanamn          #+#    #+#             */
/*   Updated: 2023/12/16 14:35:04 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process(char *av, char **env)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		err_msg(1);
	pid = fork();
	if (pid == -1)
		err_msg(1);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		execute(av, env);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(pid, NULL, 0);
	}
}

void	here_doc(char *limiter, int ac)
{
	pid_t	r;
	int		fd[2];
	char	*line;

	if (ac < 6)
		err_msg(1);
	if (pipe(fd) == -1)
		err_msg(1);
	r = fork();
	if (r == 0)
	{
		close(fd[0]);
		while (get_next_line(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(0);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		wait(NULL);
	}
}

/*
int	main(int ac, char **av, char **env)
{
	int	i;
	int	infile;
	int	outfile;

	if (ac >= 5)
	{
		if (ft_strncmp(av[1], "here_doc", 8) == 0)
		{
			i = 3;
			outfile = open_file(av[ac - 1], 0);
			here_doc(av[2], ac);
		}
		else
		{
			i = 2;
			outfile = open_file(av[ac - 1], 1);
			infile = open_file(av[1], 2);
			dup2(infile, 0);
		}
		while (i < ac - 2)
			process(av[i++], env);
		dup2(outfile, 1);
		execute(av[ac - 2], env);
	}
	else
		err_msg(0);
	return (0);
}
*/

int	process_here_doc(int ac, char **av, char **env)
{
	int	i;
	int	outfile;

	i = 3;
	outfile = open_file(av[ac - 1], 0);
	here_doc(av[2], ac);
	while (i < ac - 2)
	{
		process(av[i++], env);
	}
	dup2(outfile, 1);
	execute(av[ac - 2], env);
	return (0);
}

int	process_normal(int ac, char **av, char **env)
{
	int	i;
	int	infile;
	int	outfile;

	i = 2;
	outfile = open_file(av[ac - 1], 1);
	infile = open_file(av[1], 2);
	dup2(infile, 0);
	while (i < ac - 2)
	{
		process(av[i++], env);
	}
	dup2(outfile, 1);
	execute(av[ac - 2], env);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	if (ac >= 5)
	{
		if (ft_strncmp(av[1], "here_doc", 8) == 0)
		{
			return (process_here_doc(ac, av, env));
		}
		else
		{
			return (process_normal(ac, av, env));
		}
	}
	else
	{
		err_msg(0);
	}
	return (0);
}

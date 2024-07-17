/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:58:06 by tluanamn          #+#    #+#             */
/*   Updated: 2023/12/16 14:35:14 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_in(char **av, char **env, int *fd)
{
	int	infile;

	infile = open(av[1], O_RDONLY, 0777);
	if (infile == -1)
	{
		perror("Error in opening input file");
		exit(1);
	}
	dup2(fd[1], 1);
	dup2(infile, 0);
	close(fd[0]);
	close(fd[1]);
	close(infile);
	execute(av[2], env);
}

void	process_out(char **av, char **env, int *fd)
{
	int	outfile;

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
		perror("Error in opening output file");
		exit(1);
	}
	dup2(fd[0], 0);
	dup2(outfile, 1);
	close(fd[0]);
	close(fd[1]);
	close(outfile);
	execute(av[3], env);
}

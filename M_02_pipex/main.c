/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:13:12 by tluanamn          #+#    #+#             */
/*   Updated: 2023/12/16 14:34:50 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	p;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
		{
			perror("Error in pipe creation");
			exit(1);
		}
		p = fork();
		if (p == -1)
		{
			perror("Error");
			exit(1);
		}
		if (p == 0)
			process_in(av, env, fd);
		waitpid(p, NULL, 0);
		process_out(av, env, fd);
	}
	else
		ft_putstr_fd("Error\n", 2);
	return (0);
}

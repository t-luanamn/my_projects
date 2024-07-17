/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:13:24 by tluanamn          #+#    #+#             */
/*   Updated: 2023/12/16 14:34:37 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "./libft/libft.h"

char	*find_path(char *cmd, char **env);
void	execute(char *av, char **env);
void	process_in(char **av, char **env, int *fd);
void	process_out(char **av, char **env, int *fd);

//Bonus
void	err_msg(int e);
int		open_file(char *av, int i);
int		get_next_line(char **line);

#endif

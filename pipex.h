/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:27:25 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/07/22 18:46:57 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
    char	*path;
	char	**paths;
	char	*cmd_path;
    char    *cmd1;
    char    *cmd2;
    char    *infile;
    char    *outfile;
    int     pipefd[2];
    pid_t	pid1; 
    pid_t   pid2;
}t_pipex;

char	*find_path(t_pipex *pipex, char	**envp);

#endif
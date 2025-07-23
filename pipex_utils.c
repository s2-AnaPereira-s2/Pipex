/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:17:06 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/07/22 18:51:01 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(t_pipex *pipex, char	**envp)
{
	int	i;
	int check;

	i = 0;
	while (envp[i])
	{
		check = ft_strncmp(envp[i], "PATH=", 5);
		if (!check)
			break ;
		i++;
	}
	pipex->paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (pipex->paths[i])
	{
		pipex->path = ft_strjoin(pipex->paths[i], "/");
		pipex->cmd_path = ft_strjoin(pipex->path, pipex->cmd1);
		free(pipex->path);
		if (!access(pipex->cmd_path, X_OK))
			return (NULL);
		free(pipex->cmd_path);
		i++;
	}
	return (NULL);
}

void    handle_file(t_pipex *pipex)
{
    int infile_fd;
    int outfile_fd;
    

    infile_fd = open(pipex->infile, O_RDONLY);
    if (infile_fd < 0)
        perror("infile error");
    outfile_fd = pen(pipex->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (outfile_fd < 0)
        perror("outfile error");
    if (pipe(pipex->pipefd) == -1)
        perror("Pipe error");
    pipex->pid1 = fork();
    if (pipex->pid1 == 0)
        func_execute(pipex);
    pipex->pid2 = fork();
    if (pipex->pid2 == 0)
        func_execute(pipex);
}
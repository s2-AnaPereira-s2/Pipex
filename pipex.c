/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:27:37 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/07/22 18:25:54 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	main(int argc, char **argv, char **envp)
{
	t_pipex pipex;
	if (argc != 5)
		return (0);
	pipex.infile = argv[1];
	pipex.cmd1 = argv[2];
	pipex.cmd2 = argv[3];
	pipex.outfile = argv[4];
	find_path(&pipex, envp);
	
	return (0);
}

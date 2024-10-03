/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remidubenard <remidubenard@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:42:21 by rcorroy       #+#    #+#             */
/*   Updated: 2024/07/15 12:29:33 by rcorroy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_command(char *cmd, char **envp)
{
	char	*args[4];

	args[0] = "/bin/sh";
	args[1] = "-c";
	args[2] = cmd;
	args[3] = NULL;
	if (execve(args[0], args, envp) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}

void	create_pipe(int pipefd[2])
{
	if (pipe(pipefd) == -1)
		erreur("pipe", EXIT_FAILURE);
}

int	open_file(char *filename, int flags, mode_t mode)
{
	int	file;

	file = open(filename, flags, mode);
	if (file == -1)
		erreur("open", EXIT_FAILURE);
	return (file);
}

void	erreur(char *message, int flag)
{
	perror(message);
	exit(flag);
}

void	claw(t_pipex2 *pepe, pid_t cpid1, pid_t cpid2)
{
	close(pepe->pipefd[0]);
	close(pepe->pipefd[1]);
	close(pepe->infile);
	close(pepe->outfile);
	waitpid(cpid1, NULL, 0);
	waitpid(cpid2, NULL, 0);
}

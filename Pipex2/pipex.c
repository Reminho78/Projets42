/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remidubenard <remidubenard@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:42:25 by rcorroy       #+#    #+#             */
/*   Updated: 2024/07/15 12:48:19 by rcorroy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	hpc(t_pipex2 *pepe, char **argv, char **envp)
{
	pid_t	cpid1;
	pid_t	cpid2;

	cpid1 = fork();
	if (cpid1 == -1)
		erreur("fork", EXIT_FAILURE);
	if (cpid1 == 0)
	{
		close(pepe->pipefd[0]);
		ecp(argv[2], pepe->infile, pepe->pipefd[1], envp);
	}
	cpid2 = fork();
	if (cpid2 == -1)
		erreur("fork", EXIT_FAILURE);
	if (cpid2 == 0)
	{
		close(pepe->pipefd[1]);
		ecp(argv[3], pepe->pipefd[0], pepe->outfile, envp);
	}
	claw(pepe, cpid1, cpid2);
}

void	ecp(char *cmd, int input_fd, int output_fd, char **envp)
{
	if (dup2(input_fd, STDIN_FILENO) == -1
		|| dup2(output_fd, STDOUT_FILENO) == -1)
		erreur("dup2", EXIT_FAILURE);
	close(input_fd);
	close(output_fd);
	execute_command(cmd, envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex2	*pepe;

	pepe = malloc(sizeof(t_pipex2));
	if (pepe == NULL)
		erreur("malloc", EXIT_FAILURE);
	if (argc != 5)
	{
		ft_printf("Usage: %s infile cmd1 cmd2 outfile\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	pepe->infile = open_file(argv[1], O_RDONLY, 0);
	pepe->outfile = open_file(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	create_pipe(pepe->pipefd);
	hpc(pepe, argv, envp);
	return (0);
}

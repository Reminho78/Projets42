/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remidubenard <remidubenard@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:10:58 by remidubenar       #+#    #+#             */
/*   Updated: 2024/07/15 11:27:59 by remidubenar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_pipes(int num_pipes, int pipes[][2])
{
	int	i;

	i = 0;
	while (i < num_pipes)
	{
		if (pipe(pipes[i]) == -1)
			erreur("pipe", EXIT_FAILURE);
		i++;
	}
}

void	close_pipes(int num_pipes, int pipes[][2])
{
	int	i;

	i = 0;
	while (i < num_pipes)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}

void	fork_child(int i, int num_cmds, int pipes[][2], int infile, int outfile)
{
	if (i == 0)
	{
		dup2(infile, STDIN_FILENO);
		dup2(pipes[i][1], STDOUT_FILENO);
	}
	else if (i == num_cmds - 1)
	{
		dup2(pipes[i - 1][0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
	}
	else
	{
		dup2(pipes[i - 1][0], STDIN_FILENO);
		dup2(pipes[i][1], STDOUT_FILENO);
	}
	close_pipes(num_cmds - 1, pipes);
	close(infile);
	close(outfile);
}

void	fork_processes(int num_cmds, int pipes[][2], char **argv, char **envp, int infile, int outfile)
{
	pid_t	*cpids;
	int		i;

	cpids = malloc(num_cmds * sizeof(pid_t));
	i = 0;
	while (i < num_cmds)
	{
		cpids[i] = fork();
		if (cpids[i] == -1)
			erreur("fork", EXIT_FAILURE);
		if (cpids[i] == 0)
		{
			fork_child(i, num_cmds, pipes, infile, outfile);
			execute_command(argv[i + 2], envp);
		}
		i++;
	}
	close_pipes(num_cmds - 1, pipes);
	close(infile);
	close(outfile);
	
	i = 0;
	while (i < num_cmds)
	{
		waitpid(cpids[i], NULL, 0);
		i++;
	}
	free(cpids);
}

int	main(int argc, char **argv, char **envp)
{
	int	num_cmds;
	int	pipes[argc - 4][2];
	int	infile;
	int	outfile;

	if (argc < 5)
	{
		fprintf(stderr, "Usage: %s infile cmd1 cmd2 ... cmdn outfile\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	num_cmds = argc - 3;
	infile = open_file(argv[1], O_RDONLY, 0);
	outfile = open_file(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	create_pipes(num_cmds - 1, pipes);
	fork_processes(num_cmds, pipes, argv, envp, infile, outfile);
	return (0);
}

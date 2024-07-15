/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remidubenard <remidubenard@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:10:58 by remidubenar       #+#    #+#             */
/*   Updated: 2024/07/15 12:40:09 by remidubenar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fork_child_bonus(int i, t_pipex *yo)
{
	if (i == 0)
	{
		dup2(yo->infile, STDIN_FILENO);
		dup2(yo->pipes[i][1], STDOUT_FILENO);
	}
	else if (i == yo->num_cmds - 1)
	{
		dup2(yo->pipes[i - 1][0], STDIN_FILENO);
		dup2(yo->outfile, STDOUT_FILENO);
	}
	else
	{
		dup2(yo->pipes[i - 1][0], STDIN_FILENO);
		dup2(yo->pipes[i][1], STDOUT_FILENO);
	}
	close_pipes_bonus(yo->num_cmds - 1, yo->pipes);
	close(yo->infile);
	close(yo->outfile);
}

void	wait_and_cleanup_bonus(t_pipex *yo, pid_t *cpids)
{
	int	i;

	close_pipes_bonus(yo->num_cmds - 1, yo->pipes);
	close(yo->infile);
	close(yo->outfile);
	i = 0;
	while (i < yo->num_cmds)
	{
		waitpid(cpids[i], NULL, 0);
		i++;
	}
}

void	fork_processes_bonus(t_pipex *yo, char **argv, char **envp)
{
	pid_t	*cpids;
	int		i;

	cpids = (pid_t *)malloc(yo->num_cmds * sizeof(pid_t));
	if (cpids == NULL)
		erreur("malloc", EXIT_FAILURE);
	i = 0;
	while (i < yo->num_cmds)
	{
		cpids[i] = fork();
		if (cpids[i] == -1)
			erreur("fork", EXIT_FAILURE);
		if (cpids[i] == 0)
		{
			fork_child_bonus(i, yo);
			execute_command(argv[i + 2], envp);
		}
		i++;
	}
	wait_and_cleanup_bonus(yo, cpids);
	free(cpids);
}

void	free_resources_bonus(t_pipex *yo)
{
	int	i;

	i = 0;
	while (i < (yo->num_cmds - 1))
	{
		free(yo->pipes[i]);
		i++;
	}
	free(yo->pipes);
	free(yo);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*yo;
	int		i;

	yo = malloc(sizeof(t_pipex));
	if (yo == NULL)
		erreur("malloc", EXIT_FAILURE);
	i = 0;
	yo->num_cmds = argc - 3;
	yo->pipes = (int **)malloc((yo->num_cmds - 1) * sizeof(int *));
	if (yo->pipes == NULL)
		erreur("malloc", EXIT_FAILURE);
	while (i < (yo->num_cmds - 1))
	{
		yo->pipes[i] = (int *)malloc(2 * sizeof(int));
		if (yo->pipes[i] == NULL)
			erreur("malloc", EXIT_FAILURE);
		i++;
	}
	check_arguments_bonus(argc, argv);
	yo->infile = open_file(argv[1], O_RDONLY, 0);
	yo->outfile = open_file(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	create_pipes_bonus((yo->num_cmds - 1), yo->pipes);
	fork_processes_bonus(yo, argv, envp);
	free_resources_bonus(yo);
	return (0);
}

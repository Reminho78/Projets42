/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remidubenard <remidubenard@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:11:58 by remidubenar       #+#    #+#             */
/*   Updated: 2024/07/15 12:44:30 by remidubenar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct t_pipex
{
	int	**pipes;
	int	num_cmds;
	int	infile;
	int	outfile;
}	t_pipex;

typedef struct t_pipex2
{
	int	pipefd[2];
	int	infile;
	int	outfile;
}	t_pipex2;

void	execute_command(char *cmd, char **envp);
void	ecp(char *cmd, int input_fd, int output_fd, char **envp);
void	create_pipe(int pipefd[2]);
void	hpc(t_pipex2 *pepe, char **argv, char **envp);
int		open_file(char *filename, int flags, mode_t mode);
void	claw(t_pipex2 *pepe, pid_t cpid1, pid_t cpid2);
void	erreur(char *message, int flag);
void	fork_child_bonus(int i, t_pipex *yo);
void	wait_and_cleanup_bonus(t_pipex *yo, pid_t *cpids);
void	fork_processes_bonus(t_pipex *yo, char **argv, char **envp);
void	free_resources_bonus(t_pipex *yo);
void	create_pipes_bonus(int num_pipes, int **pipes);
void	close_pipes_bonus(int num_pipes, int **pipes);
void	check_arguments_bonus(int argc, char **argv);

#endif
// ecp = execute child process
// hpc = handle parent process
// claw = close_files_and_wait
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remidubenard <remidubenard@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:04:10 by remidubenar       #+#    #+#             */
/*   Updated: 2024/07/15 12:48:09 by remidubenar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_pipes_bonus(int num_pipes, int **pipes)
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

void	close_pipes_bonus(int num_pipes, int **pipes)
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

void	check_arguments_bonus(int argc, char **argv)
{
	if (argc < 5)
	{
		ft_printf("Usage: %s inf cmd1 cmd2...cmdn outf\n", argv[0]);
		exit(EXIT_FAILURE);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:35:41 by junseyun          #+#    #+#             */
/*   Updated: 2024/07/24 17:40:06 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_header.h"

void	free_child(t_pipe_vars *vars)
{
	int	i;

	i = 0;
	while (vars->argv_cmd[i])
	{
		free(vars->argv_cmd[i]);
		i++;
	}
	free(vars->argv_cmd);
	free(vars->cmd);
}

void	free_parent(t_pipe_vars *vars)
{
	int	i;

	i = 0;
	close(vars->input_file);
	close(vars->output_file);
	while (vars->cmd_paths[i])
	{
		free(vars->cmd_paths[i]);
		i++;
	}
	free(vars->cmd_paths);
}

void	free_str(char **res, int i)
{
	int	j;

	j = 0;
	while (j <= i)
		free(res[j++]);
	free(res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:35:25 by junseyun          #+#    #+#             */
/*   Updated: 2024/07/30 21:38:05 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_header.h"

static char	*combine_cmd(char **paths, char *cmd)
{
	char	*temp;
	char	*command;

	while (*paths)
	{
		temp = ft_strjoin(*paths, "/");
		command = ft_strjoin(temp, cmd);
		free(temp);
		if (access(command, X_OK) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void	first_child(t_pipe_vars vars, char **argv, char **envp)
{
	dup2(vars.fd[1], 1);
	close(vars.fd[0]);
	if (argv[2][0] == 32 || argv[2][0] == 0)
	{
		free_parent(&vars);
		exit(1);
	}
	vars.argv_cmd = ft_split(argv[2], ' ');
	if (access(vars.argv_cmd[0], X_OK) == 0)
		execve(vars.argv_cmd[0], vars.argv_cmd, envp);
	else
	{
		vars.argv_cmd = ft_split(argv[2], ' ');
		vars.cmd = combine_cmd(vars.cmd_paths, vars.argv_cmd[0]);
	}
	if (!(vars.cmd))
	{
		free_child(&vars);
		exception_msg(ERR_CMD);
		exit(1);
	}
	execve(vars.cmd, vars.argv_cmd, envp);
}

void	second_child(t_pipe_vars vars, char **argv, char **envp)
{
	dup2(vars.fd[0], 0);
	close(vars.fd[1]);
	if (argv[3][0] == 32 || argv[3][0] == 0)
	{
		free_parent(&vars);
		exit(1);
	}
	vars.argv_cmd = ft_split(argv[3], ' ');
	if (access(vars.argv_cmd[0], X_OK) == 0)
		execve(vars.argv_cmd[0], vars.argv_cmd, envp);
	else
	{
		vars.argv_cmd = ft_split(argv[3], ' ');
		vars.cmd = combine_cmd(vars.cmd_paths, vars.argv_cmd[0]);
	}
	if (!(vars.cmd))
	{
		free_child(&vars);
		exception_msg(ERR_CMD);
		exit(1);
	}
	execve(vars.cmd, vars.argv_cmd, envp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:35:38 by junseyun          #+#    #+#             */
/*   Updated: 2024/07/24 17:39:47 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_header.h"

static void	close_all(t_pipe_vars *vars)
{
	close(vars->fd[0]);
	close(vars->fd[1]);
}

static void	open_files(char **argv, t_pipe_vars *vars)
{
	vars->input_file = open(argv[1], O_RDONLY);
	if (vars->input_file < 0)
		exception_err_msg(ERR_INPUTFILE);
	dup2(vars->input_file, 0);
	vars->output_file = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0777);
	if (vars->output_file < 0)
		exception_err_msg(ERR_OUTPUTFILE);
	dup2(vars->output_file, 1);
}

static char	*find_paths(char **envp, t_pipe_vars *vars)
{
	int	flag;

	flag = 0;
	while (*envp)
	{
		if (ft_strnstr(*envp, "PATH=", 5) != 0)
		{
			flag = 1;
			break ;
		}
		envp++;
	}
	if (flag == 0)
	{
		exception_msg(ERR_ENVP);
		close_all(vars);
		close(vars->input_file);
		close(vars->output_file);
		exit(1);
	}
	return (*envp + 5);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe_vars	vars;

	if (argc != 5)
		return (exception_msg(ERR_ARGC));
	open_files(argv, &vars);
	if (pipe(vars.fd) < 0)
		exception_err_msg(ERR_PIPE);
	vars.paths = find_paths(envp, &vars);
	vars.cmd_paths = ft_split(vars.paths, ':');
	vars.pid1 = fork();
	if (vars.pid1 == 0)
		first_child(vars, argv, envp);
	vars.pid2 = fork();
	if (vars.pid2 == 0)
		second_child(vars, argv, envp);
	close_all(&vars);
	waitpid(vars.pid1, NULL, 0);
	waitpid(vars.pid2, NULL, 0);
	free_parent(&vars);
	return (0);
}

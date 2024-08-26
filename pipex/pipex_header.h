/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_header.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:17:28 by junseyun          #+#    #+#             */
/*   Updated: 2024/07/24 17:45:10 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_HEADER_H
# define PIPEX_HEADER_H

# define ERR_ARGC "Invalid argument count !!\n"
# define ERR_ENVP "Invalid envp value !!\n"
# define ERR_PIPE "Fail pipe create \n"
# define ERR_INPUTFILE "Fail open input file !!\n"
# define ERR_OUTPUTFILE "Fail open output file !!\n"
# define ERR_CMD "Invalid command\n"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

typedef struct s_pipe
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		input_file;
	int		output_file;
	char	*paths;
	char	*cmd;
	char	**cmd_paths;
	char	**argv_cmd;
}	t_pipe_vars;

char	*single_quote_idx(char *s);
int		check_sep(char c, char sep);
int		single_quote_word_len(char *s);
int		single_quote_count_word(char *str, char c);
void	free_str(char **res, int i);
void	free_child(t_pipe_vars *vars);
void	free_parent(t_pipe_vars *vars);
void	first_child(t_pipe_vars vars, char **argv, char **envp);
void	second_child(t_pipe_vars vars, char **argv, char **envp);
void	exception_err_msg(char *str);
int		exception_msg(char *str);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
char	**ft_split(char *str, char c);
size_t	ft_strlen(const char *s);

#endif

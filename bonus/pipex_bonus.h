/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:45:45 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/18 15:08:50 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include "../libft/libft.h"
# include  <unistd.h>
# include <fcntl.h>
# include "errno.h"
# include <sys/wait.h>

# define ERR_CMD "Command not found\n"
# define READ_END 0
# define WRITE_END 1

typedef struct s_parse
{
	char	*path;
	char	**dir;
}	t_parse;

typedef struct s_file
{
	char	*file;
}	t_file;

typedef struct s_cmd
{
	char	**cmd;
	t_file	file;
}	t_cmd;

typedef struct s_pipe
{
	int	pipe[2];
	int	pid;
}	t_pipe;

typedef struct s_data
{
	int		argc;
	char	**argv;
	char	**envp;
	t_pipe	*pipes;
	t_file	input;
	t_file	output;
	int		status;
}	t_data;

char	*get_path(char **envp);
char	**get_dir(char *path);
t_data	init_data(int argc, char **argv, char **envp);
char	*get_file(t_parse parse, t_data data, int size);
char	*get_exec_file(t_parse parse, t_cmd *cmd, t_data data);
void	free_pointers(t_parse parse);
t_parse	init_parsing_values(void);
void	init_args(t_cmd **cmd, t_data data);
void	skip_space(t_file file, int j);
void	init_pipes(t_data *data);
void	close_pipes(t_data *data);
void	get_data_files(t_data *data);
void	get_multiple_files(t_parse parse, t_data data, t_cmd *cmd, int size);
void	execute_command(t_data *data, t_cmd *cmd, int child_number);
void	redirect_io(int input, int output);
void	redirect_pipes(t_data **data, int child_number);
int		err_handle(char *msg);
char	*different_format(t_file file, char *tmp, char *argv);

#endif
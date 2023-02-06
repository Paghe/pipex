/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:20:21 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/06 00:44:10 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include "libft/libft.h"
# include  <unistd.h>
# include <fcntl.h>

# define ERR_CMD "Command not found\n"
# define READ_END 0
# define WRITE_END 1

typedef struct s_input_data
{
	int			argc;
	char		**argv;
	char		**envp;
	pid_t		pid[2];
	int			error_data;
}				t_input_data;

typedef struct s_data_object
{
	int		input_file;
	int		output_file;
}				t_data_object;

typedef struct s_cmd
{
	char	**cmd;
	char	*file;
}			t_cmd;

t_input_data	init_input(int argc, char **argv, char **envp);
int				err_fork(void);
int				err_handle(char *msg);
void			child1(t_data_object *object, int **pipe0, t_input_data *data, t_cmd *cmd);
void			child2(t_data_object *object, int **pipe0, t_input_data *data, t_cmd *cmd);
t_data_object	init_object(void);
char			*get_path(char **envp);
char			**get_dir(char *path, char split);
char			*exec_file(char **path, char *argv);
t_cmd			*init_args(t_cmd *cmd, t_input_data data);
char			*get_file(char **envp, char *argv);
void			free_cmd(char **cmd);
int				error_msg(char *msg);
int				argv_error(char **argv);
void			free_cmds(char **cmd1, char **cmd2);
void			init_pipe(int *pipe0, t_input_data data, t_data_object *object);

#endif
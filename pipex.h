/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:20:21 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/14 20:41:22 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include "libft/libft.h"
# include  <unistd.h>
# include <fcntl.h>
# include "errno.h"
# include <sys/wait.h>

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
	int			status;
}				t_input_data;

typedef struct s_data_object
{
	int		i;
	int		o;
}				t_data_object;

typedef struct s_cmd
{
	char	**cmd;
	char	*file;
}			t_cmd;

t_input_data	init_input(int argc, char **argv, char **envp);
int				err_fork(void);
int				err_handle(char *msg);
void			child1(t_data_object *object, int **pipe0, \
						t_input_data *data, t_cmd *cmd);
void			child2(t_data_object *object, int **pipe0, \
						t_input_data *data, t_cmd *cmd);
t_data_object	init_object(void);
char			*get_path(char **envp);
char			**get_dir(char *path, char split);
char			*check_file(char **path, char *argv);
void			init_args(t_cmd **cmd, t_input_data data);
char			*get_file(char **envp, char *argv);
void			free_cmd(char **cmd);
int				error_msg(char *msg);
int				argv_error(char **argv);
void			free_cmds(char **cmd1, char **cmd2);
void			init_pipe(int *pipe0, t_input_data data, t_data_object *object);
char			*different_format(char *file, char *tmp, char *argv);
int				err_pipe(int *pipe);
void			open_files(t_input_data data, t_data_object *object);
void			close_files(t_data_object *obj);
void			close_pipes(int *pipe0);
void			init_child1(t_data_object *obj, int **pipe, \
						t_input_data *data, t_cmd *cmd);
void			init_child2(t_data_object *object, int **pipe0, \
						t_input_data *data, t_cmd *cmd);
char			*ft_strjoin_pipex(char *s, char *s2);
char			*ft_strdup_pipex(char *s1);

#endif
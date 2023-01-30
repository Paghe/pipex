/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:20:21 by apaghera          #+#    #+#             */
/*   Updated: 2023/01/30 21:15:38 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include "libft/libft.h"
# include  <unistd.h>
# include <fcntl.h>

typedef struct s_input_data
{
	int			argc;
	char		**argv;
	char		**envp;
}				t_input_data;

typedef struct s_data_object
{
	int		input_file;
	int		output_file;
}				t_data_object;

typedef struct s_cmd
{
	char	*cmd;
	char	*cmd1;
}			t_cmd;

t_input_data	create_input(int argc, char **argv, char **envp);
int				err_handle(void);
void	child1(int input_file_fd, int pipe0[2], t_input_data data, char *cmd);
void			child2(int output_file, int pipe0[2], t_input_data data, char *cmd, char *option);
t_data_object	create_object(void);
char			*get_path(char **envp);
char			**get_commands(char *path, char split);
char			*exec_cmd(char **path, char *argv);
char			*get_args(char	*data);

#endif
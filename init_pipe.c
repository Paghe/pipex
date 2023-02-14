/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:19:09 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/14 20:01:13 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	init_pipe(int *pipe0, t_input_data data, t_data_object *object)
// {

// }

void	init_child1(t_data_object *object, int **pipe0, \
						t_input_data *data, t_cmd *cmd)
{
	char	**args;

	args = cmd[0].cmd;
	if (cmd->file == NULL)
	{
		error_msg(ERR_CMD);
		exit(127);
	}
	if (object -> i == -1)
		exit(1);
	if (dup2(object -> i, STDIN_FILENO) == -1)
		exit(EXIT_FAILURE);
	if (dup2((*pipe0)[WRITE_END], STDOUT_FILENO) == -1)
		exit(EXIT_FAILURE);
	close_files(object);
	close_pipes(*pipe0);
	if (execve(cmd -> file, args, data->envp) == -1)
		err_handle("execve error: ");
	free_cmd(args);
	exit(0);
}

void	init_child2(t_data_object *object, int **pipe0, \
						t_input_data *data, t_cmd *cmd)
{
	char	**args;

	args = cmd[1].cmd;
	if (cmd->file == NULL)
	{
		error_msg(ERR_CMD);
		exit(127);
	}
	if (object -> o < 0)
		exit(1);
	if (dup2((*pipe0)[READ_END], STDIN_FILENO) == -1)
		exit(EXIT_FAILURE);
	if (dup2(object -> o, STDOUT_FILENO) == -1)
		exit(EXIT_FAILURE);
	if (ft_strnstr(args[0], "exit", ft_strlen(args[0])) != NULL)
		exit(ft_atoi(args[1]));
	close_files(object);
	close_pipes(*pipe0);
	if (execve(cmd->file, args, data->envp) == -1)
		err_handle("execve error: ");
	free_cmd(args);
	exit(0);
}

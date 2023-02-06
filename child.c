/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:54:54 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/06 01:39:26 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "errno.h"
#define READ_END 0
#define WRITE_END 1

void	child1(t_data_object *object, int **pipe0, t_input_data *data, t_cmd *cmd)
{
	char			**args;

	args = cmd[0].cmd;

	data->pid[0] = fork();
	if (data->pid[0] == -1)
		err_handle("Fork: ");
	if (data->pid[0] == 0)
	{
		if (cmd->file == NULL)
		{
			error_msg(ERR_CMD);
			exit(127);
		}
		if (object -> input_file == -1)
			exit(1);
		dup2(object -> input_file, STDIN_FILENO);
		if (dup2((*pipe0)[WRITE_END], STDOUT_FILENO) == -1)
			exit(EXIT_FAILURE);
		close(object -> input_file);
		close(object -> output_file);
		close((*pipe0)[READ_END]);
		close((*pipe0)[WRITE_END]);
		if(execve(cmd -> file, args, data->envp) == 0)
			exit(1);
	}
}

void	child2(t_data_object *object, int **pipe0, t_input_data *data, t_cmd *cmd)
{
	char			**args;

	args = cmd[1].cmd;
	data->pid[1] = fork();
	if (data->pid[1] == -1)
		err_handle("Fork: ");
	if (data->pid[1] == 0)
	{
		if (cmd->file == NULL)
		{
			error_msg(ERR_CMD);
			exit(127);
		}
		if (object -> output_file < 0)
			exit(1);
		dup2((*pipe0)[READ_END], STDIN_FILENO);
		if (dup2(object -> output_file, STDOUT_FILENO) == -1)
			exit(EXIT_FAILURE);
		if (ft_strnstr(args[0], "exit", ft_strlen(args[0])) != NULL)
			exit(ft_atoi(args[1]));
		close(object -> output_file);
		close(object -> input_file);
		close((*pipe0)[WRITE_END]);
		close((*pipe0)[READ_END]);
		if (execve(cmd->file, args, data->envp) == -1)
			exit(1); //exit(0) fail less test
	}
}

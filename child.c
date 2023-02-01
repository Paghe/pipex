/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:54:54 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/01 19:23:27 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#define READ_END 0
#define WRITE_END 1

int	child1(int input, int pipe0[2], t_input_data data, t_cmd *cmd)
{
	char	**args;

	args = cmd[0].cmd;
	if (!args)
	{
		free_cmd(cmd[0].cmd);
		free_cmd(cmd[1].cmd);
		error_msg(ERR_CMD);
		exit(1);
	}
	input = open(data.argv[1], O_RDONLY);
	if (input < 0)
		return (-1);
	if (dup2(input, STDIN_FILENO) < 0)
		return (-1);
	if (dup2(pipe0[WRITE_END], STDOUT_FILENO) < 0)
		return (-1);
	close(pipe0[READ_END]);
	close(pipe0[WRITE_END]);
	close(input);
	if (execve(cmd -> file, args, data.envp) < 0)
	{
		free_cmd(cmd[0].cmd);
		exit (1);
	}	
	return (0);
}

int	child2(int output, int pipe0[2], t_input_data data, t_cmd *cmd)
{
	char			**args;

	args = cmd[1].cmd;
	if (!args)
	{
		free_cmd(cmd[0].cmd);
		free_cmd(cmd[1].cmd);
		error_msg(ERR_CMD);
		exit(1);
	}
	output = open(data.argv[data.argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output < 0)
		return (-1);
	if (dup2(pipe0[READ_END], STDIN_FILENO) < 0)
		return (-1);
	if (dup2(output, STDOUT_FILENO) < 0)
		return (-1);
	close(output);
	close(pipe0[WRITE_END]);
	close(pipe0[READ_END]);
	if (execve(cmd -> file, args, data.envp) < 0)
	{
		free_cmd(cmd[1].cmd);
		exit (1);
	}	
	return (0);
}

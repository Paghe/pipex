/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:54:54 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/05 16:41:30 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "errno.h"
#define READ_END 0
#define WRITE_END 1

void	child1(int input, int pipe0[2], t_input_data *data, t_cmd *cmd)
{
	char			**args;

	args = cmd[0].cmd;

	if (!args)
	{
		free_cmd(cmd[0].cmd);
		free_cmd(cmd[1].cmd);
		error_msg(ERR_CMD);
		exit(EXIT_FAILURE);
	}
	data->pid[0] = fork();
	if (data->pid[0] == 0)
	{
		input = open(data->argv[1], O_RDONLY);
		if (input == -1)
			exit(1);
		if (dup2(input, STDIN_FILENO) == -1)
			exit(0);
		close(input);
		if (dup2(pipe0[WRITE_END], STDOUT_FILENO) == -1)
			exit(EXIT_FAILURE);
		close(pipe0[READ_END]);
		close(pipe0[WRITE_END]);
		execve(cmd -> file, args, data->envp);
		exit(0);
	}
}

void	child2(int output, int pipe0[2], t_input_data *data, t_cmd *cmd)
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
	data->pid[1] = fork();
	if (data->pid[1] == 0)
	{
		output = open(data->argv[data->argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (output < 0)
			exit(1);
		if (dup2(pipe0[READ_END], STDIN_FILENO) == -1)
			exit(0);
		if (dup2(output, STDOUT_FILENO) == -1)
			exit(EXIT_FAILURE);
		close(output);
		if (ft_strnstr(args[0], "exit", ft_strlen(args[0])) != NULL)
			exit(ft_atoi(args[1]));
		close(pipe0[WRITE_END]);
		close(pipe0[READ_END]);
		if (execve(cmd->file, args, data->envp) == -1)
			exit(1); //exit(0) fail less test
		exit(0);
	}
}

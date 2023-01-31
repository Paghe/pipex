/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:54:54 by apaghera          #+#    #+#             */
/*   Updated: 2023/01/31 15:39:14 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#define READ_END 0
#define WRITE_END 1

void	child1(int input_file_fd, int pipe0[2], t_input_data data, t_cmd *cmd)
{
	char	**args;

	args = cmd[0].cmd;
	input_file_fd = open(data.argv[1], O_RDONLY);
	if (input_file_fd < 0)
		return ;
	dup2(input_file_fd, STDIN_FILENO);
	dup2(pipe0[WRITE_END], STDOUT_FILENO);
	close(pipe0[READ_END]);
	close(pipe0[WRITE_END]);
	close(input_file_fd);
	execve(cmd -> file, args, data.envp);
}

void	child2(int output_file_fd, int pipe0[2], t_input_data data, t_cmd *cmd)
{
	char			**args;

	args = cmd[1].cmd;
	output_file_fd = open(data.argv[data.argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_file_fd < 0)
		return ;
	dup2(pipe0[READ_END], STDIN_FILENO);
	dup2(output_file_fd, STDOUT_FILENO);
	close(output_file_fd);
	close(pipe0[WRITE_END]);
	close(pipe0[READ_END]);
	execve(cmd -> file, args, data.envp);
}

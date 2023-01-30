/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:54:54 by apaghera          #+#    #+#             */
/*   Updated: 2023/01/30 21:15:16 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#define READ_END 0
#define WRITE_END 1

void	child1(int input_file_fd, int pipe0[2], t_input_data data, char *cmd)
{
	char	*cat_args[3];

	cat_args[0] = cmd;
	cat_args[1] = get_args(data.argv[2]);
	cat_args[2] = NULL;
	input_file_fd = open(data.argv[1], O_RDONLY);
	if (input_file_fd < 0)
		return ;
	dup2(input_file_fd, STDIN_FILENO);
	dup2(pipe0[WRITE_END], STDOUT_FILENO);
	close(pipe0[READ_END]);
	close(pipe0[WRITE_END]);
	close(input_file_fd);
	execve(cmd, cat_args, data.envp);
}

void	child2(int output_file_fd, int pipe0[2], t_input_data data, char *cmd, char *option)
{
	char			*args[3];

	args[0] = cmd;
	args[1] = option;
	args[2] = NULL;
	output_file_fd = open(data.argv[data.argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_file_fd < 0)
		return ;
	dup2(pipe0[READ_END], STDIN_FILENO);
	dup2(output_file_fd, STDOUT_FILENO);
	close(output_file_fd);
	close(pipe0[WRITE_END]);
	close(pipe0[READ_END]);
	execve(cmd, args, data.envp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:27:56 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/06 01:27:56 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int				*pipe0;
	t_input_data	data;
	t_data_object	object2;
	t_data_object	*object;

	pipe0 = (int *)malloc(sizeof(int) * 2);
	data = init_input(argc, argv, envp);
	object2 = init_object();
	object = &object2;
	t_cmd			*cmd;
	int				status;

	if (pipe(pipe0) == -1)
	{
		err_handle("pipe error");
		close(pipe0[0]);
		close(pipe0[1]);
		exit(1);
	}
	cmd = NULL;
	cmd = init_args(cmd, data);
	object->input_file = open(data.argv[1], O_RDONLY);
	object->output_file = open(data.argv[data.argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	cmd -> file = get_file(data.envp, data.argv[2]);
	child1(object, &pipe0, &data, cmd);
	cmd -> file = get_file(data.envp, data.argv[3]);
	child2(object, &pipe0, &data, cmd);
	close(object->input_file);
	close(object->output_file);
	close(pipe0[READ_END]);
	close(pipe0[WRITE_END]);
	waitpid(data.pid[1], &status, 0);
	free_cmd(cmd[0].cmd);
	free_cmd(cmd[1].cmd);
	exit(WEXITSTATUS(status));
}
/* STDIN -> FIle1 -> cat -> [1] PIPE [0] < -- grep x --> FILE2 -> STDOUT

Pipe -> Communication channel between proccesses

step1:	file1 <- cat -> pipe0[WRITE]
step2:   pipe0[READ] <- grep -> pipe1[WRITE]
step2:   pipe1[READ] <- grep -> pipe2[WRITE]
step2:   pipe2[READ] <- grep -> pipe3[WRITE]
step3	  pipe3[READ] <- cat -e -> file2

step    file     file_descriptor
infile  infile   file_input
cat     infile   stdin 
cat     pipe[1]  stdout 
grep    pipe[0]  stdin
grep    outfile  stdoutw */

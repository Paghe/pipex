/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:27:56 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/14 20:43:34 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int				*pipe0;
	t_input_data	data;
	t_data_object	obj2;
	t_data_object	*obj;
	t_cmd			*cmd;

	pipe0 = (int *)malloc(sizeof(int) * 2);
	data = init_input(argc, argv, envp);
	obj2 = init_object();
	obj = &obj2;
	if (pipe(pipe0) == -1)
		err_pipe(pipe0);
	cmd = NULL;
	init_args(&cmd, data);
	open_files(data, obj);
	cmd[0].file = get_file(data.envp, data.argv[2]);
	child1(obj, &pipe0, &data, cmd);
	free(cmd[0].file);
	free_cmd(cmd[0].cmd);
	cmd -> file = get_file(data.envp, data.argv[3]);
	child2(obj, &pipe0, &data, cmd);
	free(cmd[1].file);
	free_cmd(cmd[1].cmd);
	close_files(obj);
	close_pipes(pipe0);
	waitpid(data.pid[1], &data.status, 0);
	system("leaks pipex");
	exit(WEXITSTATUS(data.status));
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

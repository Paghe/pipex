/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:27:56 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/02 17:37:20 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#define READ_END 0
#define WRITE_END 1

int	main(int argc, char **argv, char **envp)
{
	int				pipe0[2];
	t_input_data	data;
	pid_t			pid[2];
	t_data_object	object;
	t_cmd			*cmd;
	int				status;

	data = create_input(argc, argv, envp);
	object = create_object();
	argv_error(data.argv);
	cmd = NULL;
	cmd = get_args(cmd, data);
	if (data.argc != 5)
		err_handle();
	if (pipe(pipe0) == -1)
		err_handle();
	pid[0] = fork();
	if (pid[0] < 0)
		return (err_fork());
	if (pid[0] == 0)
	{
		cmd -> file = get_file(data.envp, data.argv[2]);
		child1(object.input_file, pipe0, data, cmd);
	}
	pid[1] = fork();
	if (pid[1] < 0)
		return (err_fork());
	if (pid[1] == 0)
	{
		cmd -> file = get_file(data.envp, data.argv[3]);
		child2(object.output_file, pipe0, data, cmd);
	}
	close(pipe0[READ_END]);
	close(pipe0[WRITE_END]);
 	waitpid(pid[0], &status, 0); 
	waitpid(pid[1], &status, 0);
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

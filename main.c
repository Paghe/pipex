/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:27:56 by apaghera          #+#    #+#             */
/*   Updated: 2023/01/25 17:50:19 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

# define READ_END 0
# define WRITE_END 1

int	main(int argc, char **argv, char **envp)
{
	int				pipe0[2];
	int				pipe1[2];
	char			*args[3];
	char			*cat_args[2];
	char			*cate_args[3];
	t_input_data	data;
	int				check;
	pid_t			pid;
	pid_t			pid2;
	pid_t			pid3;
	int				input_file_fd;
	int				output_file_fd;

	data = create_input(argc, argv, envp);
	if (data.argc < 5)
		err_handle();
	check = pipe(pipe0);
	if (check == -1)
		err_handle();
	pid = fork();
	args[0] = "/usr/bin/grep";
	args[1] = "s";
	args[2] = NULL;
	cat_args[0] = "/bin/cat";
	cat_args[1] = NULL;
	cate_args[0] = "cat";
	cate_args[1] = "-e";
	cate_args[2] = NULL;
	pipe(pipe1);
	if (pid == 0)
	{
		input_file_fd = open(argv[1], O_RDONLY);
		dup2(input_file_fd, STDIN_FILENO);
		dup2(pipe0[WRITE_END], STDOUT_FILENO);
		close(input_file_fd);
		close(pipe0[READ_END]);
		close(pipe0[WRITE_END]);
		close(pipe1[READ_END]);
		close(pipe1[WRITE_END]);
		execve("/usr/bin/grep", args, envp);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(pipe0[READ_END], STDIN_FILENO);
		dup2(pipe1[WRITE_END], STDOUT_FILENO);
		close(pipe0[0]);
		close(pipe0[1]);
		close(pipe1[0]);
		close(pipe1[1]);
		execve("/bin/cat", cate_args, envp);
	}
	pid3 = fork();
	if (pid3 == 0)
	{
		output_file_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(pipe1[READ_END], STDIN_FILENO);
		dup2(output_file_fd, STDOUT_FILENO);
		close(output_file_fd);
		close(pipe0[0]);
		close(pipe0[1]);
		close(pipe1[0]);
		close(pipe1[1]);
		execve("/bin/cat", cate_args, envp);
	}
	close(pipe0[0]);
	close(pipe0[1]);
	close(pipe1[0]);
	close(pipe1[1]);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
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
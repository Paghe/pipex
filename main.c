/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:27:56 by apaghera          #+#    #+#             */
/*   Updated: 2023/01/23 15:24:23 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int				fd;
	int				i;
	int				current_out;
	char			*args[2];
	t_input_data	data;

	data = create_input(argc, argv, envp);
	if (data.argc < 5)
		printf("BULLSHIT\n");
	// args[0] = "bullshit";
	// args[1] = NULL;
	// // if (argc < 1)
	// // 	return (0);
	// pid_t pid = fork();
	// if (pid == 0)
	// {
	// fd = open("file1", O_RDONLY);
	// int fd2 = open("file2", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// //setbuf(stdout, NULL);
	// //current_out = dup(STDOUT_FILENO);
	// dup2(fd, STDIN_FILENO);
	// dup2(fd2, STDOUT_FILENO);
	// close(fd);
	// close(fd2);
	// // dup2(current_out, STDOUT_FILENO);
	// printf("HI I AM THE child\nChild pid: %d\n", pid);
	// fflush(stdout);
	// execve("/bin/cat", args, envp);
	// }
	// printf("HI I AM THE PARENT\nChild pid: %d", pid);
	return (0);
}

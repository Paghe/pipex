/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:14:10 by apaghera          #+#    #+#             */
/*   Updated: 2023/01/31 12:07:05 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		if (envp[i] == ft_strnstr(envp[i], "PATH", 4))
		{
			path = envp[i];
			printf("path : %s\n", path);
		}	
		i++;
	}	
	return (path);
}

char	**get_dir(char *path, char split)
{
	char	**cmd;
	int		i;

	cmd = ft_split(path + 5, split);
	i = 0;
	while (cmd[i])
	{
		printf("dir: %s\n", cmd[i]);
		i++;
	}	
	return (cmd);
}

char	*exec_file(char **path, char *argv)
{
	char	*tmp;
	int		i;
	char	*file;
	int		j;

	i = 0;
	j = 0;
	while (path[i])
	{
		j = 0;
		tmp = ft_strjoin(path[i], "/");
		file = ft_strjoin(tmp, argv);
		while (file[j] != ' ')
			j++;
		file[j] = '\0';
		free(tmp);
		if (access(file, 0) == 0)
		{
			printf("file: %s\n", file);
			return (file);
		}	
		i++;
	}
	return (NULL);
}

char	*get_file(char **envp, char *argv)
{
	char	*path;
	char	**dir;
	char	*file;

	path = get_path(envp);
	dir = get_dir(path, ':');
	file = exec_file(dir, argv);
	return (file);
}

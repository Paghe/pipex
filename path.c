/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:14:10 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/14 20:17:21 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	if (!envp | !*envp)
		exit(EXIT_FAILURE);
	while (envp[i])
	{
		if (envp[i] == ft_strnstr(envp[i], "PATH", 4))
			path = ft_strdup(envp[i]);
		i++;
	}
	return (path);
}

char	**get_dir(char *path, char split)
{
	char	**dir;

	if (!path)
		return (NULL);
	dir = ft_split(path + 5, split);
	return (dir);
}

char	*check_file(char **dir, char *argv)
{
	char	*tmp;
	int		i;
	char	*file;
	int		j;

	i = 0;
	j = 0;
	while (dir[i])
	{
		j = 0;
		tmp = ft_strjoin(dir[i], "/");
		if (ft_strrchr(argv, '/') && (*(ft_strrchr(argv, '/') + 1)) != '\0')
			file = different_format(file, tmp, argv);
		else
			file = ft_strjoin(tmp, argv);
		while (file[j] && file[j] != ' ')
			j++;
		file[j] = '\0';
		free(tmp);
		if (access(file, X_OK) == 0)
			return (file);
		free(file);
		i++;
	}
	return (NULL);
}

char	*get_file(char **envp, char *argv)
{
	char	*path;
	char	**dir;
	char	*file;

	file = NULL;
	path = get_path(envp);
	dir = get_dir(path, ':');
	free(path);
	file = check_file(dir, argv);
	free_cmd(dir);
	return (file);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:55:24 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/14 14:20:57 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_files(t_input_data data, t_data_object *obj)
{
	obj->i = open(data.argv[1], O_RDONLY);
	obj->o = open(data.argv[data.argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
}

void	close_files(t_data_object *obj)
{
	close(obj->i);
	close(obj->o);
}

void	close_pipes(int *pipe0)
{
	close(pipe0[READ_END]);
	close(pipe0[WRITE_END]);
}

char	*ft_strjoin_pipex(char *s, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s)
	{
		s = ft_calloc(sizeof(char), 1);
		s[0] = '\0';
	}
	s3 = ft_calloc(sizeof(char), ft_strlen(s) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	while (s[++i])
		s3[i] = s[i];
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free(s);
	return (s3);
}

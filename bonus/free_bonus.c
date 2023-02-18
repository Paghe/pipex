/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:42:29 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/18 15:05:56 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_pointers(t_parse parse)
{
	int	i;

	i = 0;
	while (parse.dir[i])
	{
		free(parse.dir[i]);
		i++;
	}
	free(parse.dir);
}

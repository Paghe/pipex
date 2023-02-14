/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:37:39 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/14 15:32:32 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*different_format(char *file, char *tmp, char *argv)
{
	file = ft_strjoin(tmp, ft_strrchr(argv, '/'));
	return (file);
}

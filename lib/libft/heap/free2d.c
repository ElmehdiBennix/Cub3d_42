/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 21:11:15 by ebennix           #+#    #+#             */
/*   Updated: 2023/11/13 13:04:56 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lib_42.h"

char	**free2d(char **array)
{
	int		i;

	i = -1;
	if (array == NULL)
		return (NULL);
	while (array[++i])
	{
		if(array[i] != NULL)
		{
			free(array[i]);
			array[i] = NULL;
		}
	}
	free(array);
	array = NULL;
	return (array);
}

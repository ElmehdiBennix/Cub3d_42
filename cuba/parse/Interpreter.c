/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:49:33 by ebennix           #+#    #+#             */
/*   Updated: 2023/12/05 19:13:54 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	plus_check(t_data *game, int i, int j)
{
	int	check;

	check = 0;
	if (game->map[i + 1][j] == '1' || game->map[i + 1][j] == '0' || game->map[i
		+ 1][j] == game->player_info.direction)
		check++;
	if (game->map[i - 1][j] == '1' || game->map[i - 1][j] == '0' || game->map[i
		- 1][j] == game->player_info.direction)
		check++;
	if (game->map[i][j + 1] == '1' || game->map[i][j + 1] == '0'
		|| game->map[i][j + 1] == game->player_info.direction)
		check++;
	if (game->map[i][j - 1] == '1' || game->map[i][j - 1] == '0'
		|| game->map[i][j - 1] == game->player_info.direction)
		check++;
	return (check);
}

static bool	first_line(char *line)
{
	int	i;

	i = 0;
	if (!line || !line[0])
		return (false);
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

void	boundary_check_helper(t_data *game, t_var *var)
{
	while (game->map[++var->i] && (unsigned int)var->i < game->map_height - 1)
	{
		if (game->map[var->i][0] == '0')
			return (ft_fprintf(2, "Error : map must be surrounded by walls."),
				free_texture(game), free2d(game->map), exit(1));
		while (game->map[var->i][++var->j])
		{
			if (game->map[var->i][var->j] == '0'
				|| game->map[var->i][var->j] == game->player_info.direction)
			{
				if (plus_check(game, var->i, var->j) != 4)
					return (ft_fprintf(2,
							"Error : map must be surrounded by walls."),
						free2d(game->map), exit(1));
			}
		}
		var->j = 1;
	}
}

void	boundary_check(t_data *game)
{
	t_var	var;

	var.i = -1;
	var.j = -1;
	if (first_line(game->map[++var.i]) == false)
		return (ft_fprintf(2, "Error : map must be surrounded by walls."),
			free_texture(game), free2d(game->map), exit(1));
	boundary_check_helper(game, &var);
	if (first_line(game->map[var.i]) == false)
		return (ft_fprintf(2, "Error : map must be surrounded by walls."),
			free_texture(game), free2d(game->map), exit(1));
}

void	setup(t_data *game)
{
	game->player.x = game->player_info.x * TILE_S + ((float)TILE_S / 2);
	game->player.y = game->player_info.y * TILE_S + ((float)TILE_S / 2);
	game->player.turnD = 0;
	game->player.walkD = 0;
	game->player.mouseX = 0;
	game->player.sideW = 0;
	if (game->player_info.direction == 'N')
		game->player.rotationA = M_PI + M_PI_2;
	else if (game->player_info.direction == 'S')
		game->player.rotationA = M_PI_2;
	else if (game->player_info.direction == 'E')
		game->player.rotationA = 0;
	else if (game->player_info.direction == 'W')
		game->player.rotationA = M_PI;
	game->player.walkS = 3.0f;
	game->player.turnS = 1 * (M_PI / 180);
}

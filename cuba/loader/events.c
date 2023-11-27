/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:06:02 by ebennix           #+#    #+#             */
/*   Updated: 2023/11/27 11:21:04 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void mouse_event(t_data *game)
{
	static int i;

	mlx_get_mouse_pos(game->mlx, &game->player.mouseX, &game->player.mouseY);
	if (i++ == 0)
		game->player.mouseX = 500;
	game->player.rotationA += (float)(game->player.mouseX - 500) / 500;
	mlx_set_mouse_pos(game->mlx, 500, 500);
}

void 	update_state(t_data *game)
{
	game->player.rotationA += game->player.turnD * game->player.turnS;
	float movestep = game->player.walkD * game->player.walkS;
	float newplayerX = cos(game->player.rotationA) * movestep;
	float newplayerY = sin(game->player.rotationA) * movestep;
	float px = game->player.x + newplayerX;
	float py = game->player.y + newplayerY;
	printf("px = %f, py = %f\n", px, py);
	if (!check_walls1(game, px, py))
	{
		game->player.x = px;
		game->player.y = py;
	}
	float tmp = game->player.rotationA + game->player.sideW * game->player.turnS;
	movestep = game->player.sideW * game->player.walkS;
	newplayerX = cos(tmp + (90 * (M_PI / 180))) * movestep;
	newplayerY = sin(tmp + (90 * (M_PI / 180))) * movestep;
	px = game->player.x + newplayerX;
	py = game->player.y + newplayerY;
	if (!check_walls1(game, px, py))
	{
		game->player.x = px;
		game->player.y = py;
	}
}

void key_events(mlx_key_data_t keycode, t_data *game)
{
	if(keycode.key == MLX_KEY_ESCAPE)
		exit(1);
	if (keycode.key == MLX_KEY_W && (keycode.action == MLX_PRESS || keycode.action == MLX_REPEAT))
		game->player.walkD = 1;
	if (keycode.key == MLX_KEY_W && keycode.action == MLX_RELEASE)
		game->player.walkD = 0;
	if (keycode.key == MLX_KEY_S && (keycode.action == MLX_PRESS || keycode.action == MLX_REPEAT))
		game->player.walkD = -1;
	if (keycode.key == MLX_KEY_S && keycode.action == MLX_RELEASE)
		game->player.walkD = 0;
	if (keycode.key == MLX_KEY_RIGHT && (keycode.action == MLX_PRESS || keycode.action == MLX_REPEAT))
		game->player.turnD = 1;
	if (keycode.key == MLX_KEY_RIGHT && keycode.action == MLX_RELEASE)
		game->player.turnD = 0;
	if (keycode.key == MLX_KEY_LEFT && (keycode.action == MLX_PRESS || keycode.action == MLX_REPEAT))
		game->player.turnD = -1;
	if (keycode.key == MLX_KEY_LEFT && keycode.action == MLX_RELEASE)
		game->player.turnD = 0;
	if (keycode.key == MLX_KEY_D && (keycode.action == MLX_PRESS || keycode.action == MLX_REPEAT))
		game->player.sideW = 1;
	if (keycode.key == MLX_KEY_D && keycode.action == MLX_RELEASE)
		game->player.sideW = 0;
	if (keycode.key == MLX_KEY_A && (keycode.action == MLX_PRESS || keycode.action == MLX_REPEAT))
		game->player.sideW = -1;
	if (keycode.key == MLX_KEY_A && keycode.action == MLX_RELEASE)
		game->player.sideW = 0;
	//ft_loop(param);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:57:52 by ebennix           #+#    #+#             */
/*   Updated: 2023/12/06 01:19:32 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_Ray
{
	float			ray_angle;
	float			wall_hit_x;
	float			wall_hit_y;
	float			distance;
	int				was_hit_vertical;
	int				is_ray_facing_up;
	int				is_ray_facing_down;
	int				is_ray_facing_left;
	int				is_ray_facing_right;
	int				wall_hit_content;
	mlx_texture_t	*text;
}	t_Ray[NUM_RAYS];

typedef struct s_RGB
{
	char			*content_nullable;

	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}					t_RGB;

typedef struct s_elements
{
	char			*content_nullable;

	mlx_texture_t	*texture;
}					t_elements;

typedef struct s_position
{
	char			direction;

	int				x;
	int				y;
}					t_position;

typedef struct s_state
{
	float			x;
	float			y;
	int				mouse_x;
	int				mouse_y;
	int				turn_d;
	int				walk_d;
	int				side_w;
	float			rotation_a;
	float			walk_s;
	float			turn_s;
	float			fov_angle;
}					t_state;

typedef struct s_images
{
	mlx_image_t		*world_3d;
	mlx_image_t		*hud;

	mlx_image_t		*gun[6];
	int32_t			gun_x;
	int32_t			gun_y;
	bool			gun_shoot;
	bool			gun_running;

	mlx_image_t		*faces[6];
	bool			face_idle;

}					t_images;

typedef struct s_data
{
	mlx_t			*mlx;

	char			**map;
	unsigned int	map_height;
	unsigned int	map_width;
	t_position		player_info;

	t_state			player;

	t_elements		north;
	t_elements		south;
	t_elements		west;
	t_elements		east;
	t_RGB			c_floor;
	t_RGB			c_ceiling;

	t_images		canvas;
	mlx_texture_t	*door;
	unsigned int	frames;

	t_Ray			rays;
}					t_data;

struct				s_draw_3d
{
	float			corr_dist;
	float			dist_proj;
	float			proj_wall_h;
	int				wall_strip_h;
	int				wall_top_pixel;
	int				wall_bot_pixel;
	int				i;
	int				y;
	int				txt_offset_x;
	int				txt_offset_y;
	int				dist_from_top;
};
struct				s_mini_map
{
	float			cam_x;
	float			cam_y;
	int				draw_x;
	int				draw_y;
	int				x_dist;
	int				y_dist;
	int				x;
	int				y;
};

struct				s_cast_ray
{
	float			x_intercept;
	float			y_intercept;
	float			horz_hit_dist;
	float			vert_hit_dist;
	float			horz_wall_hit_x;
	float			horz_wall_hit_y;
	float			vert_wall_hit_x;
	float			vert_wall_hit_y;
	float			nxt_horz_touch_x;
	float			nxt_horz_touch_y;
	float			nxt_vert_touch_x;
	float			nxt_vert_touch_y;
	float			xstep;
	float			ystep;
	float			check_x;
	float			check_y;
	int				found_vertw_hit;
	int				found_horzw_hit;
	int				vert_wall_contnt;
	int				horz_wall_contnt;
	int				is_ray_fac_d;
	int				is_ray_fac_u;
	int				is_ray_fac_r;
	int				is_ray_fac_l;
};

struct				s_draw_gun
{
	int				animat[7];
	int				i;
};

struct				s_valid_map
{
	int				i;
	int				j;
	int				longest;
	int				player;	
};

struct				s_file_data
{
	char			*str;
	char			*row;
	bool			map_flag;
	char			**res;
};

struct				s_update_state
{
	float			move_step;
	float			newp_x;
	float			newp_y;
	float			px;
	float			py;
	float			tmp;
};

struct				s_init_image
{
	bool			check;
	char			*path;
};

struct				s_var
{
	int				i;
	int				j;	
};

struct				s_d_line
{
	float			dx;
	float			dy;
	float			step;
	float			x;
	float			y;
	int				i;
};

struct				s_draw_line
{
	float			x0;
	float			y0;
	float			x1;
	float			y1;
};

#endif
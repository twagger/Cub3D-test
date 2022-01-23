/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 09:35:12 by twagner           #+#    #+#             */
/*   Updated: 2022/01/23 19:18:37 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdbool.h>

/*
** PARAMS
*/

# define PLAYER_CHAR "NSWE"
# define VALID_CHAR "NSWE 01"
# define free_gnl_buffer() ft_get_next_line(0, NULL, 1)
typedef enum e_return_codes
{
	OK = 0,
	NO = 0,
	YES = 1,
	KO = 1
}	t_return_codes;

enum e_exit_codes {
	SUCCESS = 0,
	MAP_ERROR,
	PARAM_ERROR,
	FILE_ERROR,
	MALLOC_FAIL,
	MLX_FAIL,
	USER_INTERRUPT,
	NUMBER_OF_EXIT_CODES,
};

typedef enum e_island_action
{
	ADD,
	COUNT
}	t_island_action;

/* for floor and ceiling colors
blue = (RGB >> 16) & 0xFF;
green = (RGB >> 8) & 0xFF;
red = RGB & 0xFF;

new_RGB = (blue << 16) | (green << 8) | red;
*/

typedef struct s_param
{
	char	*tex_no;
	char	*tex_so;
	char	*tex_we;
	char	*tex_ea;
	int		*col_floor;
	int		*col_ceiling;
	char	**map;
}			t_param;

/*
** FUNCTIONS
*/

/*
** Error Handling
*/
int exit_clean(int error_msg, int fd, char **to_free);

/*
** parser
*/
bool	is_cub_file(char *file);
bool	are_parameters_ok(char *file, int *fd);
int		param_controller(int fd);
bool	is_map_ok(int fd);
int		map_controller(int fd);
int		count_island(char *line, int action);
int		init_param(char *file, t_param *param);
bool	are_color_param_ok(int fd, char *param_bit_counter, char **line);
bool	are_texture_param_ok(int fd, char *param_bit_counter, char **line);
/*
** Resource Free
*/
void	free_two_d_array(char **tab);

#endif
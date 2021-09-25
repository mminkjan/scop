/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scop.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/06 14:51:59 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/09/25 22:47:22 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include "../glew/include/GL/glew.h"
# include "../sdl/includes/SDL.h"
# include "../sdl/includes/SDL_opengl.h"
# include "../libft/libft.h"

# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>
# include <stdbool.h>
# include <time.h>

# define WINDOW_NAME "Scop"
# define WIDTH	640
# define HEIGHT 480

# define TRUE	1
# define FALSE	0

# define PI 3.14159265359

# define BUFFER 100000

# define VDUB 3

typedef struct	s_vec2 {
	float		x;
	float		y;
	float		z;
}				t_vec2;

typedef struct	s_vec3 {
	float		x;
	float		y;
	float		z;
}				t_vec3;

typedef struct	s_vec4 {
	int         x;
	int         y;
	int         z;
    int         w;
}				t_vec4;

typedef struct		s_buffer_data {
	t_vec3			v[BUFFER];
	t_vec2			vt[BUFFER]; 
	t_vec3			vn[BUFFER];
	GLfloat			*points;
	GLfloat			*lines;
	GLfloat			*triangles;
	GLfloat			*squads;
}					t_buffer_data;

typedef struct		s_cop {
	SDL_Window		*window;
	SDL_GLContext	context;
	SDL_Surface		*surface;
	SDL_Event		*event;
	GLuint			*vertex_arrayID;
	GLuint			vertex_buffer;
    GLuint			color_buffer;
	GLuint			program_id;
	GLfloat			*point_data;
	GLfloat			*line_data;
    GLfloat			*triangle_data;
	GLfloat			*quad_data;
	bool			running;
}					t_cop;

int 	main(void);
void	SDL_GL_init(t_cop *scop);
void	render(t_cop *scop);
void	scop_return_error(t_cop *cop, const char *message);
GLuint 	get_shaders(t_cop *scop);
void    obj_reader(t_cop *scop, char *file);
void    file_to_string(t_cop *scop, int fd, const char **file);
void 	obj_parcer(t_cop *scop,  t_buffer_data *buffer, char *str);

void    load_bmp(t_cop *scop, const char *imagepath);

void	rotation_x(int degree, t_vec3 *position);
void	rotation_y(int degree, t_vec3 *position);
void	rotation_z(int degree, t_vec3 *position);
void	iso_projection(t_vec3 *position);

#endif
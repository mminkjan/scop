/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scop.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/06 14:51:59 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/09/22 19:01:59 by mminkjan      ########   odam.nl         */
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

typedef enum    e_primitives {
    point,
    line,
    triangle,
    square
}               t_primitives;


typedef struct	s_v {
	float		x;
	float		y;
	float		z;
	struct s_v			*next;
}				t_v;

typedef struct	s_vt {
	float		u;
	struct s_vt		*next;
}				t_vt;

typedef struct	s_vn {
	float		x;
	float		y;
	float		z;
	struct s_vn		*next;
}				t_vn;

typedef struct	s_f {
	int			v;
	int			vt;
	int			vn;
}				t_f;

typedef struct	s_objs {
	int			length;
	float		*v;
	float		*vt;
	float		*vn;			
}				t_objs;

typedef struct	s_shaders {
	const char	*vshader;
	const char	*fshader;
}				t_shaders;

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

typedef struct      s_vertex_array {
    struct s_vec3   *s_vec3;
    int             length;
}                   t_vec3_array;

typedef struct      s_face {
    struct s_vec4   v;
    struct s_vec4   vt;
    struct s_vec4   vn;
}                   t_face;

typedef struct      s_cop {
	SDL_Window      *window;
	SDL_GLContext   context;
	SDL_Surface     *surface;
	SDL_Event       *event;
	GLuint          *vertex_arrayID;
	GLuint          vertex_buffer;
    GLuint          color_buffer;
	GLuint          program_id;
    GLfloat*        vt3_buffer_data;
	bool            running;
	t_objs          obj[1];
	t_shaders       shaders[1];
}				    t_cop;

int 	main(void);
void	SDL_GL_init(t_cop *scop);
void	render(t_cop *scop);
void	scop_return_error(t_cop *cop, const char *message);
GLuint 	load_shaders(t_cop *scop);
void    obj_reader(t_cop *scop, char *file);
void    file_to_string(t_cop *scop, int fd, const char **file);
GLfloat *vector3_to_float_array(t_cop *scop, t_vec3 *buffer,\
        float *data, int length);
void    obj_arrange_vertices(t_cop *scop, t_vec3 *vertices,\
        t_vec4 *faces, int fc_lenght);
void    load_bmp(t_cop *scop, const char *imagepath);

void	rotation_x(int degree, t_vec3 *position);
void	rotation_y(int degree, t_vec3 *position);
void	rotation_z(int degree, t_vec3 *position);
void	iso_projection(t_vec3 *position);

#endif
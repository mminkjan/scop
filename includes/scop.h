/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scop.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/06 14:51:59 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/05/13 15:01:29 by mminkjan      ########   odam.nl         */
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

# define WINDOW_NAME "Scop"
# define WIDTH	640
# define HEIGHT 480

# define TRUE	1
# define FALSE	0

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
	char		*vshader;
	char		*fshader;
}				t_shaders;

typedef struct s_cop {
	SDL_Window	*window;
	SDL_Surface *surface;
	SDL_Event	*event;
	GLuint 		*vertex_arrayID;
	GLuint 		vertex_buffer;
	bool		running;
	t_objs		obj[1];
	t_shaders	shaders[1];
}				t_cop;

int 	main(void);
void	SDL_GL_init(t_cop *scop);
void	render(t_cop *scop);
void	scop_return_error(t_cop *cop, const char *message);
GLuint 	load_shaders(t_cop *scop);

#endif
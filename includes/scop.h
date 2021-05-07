/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scop.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/06 14:51:59 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/05/07 17:12:53 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include "../sdl/includes/SDL.h"
# include "../libft/libft.h"

# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>
# include <stdbool.h>

# define WINDOW_NAME "Scop"
# define WIDTH	900
# define HEIGHT 600

# define TRUE	1
# define FALSE	0


typedef struct s_cop {
	SDL_Window	*window;
	SDL_Surface *surface;
	SDL_Event	*event;
	bool		running;
}				t_cop;

int 	main(void);
void	SDL_init(t_cop *scop);
void	render(t_cop *scop);
void	scop_return_error(t_cop *cop, const char *message);

#endif
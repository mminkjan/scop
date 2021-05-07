/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/06 14:42:36 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/05/07 16:49:04 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	render(t_cop *scop)
{
	SDL_Event e;
	bool quit = false;
	while (!quit)
	{
    	while (SDL_PollEvent(&e))
		{
        	if (e.type == SDL_QUIT)
            	quit = true;
        	if (e.type == SDL_KEYDOWN)
            	quit = true;
        	if (e.type == SDL_MOUSEBUTTONDOWN)
          		quit = true;
        }
		SDL_UpdateWindowSurface(scop->window);
	}
	SDL_DestroyWindow(scop->window);
}

void	scop_return_error(t_cop *cop, const char *message)
{
	ft_putstr(message);
	exit (0);
}

void	SDL_init(t_cop *scop)	
{
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
		scop_return_error(scop, SDL_GetError());
	scop->window = SDL_CreateWindow(WINDOW_NAME, \
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
	if (scop->window == NULL)
		scop_return_error(scop, SDL_GetError());
	scop->surface = SDL_GetWindowSurface(scop->window);
	if (scop->surface == NULL)
		scop_return_error(scop, SDL_GetError());
}

int		main(void)
{
	t_cop scop;

	SDL_init(&scop);
	render(&scop);
	return (0);
}
# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jesmith <jesmith@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/08/28 15:14:36 by jesmith       #+#    #+#                  #
#    Updated: 2021/05/07 19:55:13 by mminkjan      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

GREEN = $(shell printf "\e[38;5;10m")
WHITE = $(shell printf "\e[39m")
RED = $(shell printf "\033[0;31m")

NAME = scop
FLAGS = -Wall -Wextra -Werror
LIBFT = libft
GLEW = glew
GLEW_INCL = glew/include/GL/
SDL = sdl
SDL_FLAGS = `sdl2-config --cflags --libs`  -framework OpenGL -lGLEW -I GLEW_INCL 
LIBS = -L $(LIBFT) -lft -lSDL2_mixer $(GLEW_LIB)

SRCS_DIR = srcs/
SRCS_FILES = main render SDL_init

C_FILES = $(SCRS_FILES:%=%.c)

O_FILES_DIR = srcs/.objects

O_FILES = $(SRCS_FILES:%=$(SRCS_DIR).objects/%.o)

HEADERS = includes/scop.h

ADD_FILES = Makefile 

all: $(NAME)

$(NAME): $(O_FILES_DIR) $(O_FILES)
	make -C $(LIBFT)
	echo $(O_FILES)
	gcc -o $@ $(O_FILES) $(LIBS) $(FLAGS) $(SDL_FLAGS)
	echo "$(GREEN)[√]$(WHITE) compiling done!"

$(SRCS_DIR).objects/%.o: $(SRCS_DIR)%.c $(HEADERS)
	$(CC) -o $@ -c $<
	echo "$(GREEN)[+]$(WHITE) $@"


%/.objects:
	mkdir $@

clean:
	make clean -C $(LIBFT)
	rm -rf $(O_FILES_DIR)
	echo "cleaned $(NAME) object files"


fclean: clean
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)
	@echo "removed $(NAME) binary"

re: fclean all

add: fclean
	@git add $(LIBFT) $(HEADERS) $(ADD_FILES) $(SDL) $(GLEW)
	$(C_FILES) @git status

push:
ifdef MSG
	@git commit -m "$(MSG)"
	@git push
endif

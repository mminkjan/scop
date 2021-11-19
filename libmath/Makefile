# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mminkjan <mminkjan@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/19 14:57:50 by mminkjan      #+#    #+#                  #
#    Updated: 2021/11/19 16:04:48 by mminkjan      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libmath.a

SRCS_DIR = src/
SCRS_FILES = mat4 vec3

C_FILES = $(SCRS_FILES:%=$(SRCS_DIR)%.c)

HEADERS = includes/mathft.h

BIN = $(SCRS_FILES:%=%.o)
FLAGS = -Wall  -Wextra -Werror

all : $(NAME)

$(NAME) :
	@ gcc $(FLAGS) -c -I includes $(C_FILES)
	@ ar rc $(NAME) $(BIN)
	@ ranlib $(NAME)

	
clean :
	@ rm -f $(BIN)
	@ rm -f *#
	@ rm -f *~

fclean : clean
	@ rm -f $(NAME)

re : fclean all

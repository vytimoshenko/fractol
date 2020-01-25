# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 19:45:56 by hlorrine          #+#    #+#              #
#    Updated: 2020/01/26 02:27:56 by mperseus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	open_cl

HDR		= 	open_cl.h

SRC		= 	fractol_main.c					\
			fractol_mlx_init.c				\
			fractol_mlx_hooks.c				\
			fractol_open_cl_init.c			\
			fractol_open_cl_get_info.c		\
			fractol_open_cl_get_kernel.c	\
			fractol_open_cl_run.c			\
			fractol_open_cl_err_1.c			\
			fractol_open_cl_err_2.c			\
			fractol_draw.c					\
			fractol_put_info_1.c			\
			fractol_put_info_3.c
		
OBJ		= 	$(SRC:.c=.o)

LIB		=	make -C libft

ADD_ERR =	-Wall -Wextra -Werror

ADD_OPT =	-Ofast

ADD_LIB =	-L./libft -lft\
			-L/usr/local/lib/
			
ADD_FMW =	-lmlx -framework OpenGL -framework AppKit\
			-framework OpenCL 

all:		$(NAME)

$(NAME):	$(OBJ)
			$(LIB)
			gcc -o $(NAME) $(OBJ) $(ADD_ERR) $(ADD_OPT) $(ADD_LIB) $(ADD_FMW)

%.o: %.c
			gcc -I $(HDR) $< -c -o $@ $(ADD_ERR) $(ADD_OPT)

clean:
			@/bin/rm -f $(OBJ)

fclean: 	clean
			@/bin/rm -f $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
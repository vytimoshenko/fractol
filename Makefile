# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 19:45:56 by hlorrine          #+#    #+#              #
#    Updated: 2020/02/12 20:03:33 by mperseus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	fractol

HDR		= 	fractol.h

SRC		= 	fractol_main.c					\
			fractol_status_init.c			\
			fractol_mlx_init.c				\
			fractol_mlx_run.c				\
			fractol_mlx_hooks.c				\
			fractol_mlx_control_1.c			\
			fractol_mlx_control_2.c			\
			fractol_mlx_put_info_1.c		\
			fractol_mlx_put_info_2.c		\
			fractol_open_cl_init.c			\
			fractol_open_cl_info.c			\
			fractol_open_cl_run.c			\
			fractol_open_cl_clean.c			\
			fractol_open_cl_err.c	
		
OBJ		= 	$(SRC:.c=.o)

MK_FT	=	make -C libft
CL_FT	=	make clean -C libft
FCL_FT	=	make fclean -C libft

MK_MLX	=	make -C mlx
CL_MLX	=	make clean -C mlx

ADD_ERR =	-Wall -Wextra -Werror

ADD_OPT =	-Ofast

ADD_LIB =	-L ./libft	-l ft\
			-L ./mlx	-l mlx
			
ADD_FMW =	-lmlx -framework OpenGL -framework AppKit\
			-framework OpenCL 

all:		$(NAME)

$(NAME):	$(OBJ)
			$(MK_FT)
			$(MK_MLX)
			gcc -o $(NAME) $(OBJ) $(ADD_ERR) $(ADD_OPT) $(ADD_LIB) $(ADD_FMW)

%.o:		%.c
			gcc -I $(HDR) $< -c -o $@ $(ADD_ERR) $(ADD_OPT)

clean:
			@/bin/rm -f $(OBJ)
			$(CL_FT)
			$(CL_MLX)

fclean: 	clean
			@/bin/rm -f $(NAME)
			$(FCL_FT)

re: 		fclean all

.PHONY: 	all clean fclean re
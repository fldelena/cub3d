# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/06 16:38:52 by fldelena          #+#    #+#              #
#    Updated: 2021/05/01 18:51:28 by fldelena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

SRCS		= 	cub3d.c mlx.c parcer.c dda_algorithm.c player_params.c player_control.c textures.c \
				sprites.c parcer_tools.c parcer_tools_one.c exit.c bmp.c mallocs.c bmp_utils.c \
				print_error.c player_control_one.c sprites_one.c parcer_tools_two.c
OBJS		=	$(SRCS:.c=.o)
MLX			=	libmlx.a
LIBFT		=	libft.a

CC			=	gcc -g

CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	-I libft/ -I minilib/ -I includes/
MLXFLAGS	=	-lmlx -framework OpenGL -framework AppKit
FTFLAGS		=	-lft

RM			=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS) $(MLX) $(LIBFT)
			$(CC) -g $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) -I includes/ -L . $(MLXFLAGS) -L . $(FTFLAGS)


$(MLX):
			@$(MAKE) -C minilib/
			@mv minilib/$(MLX) .

$(LIBFT):
			@$(MAKE) -C libft/
			@mv libft/$(LIBFT) .

clean:
			$(RM) $(OBJS)
			$(MAKE) -C libft/ fclean
			$(MAKE) -C minilib/ clean
			$(RM) $(MLX)
			$(RM) $(LIBFT)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

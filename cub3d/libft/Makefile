# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/06 17:54:31 by fldelena          #+#    #+#              #
#    Updated: 2021/04/29 20:43:11 by fldelena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRCS = 		ft_bzero.c ft_calloc.c ft_endline.c \
			ft_lstadd_back.c ft_lstlast.c ft_lstnew.c \
			ft_lstsize.c ft_memset.c ft_putchar.c \
			ft_putendl.c ft_putstr.c ft_strjoin.c \
			ft_strlen.c get_next_line.c ft_strdup.c \
			ft_strnstr.c ft_strchr.c ft_split.c ft_atoi.c \
			ft_trim.c ft_simbcount.c ft_isdigit.c ft_strtrim.c \
			ft_strlcpy.c ft_lstclear.c

OBJS		= $(SRCS:.c=.o)

AR			= ar rc

RM			= rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

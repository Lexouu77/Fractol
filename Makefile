# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamouda <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 22:13:19 by ahamouda          #+#    #+#              #
#    Updated: 2016/03/04 18:27:24 by ahamouda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = clang
rm = rm -f
CFLAGS = -Wall -Werror -Wextra -O3 -march=native
DEBUGFLAG = -g3 -fsanitize=address
INCLUDES = ./h/
OBJ = $(SRC:.c=.o)
SRC =  fractol.c error.c draw.c key.c draw2.c draw3.c
HEADER = fractol.h

#.SILENT:

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
		@Make -C ./libft/
		@Make -C ./libmx2/
		$(CC) -o $(NAME) $(SRC) $(CFLAGS) -L ./libft/ -L ./libmx2/ -lft -lmlx \
			-framework OpenGL -framework AppKit

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INCLUDES)

clean:
	@Make -C ./libft/ clean
	$(RM) $(OBJ)

fclean: clean
	@Make -C ./libft/ fclean
	@Make -C ./libmx2/ clean
	$(RM) $(NAME)

re: fclean all

norme:
	norminette $(SRC) $(HEADER)

watch:
		watch "make norme" "20"

function:
	nm -u $(NAME)

.PHONY: re fclean clean all norme function watch

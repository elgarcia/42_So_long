# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 11:55:24 by eliagarc          #+#    #+#              #
#    Updated: 2023/12/30 16:52:41 by eliagarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SOURCE = Src/main.c Src/events.c Src/init.c Src/moves.c Src/map.c Src/auxiliar_functions.c \
Src/map_checks.c Src/prints.c Src/free.c
INCLUDE = Inc/so_long.h

MINILIB_DIR = mlx
MINILIB_A = libmlx.a

SILENCE = --no-print-directory
CC = cc
CFLAGS = -Wall -Wextra -Werror
LMLX = -Lmlx -lmlx -framework OpenGL -framework AppKit
LIBFT = lib/Libft/libft.a

OBJS = $(SOURCE:.c=.o)

%.o: %.c Makefile $(INCLUDE)
	@echo "Compiling $<..."
	@${CC} -c ${CFLAGS} -I $(INCLUDE) $< -o $@

all: sub_make $(NAME)

$(NAME): ${OBJS} $(INCLUDE) Makefile
	@echo "Creating executable..."
	@$(CC) $(CFLAGS) $(MINILIB_DIR)/$(MINILIB_A) $(OBJS) $(LIBFT) $(LMLX) -o $(NAME)
	@echo "$(NAME) created!"
	
sub_make:
	@echo "Compiling minilibx"
	@make -C $(MINILIB_DIR) $(SILENCE)
	@echo "Compiling libft..."
	@make -C lib/Libft $(SILENCE)

clean:
	@echo "Cleaning object files..."
	@make clean -C lib/Libft/ $(SILENCE)
	@rm -f $(OBJS)
	@echo "Object files removed!"

fclean:	clean
	@echo "Cleaning trash..."
	@make fclean -C lib/Libft/ $(SILENCE)
	@make clean -C $(MINILIB_DIR)/ $(SILENCE)
	@rm $(NAME)
	@echo "Trash removed!"

re: 	fclean all

.PHONY: all clean fclean re sub_make

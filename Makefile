#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtuiasos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/11 10:03:42 by dtuiasos          #+#    #+#              #
#    Updated: 2017/10/19 16:11:42 by dtuiasos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = main \
	  	map \
		read \
		player \
		coord \
		raycast \
		raydraw \
		init_mlx \
		draw \
		texture \
		keyboard \
		hook \

LIB_H = -I inc -I libft
MLBX_H = -I minilibx
MLBX = minilibx/libmlx.a
LIB = libft/libft.a
FLAGS = -L minilibx -lmlx -framework OpenGL -framework Appkit
OBJ = $(patsubst %, src/%.o, $(SRC))
C_FLAGS = gcc -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C minilibx
	@make -C libft fclean
	@make -C libft
	@$(C_FLAGS) $(OBJ) $(LIB) $(MLBX) $(FLAGS) -o $(NAME)
	@echo "I be hoppin' out the shower on a marble floor.."

src/%.o: src/%.c
	@$(C_FLAGS) $(LIB_H) $(MLBX_H) -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

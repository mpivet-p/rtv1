# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/22 02:45:47 by mpivet-p          #+#    #+#              #
#    Updated: 2019/08/22 05:23:02 by mpivet-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= rtv1
CC= gcc
CFLAGS= -Wall -Wextra -Werror

INC_PATH= inc/
SRC_PATH= src/
OBJ_PATH= obj/

INC_NAME= fractol.h
SRC_NAME= main.c events.c tools.c vectors.c viewplane.c render.c sphere.c\
		  solve.c plane.c cylinder.c cone.c test.c normal.c misc.c color.c\
		  rotations.c user_interface.c vecops.c ray.c list.c
OBJ_NAME= $(SRC_NAME:.c=.o)

INC= -I inc/ -I libft/inc/ -I mlx/
SRC= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))
LIBS= -L libft/ -lft -L /usr/local/lib/ -lmlx -lm
MLX= -framework OpenGL -framework AppKit

DEF= \033[0m
RED= \033[31;1m
GRN= \033[32;1m

.PHONY: all clean fclean re local

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) $(INC) $(LIBS) $(MLX)
	@echo "$(RED)[rtv1] : $(DEF)Compilation                  $(GRN)[OK]$(DEF)"

local: $(OBJ)
	@make -C libft
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) $(INC) -L libft/ -lft -L mlx/ -lmlx -lm $(MLX)
	@echo "$(RED)[rtv1] : $(DEF)Compilation                  $(GRN)[OK]$(DEF)"

multi:
	mv src/main.c src/maintmp.c
	mv src/multithreading.c src/main.c
	@make fclean
	@make -C libft
	@make $(OBJ)
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) $(INC) $(LIBS) -lpthread $(MLX)
	@echo "$(RED)[rtv1] : $(DEF)Compilation                  $(GRN)[OK]$(DEF)"
	mv src/main.c src/multithreading.c
	mv src/maintmp.c src/main.c

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@echo "$(RED)[rtv1] :$(DEF) Compiling $@"
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@make -C libft clean
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)[rtv1] : $(DEF)Cleaning                     $(GRN)[OK]$(DEF)"

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)
	@echo "$(RED)[rtv1] : $(DEF)Full Cleaning                $(GRN)[OK]$(DEF)"

re: fclean all

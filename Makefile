# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 21:59:30 by mcolin            #+#    #+#              #
#    Updated: 2026/01/04 11:59:59 by mcolin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
NAME = so_long
SRCS_DIR = srcs/
SOURCES =	$(SRCS_DIR)main.c				\
			$(SRCS_DIR)error.c				\
			$(SRCS_DIR)event.c				\
			$(SRCS_DIR)renderer/display.c	\
			$(SRCS_DIR)renderer/textures.c	\
			$(SRCS_DIR)renderer/window.c	\
			$(SRCS_DIR)map/check_map.c		\
			$(SRCS_DIR)map/set_map.c		\

OBJ_DIR = .build/
OBJS = $(SOURCES:$(SRCS_DIR)%.c=$(OBJ_DIR)%.o)

DEPS = $(SOURCES:$(SRCS_DIR)%.c=$(OBJ_DIR)%.d)

CFLAGS = -MP -MMD -Wall -Werror -Wextra -g
INCLUDE = -I includes/ -I libft/includes/ -I MacroLibX/includes/

all: $(NAME)

$(NAME): make_dir $(OBJS)
	$(MAKE) --no-print-directory -C libft/
	$(MAKE) --no-print-directory -C  MacroLibX/ -j
	$(CC) $(OBJS) $(CFLAGS) $(INCLUDE) -lSDL2 -lm libft/libft.a MacroLibX/libmlx.so -o $(NAME)

make_dir:
	@mkdir -p .build/
	@mkdir -p .build/map
	@mkdir -p .build/map
	@mkdir -p .build/renderer
	
$(OBJ_DIR)%.o:  $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDE) $< -c -o $@

gdb: $(NAME)
	gdb -tui $(NAME)

clean:
	$(MAKE) clean --no-print-directory -C libft/
	$(MAKE) clean --no-print-directory -C MacroLibX/
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C libft/
	$(MAKE) fclean --no-print-directory -C MacroLibX/
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re gdb

-include $(DEPS)
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/17 18:19:17 by mkuehl            #+#    #+#              #
#    Updated: 2021/12/19 17:26:22 by mkuehl           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
FLAGS = -Wall -Werror -Wextra
LIBRARIES = $(LIBFT) $(MINILIBX) -framework OpenGL -framework AppKit
INCLUDES = -I$(FDF_HEADER) -I$(LIBFT_HEADER) -I$(MINILIBX_HEADER)
LIBFT_DIRECTORY = ./libft/
LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_HEADER = $(LIBFT_DIRECTORY)/libft.h
MINILIBX_DIRECTORY = ./minilibx_macos/
MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
MINILIBX_HEADER = $(MINILIBX_DIRECTORY)/mlx.h
FDF_HEADER = ./fdf.h
SOURCES = draw.c main.c parse_map.c utils.c utils_2.c
OBJECTS := $(SOURCES:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

%.o: %.c $(FDF_HEADER)
	@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

$(NAME): $(LIBFT) $(MINILIBX) $(OBJECTS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(OBJECTS) -o $(NAME)

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

$(MINILIBX):
	@$(MAKE) -sC $(MINILIBX_DIRECTORY)

bonus:
	@$(MAKE) fclean
	@$(MAKE) all

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@$(MAKE) -sC $(MINILIBX_DIRECTORY) clean
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -f $(MINILIBX)
	@rm -f $(LIBFT)
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all
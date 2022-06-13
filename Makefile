# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 22:36:29 by nvideira          #+#    #+#              #
#    Updated: 2022/06/13 04:27:03 by nvideira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=		so_long.c\
			map_get.c

NAME=		so_long

OBJ=		$(SRC:.c=.o)

CC=			gcc

CFLAGS= 	-Wall -Werror -Wextra

LIBFT=		Libft/libft.a

LIBFT_DIR=	Libft

PRINTF=		ft_printf/libftprintf.a

PRINTF_DIR=	ft_printf

all: $(NAME)

.c.o:
	@$(CC) $(CFLAGS) -Imlx -c $< -o $(<:.c=.o)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	@$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT) $(PRINTF)

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(PRINTF):
	@make -s -C $(PRINTF_DIR)

clean:
	@rm -f $(OBJ)
	@make -s clean -C $(LIBFT_DIR)
	@make -s clean -C $(PRINTF_DIR)

fclean: clean
	@rm -f $(NAME)
	@make -s fclean -C $(LIBFT_DIR)
	@make -s fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re

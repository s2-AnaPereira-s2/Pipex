# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/21 17:27:14 by ana-pdos          #+#    #+#              #
#    Updated: 2025/07/22 18:20:41 by ana-pdos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDES = -I. -I$(LIBFT_DIR) 
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

CFILES = pipex.c pipex_utils.c
OFILES = $(CFILES:.c=.o)

.PHONY: all clean fclean re 

all: $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OFILES) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(INCLUDES) $(OFILES) $(LIBFT_LIB) -o $(NAME)

%.o: %.c pipex.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OFILES)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all
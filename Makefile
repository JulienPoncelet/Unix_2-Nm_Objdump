# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/27 12:29:52 by jponcele          #+#    #+#              #
#    Updated: 2014/04/23 15:48:48 by jponcele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_nm

DIRSRC = ./srcs/
DIROBJ = ./obj/

SRC = nm_main.c\
	  ft_nm.c\
	  setters.c

OBJ = $(SRC:.c=.o)

DIROBJS = $(addprefix $(DIROBJ), $(OBJ))

LFT = -L ./libft/ -lft
LPRINTF = -L ./libft/ -lft2

CC = clang
CFLAGS = -Wall -Werror -Wextra -g

HEAD = -I ./includes -I ./libft/includes/

all: $(NAME)

$(NAME): $(DIROBJS)
	@printf 'Compiling ./%s binaries : [\033[32mDONE\033[0m]\n' '$(NAME)'
	@$(MAKE) -C ./libft/
	@$(CC) $(CFLAGS) -o $@ $^ $(HEAD) $(LFT) $(LPRINTF)
	@printf 'Compiling ./%s : [\033[32mDONE\033[0m]\n' '$(NAME)'

$(DIROBJ)%.o: $(DIRSRC)%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $^ $(HEAD) -o $@

clean:
	@rm -rf $(DIROBJ)
	@printf 'Clean %s : [\033[32mDONE\033[0m]\n' '$(NAME)'
	@$(MAKE) clean -C ./libft

fclean: clean
	@$(RM) $(RFLAGS) $(NAME)
	@printf 'Fclean %s : [\033[32mDONE\033[0m]\n' '$(NAME)'
	@$(MAKE) fclean -C ./libft

re : fclean all

.PHONY: all clean fclean re

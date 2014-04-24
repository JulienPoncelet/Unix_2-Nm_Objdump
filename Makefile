# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/27 12:29:52 by jponcele          #+#    #+#              #
#    Updated: 2014/04/24 10:40:14 by jponcele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = nm_otool

NM_DIRSRC = ./nm_srcs/
NM_DIROBJ = ./nm_obj/

NM_SRC = nm_main.c\
	  ft_nm.c\
	  setters.c\
	  struct_nm.c

NM_OBJ = $(NM_SRC:.c=.o)

NM_DIROBJS = $(addprefix $(NM_DIROBJ), $(NM_OBJ))

OTOOL_DIRSRC = ./otool_srcs/
OTOOL_DIROBJ = ./otool_obj/

OTOOL_SRC = otool_main.c\
			ft_otool.c\
			setters.c

OTOOL_OBJ = $(OTOOL_SRC:.c=.o)

OTOOL_DIROBJS = $(addprefix $(OTOOL_DIROBJ), $(OTOOL_OBJ))

LFT = -L ./libft/ -lft
LPRINTF = -L ./libft/ -lftprintf

CC = clang
CFLAGS = -Wall -Werror -Wextra -g

HEAD = -I ./includes -I ./libft/includes/

all: $(NAME)

$(NAME): ft_nm ft_otool

ft_nm: $(NM_DIROBJS)
	@printf 'Compiling ./%s binaries : [\033[32mDONE\033[0m]\n' '$@'
	@$(MAKE) -C ./libft/
	@$(CC) $(CFLAGS) -o $@ $^ $(HEAD) $(LFT) $(LPRINTF)
	@printf 'Compiling ./%s : [\033[32mDONE\033[0m]\n' '$@'

$(NM_DIROBJ)%.o: $(NM_DIRSRC)%.c
	@mkdir -p nm_obj
	@$(CC) $(CFLAGS) -c $^ $(HEAD) -o $@

ft_otool: $(OTOOL_DIROBJS)
	@printf 'Compiling ./%s binaries : [\033[32mDONE\033[0m]\n' '$@'
	@$(MAKE) -C ./libft/
	@$(CC) $(CFLAGS) -o $@ $^ $(HEAD) $(LFT) $(LPRINTF)
	@printf 'Compiling ./%s : [\033[32mDONE\033[0m]\n' '$@'

$(OTOOL_DIROBJ)%.o: $(OTOOL_DIRSRC)%.c
	@mkdir -p otool_obj
	@$(CC) $(CFLAGS) -c $^ $(HEAD) -o $@

clean:
	@rm -rf $(NM_DIROBJ) $(OTOOL_DIROBJ)
	@printf 'Clean %s : [\033[32mDONE\033[0m]\n' '$(NAME)'
	@$(MAKE) clean -C ./libft

fclean: clean
	@$(RM) $(RFLAGS) ft_nm ft_otool
	@printf 'Fclean %s : [\033[32mDONE\033[0m]\n' '$(NAME)'
	@$(MAKE) fclean -C ./libft

re : fclean all

.PHONY: all clean fclean re

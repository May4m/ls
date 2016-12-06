# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smamba <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/12 10:08:38 by smamba            #+#    #+#              #
#    Updated: 2016/06/12 10:30:42 by smamba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = main.c make_list.c display_mech.c read_args.c options_dir.c \
	  recursive_works.c aux.c sort_lst.c sort_errnos.c sdev.c \
	  pretty_print.c alternative_ops.c dir_path.c

SRC1 = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Werror -Wextra $(SRC)
	@make -C libft/ fclean
	@make -C libft/
	@make -C libft/ clean
	@gcc -o $(NAME) -L libft/ -lft $(SRC1)
	@echo "ft_ls ready"

clean:
	@/bin/rm -f $(SRC1)
	@echo "clean"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "fclean"

re: fclean all

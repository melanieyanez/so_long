# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 23:57:00 by melanieyane       #+#    #+#              #
#    Updated: 2023/08/20 19:18:59 by melanieyane      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Attention d'ajouter les flags dans la compilation quand terminé

NAME = so_long

# Dossiers

SRCDIR = SRCS
OBJDIR = objs/
HDRDIR = includes


# Fichiers

SRCS = $(shell find ${SRCDIR} -name '*.c')
OBJS = ${SRCS:${SRCDIR}%.c=${OBJDIR}%.o}
HEADERS = ${HDRDIR}

# Compilation

GCC = GCC
CFLAGS = -Wall -Wextra -Werror

# Commandes

CP = cp
RM = rm -Rf

# Règles

${OBJDIR}%.o : ${SRCDIR}%.c
	@${GCC} -Imlx -I ${HEADERS} -c $< -o $@

${NAME} : ${OBJS}
	make -C mlx
	make -C libft
	@${GCC} ${OBJS} -Llibft -lft -Lmlx -lmlx -lz -framework OpenGL -framework AppKit -o ${NAME}
			
all : ${NAME}

# Nettoyage

clean : 
	@${RM} ${OBJS}
	make clean -C mlx
	make clean -C libft

fclean : clean
	@${RM} ${NAME}
	make fclean -C libft

# Autres règles

re : fclean all

.PHONY : re fclean clean all
	



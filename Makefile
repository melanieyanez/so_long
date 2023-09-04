# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 23:57:00 by melanieyane       #+#    #+#              #
#    Updated: 2023/09/04 14:07:05 by myanez-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

RM = rm -Rf

# Règles

${OBJDIR}%.o : ${SRCDIR}%.c
	@mkdir -p ${OBJDIR}
	@${GCC} ${CFLAGS} -Imlx -I ${HEADERS} -c $< -o $@

${NAME} : ${OBJS}
	@echo "Compiling the mlx..."
	@make -C mlx > /dev/null 2>&1;
	@echo "Compiling the libft..."
	@make -C libft
	@echo "Compiling so_long..."
	@${GCC} ${CFLAGS} ${OBJS} -Llibft -lft -Lmlx -lmlx -lz -framework OpenGL -framework AppKit -o ${NAME}
	@echo "All done!"
			
all : ${NAME}

# Nettoyage

clean : 
	@echo "Cleaning..."
	@${RM} ${OBJS}
	@make clean -C mlx
	@make clean -C libft

fclean : clean
	@echo "Full cleaning..."
	@${RM} ${NAME}
	@make fclean -C libft

# Autres règles

re : fclean all

.PHONY : re fclean clean all
	



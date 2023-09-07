# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 23:57:00 by melanieyane       #+#    #+#              #
#    Updated: 2023/09/07 12:46:17 by melanieyane      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Dossiers

SRCDIR = SRCS
OBJDIR = objs
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

${OBJDIR}/%.o : ${SRCDIR}/%.c
	@mkdir -p ${OBJDIR}
	@echo "Compiling $< into ${@F}..."
	@${GCC} ${CFLAGS} -Imlx -I ${HEADERS} -c $< -o $@

${NAME} : ${OBJS}
	@echo "\nCompiling the mlx library..."
	@make -C mlx > /dev/null 2>&1;
	@echo "\nCompiling the libft library..."
	@make -C libft
	@echo "\nCompiling so_long executable..."
	@${GCC} ${CFLAGS} ${OBJS} -Llibft -lft -Lmlx -lmlx -lz -framework OpenGL -framework AppKit -o ${NAME}
	@echo "\nAll done!"
			
all : ${NAME}

# Nettoyage

clean : 
	@echo "Cleaning...\n"
	@${RM} ${OBJS}
	@make clean -C mlx
	@make clean -C libft

fclean : clean
	@echo "Full cleaning...\n"
	@${RM} ${NAME}
	@make fclean -C libft

# Autres règles

re : fclean all

.PHONY : re fclean clean all
	



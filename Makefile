# --- VARIABLES --- #
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address
BONUS_DIR = ./bonus/
SRCS_DIR = ./srcs/
SRCS = pipex.c cmd_parsing.c errors.c utils.c utils_2.c
SRCS_BONUS = pipex_bonus.c cmd_parsing_bonus.c cmd_selection_bonus.c \
			 utils_bonus.c errors_bonus.c  here_doc_bonus.c
OBJ_DIR = objs/
OBJ = ${SRCS:%.c=${OBJ_DIR}%.o}
OBJ_BONUS = ${SRCS_BONUS:%.c=${OBJ_DIR}%.o}
NAME = pipex
NAME_BONUS = pipex_bonus
RM = rm -f
HEADER = ${SRCS_DIR}pipex.h
HEADER_BONUS = ${BONUS_DIR}pipex_bonus.h
LIBFT = libft/libft.a
LIBFT_DIR = libft/

# --- COLORS --- #

_NOC	:=	\033[0m
_RED	:=	\033[1;31m
_GREEN	:=	\033[1;32m

# --- RULES --- #

${NAME} :	${OBJ}
		${CC} ${CFLAGS} ${OBJ} ${LIBFT} -o ${NAME}
		@echo "${_GREEN}### ${NAME} created ###${_NOC}\n"

${NAME_BONUS} :	${OBJ_BONUS}
		${CC} ${CFLAGS} ${OBJ_BONUS} ${LIBFT} -o ${NAME_BONUS}
		@echo "${_GREEN}### ${NAME_BONUS} created ###${_NOC}\n"

${OBJ}: ${OBJ_DIR}%.o :	${SRCS_DIR}%.c ${HEADER} ${LIBFT}
		@mkdir -p objs
		${CC} ${CFLAGS} -I/usr/include -c $< -o $@

${OBJ_BONUS}: ${OBJ_DIR}%.o :	${BONUS_DIR}%.c ${HEADER_BONUS} ${LIBFT}
		@mkdir -p objs
		${CC} ${CFLAGS} -I/usr/include -c $< -o $@

${LIBFT}: FORCE
		${MAKE} -sC ${LIBFT_DIR}

FORCE:

all :	${NAME} ${NAME_BONUS}

bonus :	${NAME_BONUS}

clean :
		@${MAKE} clean -sC ${LIBFT_DIR}
		rm -rf objs/
		@echo "${_RED}### Removed pipex object files ###${_NOC}"

fclean :	clean
		@${MAKE} fclean -sC ${LIBFT_DIR}
		${RM} ${NAME} ${NAME_BONUS}
		@echo "${_RED}### Removed ${NAME} and/or ${NAME_BONUS} ###${_NOC}"

re : 	fclean all

.PHONY : all clean fclean re FORCE bonus

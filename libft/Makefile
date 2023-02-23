# --- VARIABLES --- #
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
SRCS = 	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_memmove.c ft_strcpy.c ft_strlcpy.c\
		ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
		ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strjoin_malloced.c ft_itoa.c ft_strtrim.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_lstnew.c \
		ft_lstsize.c ft_lstlast.c ft_lstdelone.c ft_lstadd_front.c \
		ft_lstadd_back.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
		ft_printf.c ft_print_functions.c ft_putchar.c \
		get_next_line.c get_next_line_utils.c
OBJ = ${SRCS:.c=.o}
NAME = libft.a
RM = rm -f
HEADER = libft.h
RAN = ranlib

%.o :	%.c ${HEADER}
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME} :	${OBJ}
		ar rc ${NAME} ${OBJ}
		${RAN} ${NAME}
		@echo "${_GREEN}### $(NAME) created ! ###${_NOC}\n"

# --- COLORS --- #

_NOC	:=	\033[0m
_RED	:=	\033[1;31m
_GREEN	:=	\033[1;32m

# --- RULES --- #

all :	${NAME}

clean :
		${RM} ${OBJ}
		@echo "${_RED}### Removed Libft object files ###${_NOC}"

fclean :	clean
		${RM} ${NAME}
		@echo "${_RED}### Removed ${NAME} ###${_NOC}"

re : 	fclean all

.PHONY : all clean fclean re

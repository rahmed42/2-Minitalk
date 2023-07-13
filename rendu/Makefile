# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/06 15:51:13 by rahmed            #+#    #+#              #
#    Updated: 2021/11/23 17:33:52 by rahmed           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libminitalk.a
LIBFT_DIR	=	libft
LIBFT_LIB	=	libft.a

SRCS		=	mt_server.c \
				mt_client.c

OBJS		=	${SRCS:.c=.o}

HEADER		=	.
CC			=	gcc
RM			=	rm -f
AR			=	ar rcs
CFLAGS		=	-Wall -Wextra -Werror

LDFLAGS		=	-L.
TARGET_SRV	=	server
TARGET_CLT	=	client

TXT_RED		=	\033[1;31m
TXT_GREEN	=	\033[1;32m
TXT_YELLOW	=	\033[1;33m
TXT_BLUE	=	\033[1;34m
TXT_MAGENTA	=	\033[1;35m
TXT_CYAN	=	\033[1;36m
FANCY_RESET	=	\033[0m

%.o			:	%.c
				@echo "${TXT_BLUE}"
				${CC} -c ${CFLAGS} -o $@ $< -I${HEADER}
				@echo "${FANCY_RESET}"

${NAME}		:	${OBJS}
				@echo "${TXT_GREEN}"
				make all -C ${LIBFT_DIR}
				@echo "${TXT_CYAN}"
				cp ${LIBFT_DIR}/${LIBFT_LIB} ${NAME}
				@echo "${TXT_YELLOW}"
				${AR} ${NAME} ${OBJS}
				make exec
				@echo "${FANCY_RESET}"

all			:	${NAME}

clean		:
				@echo "${TXT_YELLOW}"
				@echo "\n~~~~~~~~~~ CLEAN ~~~~~~~~~~"
				@echo "${TXT_RED}"
				${RM} ${OBJS}
				@echo "${TXT_GREEN}"
				make clean -C ${LIBFT_DIR}
				@echo "$(FANCY_RESET)"

fclean		:
				@echo "${TXT_YELLOW}"
				@echo "\n~~~~~~~~~~ FCLEAN ~~~~~~~~~~"
				@echo "${TXT_RED}"
				${RM} ${OBJS}
				@echo "${TXT_MAGENTA}"
				${RM} ${NAME}
				@echo "${TXT_GREEN}"
				make fclean -C ${LIBFT_DIR}
				@echo "$(FANCY_RESET)"

re			:	fclean all

norm		:
				@echo "${TXT_YELLOW}"
				@echo "\n~~~~~~~~~~ CHECK NORM ~~~~~~~~~~"
				@echo "${TXT_GREEN}"
				norminette ${LIBFT_DIR}/*.c -R CheckForbiddenSourceHeader
				norminette ${LIBFT_DIR}/*.h -R CheckDefine
				@echo "${TXT_CYAN}"
				norminette *.c -R CheckForbiddenSourceHeader
				norminette *.h -R CheckDefine
				@echo "${FANCY_RESET}"

exec		:	${NAME}
				@echo "${TXT_YELLOW}"
				@echo "\n~~~~~~~~~~ COMPILATION ~~~~~~~~~~"
				@echo "${TXT_GREEN}"
				${CC} ${CFLAGS} mt_client.c ${LDFLAGS} ${NAME} -o ${TARGET_CLT}
				${CC} ${CFLAGS} mt_server.c ${LDFLAGS} ${NAME} -o ${TARGET_SRV}
				@echo "${FANCY_RESET}"

.PHONY		:	all clean fclean re norm exec test flush

############### PARTIE TEST ###############
test		:
				@echo "${TXT_YELLOW}"
				@echo "\n~~~~~~~~~~   TEST    ~~~~~~~~~~"
				@echo "${TXT_BLUE}"
				./${TARGET_SRV}
				@echo "${FANCY_RESET}"

flush		:	fclean
				@echo "${TXT_YELLOW}"
				@echo "\n~~~~~~~~~~ Extra-CLEANING  ~~~~~~~~~~"
				@echo "${TXT_RED}"
				${RM} ${TARGET_SRV} ${TARGET_CLT}
				${RM} .DS_STORE
				${RM} *.out
				${RM} -R *.dSYM
				@echo "${FANCY_RESET}"
###########################################

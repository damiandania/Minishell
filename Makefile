# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: damian <damian@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 17:05:48 by ddania-c          #+#    #+#              #
#    Updated: 2023/10/17 22:32:57 by damian           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

#DIRECTORIES_________________________________________________________

READLINE_DIR=	usr/include/readline
INC_DIR		=	includes/
SRC_DIR		=	sources/
SRC_FILES	=	main.c			\
				lexer.C			\

SRC := $(addprefix $(SRC_DIR)/, $(SRC_FILES))
INC			=	-I $(INC_DIR) -I $(LIBFT_DIR)

#OBJECT______________________________________________________________

OBJ_DIR		=	objects/
OBJS		=	$(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))

#LIBFT_______________________________________________________________

LIBFT_DIR	=	libft
LIBFT		=	libft/libft

#FLAGS_______________________________________________________________

CC		=	cc
RM		=	rm -f
CFLAGS	=	-Werror -Wextra -Wall

#COLORS______________________________________________________________

GREEN	=	\033[0;32m
RED		=	\033[0;31m
WHITE	=	\033[0;97m
RESET	=	\033[0m
YELLOW 	=	\033[0;93m

#MAIN_RULE___________________________________________________________

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

#OBJECT_RULE_________________________________________________________

$(NAME): $(OBJS)
	@make -C ${LIBFT_DIR} --no-print-directory
	@echo -n "$(YELLOW)Compiling	${WHITE}→	$(YELLOW)$(NAME)$(RESET) "
	@$(CC) $(OBJS) $(CFLAGS) -o $@ $(INC) -L$(READLINE_DIR) -lreadline $(LIBFT)
	@echo "$(GREEN)[ok]✓$(RESET)"

#LIBFT_RULE__________________________________________________________

$(LIBFT):
	@make clean -C ${LIBFT_DIR} --no-print-directory

#CLEAN_RULE__________________________________________________________

clean:
	@make clean -C ${LIBFT_DIR} --no-print-directory
	@echo -n "$(RED)Deleting	${WHITE}→	$(RED)$(NAME) object$(RESET) "
	@$(RM) -r $(OBJ_DIR)
	@echo "$(GREEN)[ok]$(RED)✗$(RESET)"

fclean: clean
	@make fclean -C ${LIBFT_DIR} --no-print-directory
	@echo -n "$(RED)Deleting	${WHITE}→	$(RED)$(NAME) executable$(RESET) "
	@$(RM) $(NAME)
	@echo "$(GREEN)[ok]$(RED)✗$(RESET)"

re: fclean all

.PHONY: all clean fclean re

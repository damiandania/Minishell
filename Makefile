# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 17:05:48 by ddania-c          #+#    #+#              #
#    Updated: 2023/10/16 11:24:27 by ddania-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

#INCLUDES____________________________________________________________

INC			= -I ./includes/

#SOURCE______________________________________________________________

SRC_DIR		= sources
SRC_FILES	=	main.c

SRC := $(addprefix $(SRC_DIR)/, $(SRC_FILES))

#OBJECT______________________________________________________________

OBJ_DIR		=	obj
OBJS		=	$(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))

#LIBFT_______________________________________________________________

LIBFT_DIR = ./libft
LIBFT_PATH = ${LIBFT_DIR}/libft.a

#FLAGS_______________________________________________________________

CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Werror -Wextra -Wall
LFLAGS:= -L $(LIBFT_DIR) -lft

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
	@$(CC) $(CFLAGS) $(INC) $(LFLAGS) -c $< -o $@

#OBJECT_RULE_________________________________________________________

$(NAME): $(OBJS)
#	@echo -n "Verifying	${WHITE}→	norminette"
#	@if norminette | grep "Error" > /dev/null 2>&1; then echo "$(RED) [Error]✗$(RESET)"; else echo "$(GREEN) [ok]✓$(RESET)"; fi
	@make -C ${LIBFT_DIR} --no-print-directory
	@echo -n "$(YELLOW)Compiling	${WHITE}→	$(YELLOW)$(NAME)$(RESET) "
	@$(CC) $(OBJS) -o $@
	@echo "$(GREEN)[ok]✓$(RESET)"

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

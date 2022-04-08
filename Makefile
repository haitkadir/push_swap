# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 18:19:57 by haitkadi          #+#    #+#              #
#    Updated: 2022/04/08 23:27:41 by haitkadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


define HEADER                                                                                                  
                              █████                                                           
                             ░░███                                                            
 ████████  █████ ████  █████  ░███████              █████  █████ ███ █████  ██████   ████████ 
░░███░░███░░███ ░███  ███░░   ░███░░███            ███░░  ░░███ ░███░░███  ░░░░░███ ░░███░░███
 ░███ ░███ ░███ ░███ ░░█████  ░███ ░███           ░░█████  ░███ ░███ ░███   ███████  ░███ ░███
 ░███ ░███ ░███ ░███  ░░░░███ ░███ ░███            ░░░░███ ░░███████████   ███░░███  ░███ ░███
 ░███████  ░░████████ ██████  ████ █████ █████████ ██████   ░░████░████   ░░████████ ░███████ 
 ░███░░░    ░░░░░░░░ ░░░░░░  ░░░░ ░░░░░ ░░░░░░░░░ ░░░░░░     ░░░░ ░░░░     ░░░░░░░░  ░███░░░  
 ░███                                                                                ░███     
 █████                                                                               █████    
░░░░░                                                                               ░░░░░                                                                                                  
endef
export HEADER

# Reset
Color_Off='\033[0m'       # Text Reset

BBlack='\033[1;30m'       # Black
BRed='\033[1;31m'         # Red
BGreen='\033[1;32m'       # Green
BYellow='\033[1;33m'      # Yellow
BBlue='\033[1;34m'        # Blue
BPurple='\033[1;35m'      # Purple
BCyan='\033[1;36m'        # Cyan
BWhite='\033[1;37m'       # White
IGreen='\033[0;92m'       # Green

CC = gcc
#CFLAGS = -Wall -Wextra -Werror # flags
NAME = push_swap # Program name
#Assets
LIBFT = -L ./assets/libft/ -lft # libft library
PRINTF = -L ./assets/ft_printf/ -lftprintf # ft_printf function
ASSETS = assets/ft_atol.c 
# Source files
SRC = src/push_swap.c src/errors/errors_handling.c src/errors/errors_handling_util.c \
src/free_allocation.c src/parsing/parsing.c src/the_recipe/recipe.c \
src/instructions/instructions.c src/instructions/instructions_util1.c \
src/instructions/instructions_util2.c src/instructions/instructions_util3.c \
src/the_recipe/get_midpoint_a.c \
src/the_recipe/quicksort.c src/the_recipe/push_b.c \
src/the_recipe/push_b_util.c src/the_recipe/push_a_util.c src/the_recipe/push_a.c \
src/the_recipe/get_midpoint_b.c 

BSRC = src/errors/errors_handling.c src/errors/errors_handling_util.c \
src/free_allocation.c src/parsing/parsing.c \
src/instructions/instructions.c src/instructions/instructions_util1.c \
src/instructions/instructions_util2.c src/instructions/instructions_util3.c \
bonus/gnl/get_next_line.c bonus/checker.c

all: banner $(NAME)

banner:
	@clear
	@echo "\n"
	@echo $(BRed)"$$HEADER"$(Color_Off)
	@echo $(BYellow)"                                 Coded by Hssain Aitkadir\n"$(Color_Off)

$(NAME): $(SRC) $(ASSETS)
	@make bonus -C assets/libft/
	@make -C assets/ft_printf/
	@$(CC) $(CFLAGS) $(LIBFT) $(PRINTF) $(ASSETS) $(SRC) -o $(NAME)
	@echo $(BCyan)"\npush_swap program is ready to use"$(Color_Off)
	@echo $(BGreen)"\nUsage: ./push_swap <numbers to sort>"$(Color_Off)

bonus: all $(BSRC)
	@$(CC) $(CFLAGS) $(LIBFT) $(PRINTF) $(ASSETS) $(BSRC) -o checker
	@echo $(BCyan)"\nBonus compiled successfuly"$(Color_Off)
	@echo $(BGreen)"\nUsage: ./push_swap <numbers to sort> | ./checker <numbers to sort>"$(Color_Off)

clean:
	@make clean -C assets/libft/
	@make clean -C assets/ft_printf/
	@echo $(BRed)"\nObject files cleaned successfuly"$(Color_Off)

fclean:
	@make fclean -C assets/libft/
	@make fclean -C assets/ft_printf/
	@rm -f $(NAME)
	@rm -f checker
	@echo $(BRed)"\nFull cleaning applied successfuly"$(Color_Off)

re: fclean all

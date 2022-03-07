
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
CFLAGS = -Wall -Wextra -Werror # flags
NAME = push_swap # Program name
#Assets
LIBFT = -L ./assets/libft/ -lft # libft library
PRINTF = -L ./assets/ft_printf/ -lftprintf # ft_printf function
ASSETS = assets/ft_stackadd.c assets/ft_stackdelone.c assets/ft_stacklast.c assets/ft_stacknew.c assets/ft_stacksize.c assets/ft_atoli.c 
# Source files
SRC = src/push_swap.c src/errors_handling.c src/errors_handling_util.c src/free_allocation.c src/parsing.c
# OBJS = $(SRC:%.c=%.o)

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
	@echo $(BGreen)"\nUsage: ./push_swap numbers to sort here"$(Color_Off)

# %.o: %.c src/push_swap.h
# 	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@make clean -C assets/libft/
	@make clean -C assets/ft_printf/
	@echo $(BRed)"\nObject files cleaned successfuly"$(Color_Off)

fclean:
	@make fclean -C assets/libft/
	@make fclean -C assets/ft_printf/
	@rm -f $(NAME)
	@echo $(BRed)"\nFull cleaning applied successfuly"$(Color_Off)

re: fclean all
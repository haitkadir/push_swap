# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 16:04:21 by haitkadi          #+#    #+#              #
#    Updated: 2021/12/02 16:04:23 by haitkadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Reset
Color_Off='\033[0m'       # Text Reset

# Regular Colors
Red='\033[0;31m'          # Red
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_atoi.c ft_bzero.c ft_check_error.c ft_isdigit.c ft_manage_flags.c\
	ft_numlen.c ft_print_data.c ft_print_flags.c ft_printf.c ft_process_c.c\
	ft_process_d.c ft_process_p.c ft_process_s.c ft_process_u.c\
	ft_process_x.c ft_strchr.c ft_strlen.c ft_tolower.c

SRC_OBJECTS = $(SRC:%.c=%.o)

$(NAME): $(SRC_OBJECTS)
	@ar rcs $(NAME) $(SRC_OBJECTS)
	@echo $(Cyan)"Created your archive library $@"$(Color_Off)

all: $(NAME)

%.o:%.c ft_printf.h
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo $(Purple)"Created $@ from => $<"$(Color_Off)

bonus: all

clean:
	@rm -f $(SRC_OBJECTS)
	@echo $(Red)"\nObject files cleaned successfuly"$(Color_Off)

fclean: clean
	@rm -f $(NAME) a.out
	@echo $(Red)"\nFull cleaning applied successfuly"$(Color_Off)

re: fclean all

compile: all
	@$(CC) $(CFLAGS) main.c -L. -lftprintf
	@./a.out

.PHONY: all bonus clean fclean re compile
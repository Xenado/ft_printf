# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocaille <jocaille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/17 10:41:51 by jocaille          #+#    #+#              #
#    Updated: 2020/06/09 18:43:13 by jocaille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

LIB			=	libft
SRC_NAME	=	ft_printf.c\
				parse.c\
				init.c\
				print_nb.c\
				print.c
OBJ_NAME	=	$(SRC_NAME:.c=.o)
SRC_LIB		=	$(wildcard $(LIB)/*.c)
OBJ_LIB		=	$(patsubst %.c, %.o, $(SRC_LIB))
SRC_PATH	=	.
OBJ_PATH	=	.
SRC			=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ			=	$(addprefix	$(OBJ_PATH)/,$(OBJ_NAME))
INC			=	libftprintf.h
INC_PATH	=	.

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I$(INC_PATH)
RM			=	rm -rf
LDLIBS		=	-lft
LDFLAGS		=	-Llibft

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIB)
	ar rc $(NAME) $(OBJ_LIB) $(OBJ) 
	ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(MAKE) clean -C $(LIB)
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIB)
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re

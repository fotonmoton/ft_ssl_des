# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/18 16:06:01 by gtertysh          #+#    #+#              #
#    Updated: 2018/06/24 18:49:59 by gtertysh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name of the executable file

NAME :=							ft_ssl

# project directories

ROOT :=							$(shell pwd)
SRC_DIR :=						$(ROOT)/src/
OBJ_DIR :=						$(ROOT)/obj/
INC_DIR :=						$(ROOT)/inc/
LIB_DIR :=						$(ROOT)/lib/
TST_DIR :=						$(ROOT)/t/


# libraries

LIBFT_DIR :=					$(LIB_DIR)libft/
LIBFT_INC :=					-I $(LIBFT_DIR)includes/
LIBFT_LIB :=					-lft -L $(LIBFT_DIR)
LIBFT =							$(LIBFT_DIR)libft.a

MUINUT_DIR :=					$(LIB_DIR)munit/
MUINUT_INC :=					-I $(MUINUT_DIR)

# project source files

SRC =							main.c

# project object files

OBJ =							$(addprefix $(OBJ_DIR), $(SRC:.c=.o))


# project test files

TEST_BIN =						ft_ssl_test

TEST_SRC =						test_test.c

TEST_SRC +=						munit.c

TEST_OBJ =						$(addprefix $(OBJ_DIR), $(TEST_SRC:.c=.o))

# compilation flags

CC_FLAGS =						-Wall -Wextra -Werror

CC_FLAGS +=						-Wpointer-arith
CC_FLAGS +=						-Wcast-align
CC_FLAGS +=						-Wwrite-strings
CC_FLAGS +=						-Wunreachable-code
CC_FLAGS +=						-Winit-self
CC_FLAGS +=						-Wmissing-field-initializers
CC_FLAGS +=						-Wno-unknown-pragmas
CC_FLAGS +=						-Wstrict-prototypes
CC_FLAGS +=						-Wundef
CC_FLAGS +=						-Wold-style-definition

# for debug

ifeq ($(DEBUG),true)

CC_FLAGS +=						-g
CC_FLAGS +=						-O0

endif

# linking flags

LINK_FLAGS = ""

# header flags

HEADER_FLAGS =					$(MUINUT_INC)

# compiler

CC :=							clang

# rules

all: $(NAME)

$(NAME): check $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME)

check: $(TEST_BIN)
	./$(TEST_BIN)

$(TEST_BIN): $(LIBFT) $(TEST_OBJ)
	$(CC) $(TEST_OBJ) $(LINK_FLAGS) -o $(TEST_BIN)

$(TEST_OBJ) $(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean: 
	rm -f $(OBJ)
	rm -f $(TEST_OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

multi:
	$(MAKE) $(LIBFT)
	$(MAKE) check
	$(MAKE) $(NAME)

# special stuff

vpath %.c						$(SRC_DIR) \
								$(TST_DIR) \
								$(MUINUT_DIR)


.PHONY: all check clean fclean re multi

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/18 16:06:01 by gtertysh          #+#    #+#              #
#    Updated: 2019/01/19 15:21:01 by gtertysh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name of the executable file

NAME :=							ft_ssl

# project directories

ROOT :=							$(shell pwd)
SRC_DIR :=						$(ROOT)/src/
MD5_DIR :=						$(SRC_DIR)/md5/
SHA_DIR :=						$(SRC_DIR)/sha/
B64_DIR :=						$(SRC_DIR)/base64/
OBJ_DIR :=						$(ROOT)/obj/
INC_DIR :=						$(ROOT)/inc/
LIB_DIR :=						$(ROOT)/lib/
TST_DIR :=						$(ROOT)/t/


# project headers
MD5_HEADER :=					$(INC_DIR)/ft_md5.h
SHA_HEADER :=					$(INC_DIR)/ft_sha.h
SSL_HEADER :=					$(INC_DIR)/ft_ssl.h
HEADERS :=						$(MD5_HEADER)		\
								$(SHA_HEADER)		\
								$(SSL_HEADER)
# libraries

LIBFT_DIR :=					$(LIB_DIR)libft/
LIBFT_INC :=					-I $(LIBFT_DIR)includes/
LIBFT_LIB :=					-lft -L $(LIBFT_DIR)
LIBFT =							$(LIBFT_DIR)libft.a

MUINUT_DIR :=					$(LIB_DIR)munit/
MUINUT_INC :=					-I $(MUINUT_DIR)

# project source files

MD5_SRC =						ft_md5.c 					\
								ft_md5_stdin.c 				\
								ft_md5_string.c 			\
								ft_md5_file.c 				\
								ft_md5_print.c				\
								ft_md5_init.c				\
								ft_md5_update.c				\
								ft_md5_transform.c			\
								ft_md5_decode.c				\
								ft_md5_encode_len.c			\
								ft_md5_encode_register.c	\
								ft_md5_final.c				\
								ft_md5_padding.c			\
								ft_md5_digest_string.c

SHA_SRC =						ft_sha256.c 				\
								ft_sha256_string.c 			\
								ft_sha256_file.c 			\
								ft_sha256_stdin.c 			\
								ft_sha256_init.c			\
								ft_sha256_update.c			\
								ft_sha256_decode.c			\
								ft_sha256_encode_len.c		\
								ft_sha256_encode_register.c	\
								ft_sha256_transform.c		\
								ft_sha256_padding.c			\
								ft_sha256_final.c			\
								ft_sha256_digest_string.c	\
								ft_sha256_constants.c 		\
								ft_sha224_string.c 			\
								ft_sha224_file.c 			\
								ft_sha224_stdin.c 			\
								ft_sha224.c 				\
								ft_sha224_init.c 			\
								ft_sha224_update.c 			\
								ft_sha224_final.c 			\
								ft_sha224_digest_string.c	\
								ft_sha_print.c 				\
								ft_sha_usage.c

BASE64_SRC =					ft_base64.c 				\
								ft_base64_init.c 			\
								ft_base64_fill_buffer.c 	\
								ft_base64_transform.c 		\
								ft_base64_decode.c 			\
								ft_base64_encode.c

SRC =							main.c						\
								ft_ssl_usage.c

SRC +=							$(MD5_SRC)					\
								$(SHA_SRC)					\
								$(BASE64_SRC)
# project object files

OBJ =							$(addprefix $(OBJ_DIR), $(SRC:.c=.o))


# project test files

TEST_BIN =						ft_ssl_test

MD5_TESTS =						md5_tests.c
MD5_TESTS +=					$(MD5_SRC)

SHA_TESTS =						sha_tests.c
SHA_TESTS +=					$(SHA_SRC)

BASE64_TESTS =					base64_tests.c
BASE64_TESTS +=					$(BASE64_SRC)

TEST_SRC =						tests.c			\
								munit.c

TEST_SRC +=						$(MD5_TESTS)	\
								$(SHA_TESTS)	\
								$(BASE64_TESTS)

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

LINK_FLAGS =					$(LIBFT_LIB)

# header flags

HEADER_FLAGS =					-I $(INC_DIR)		\
								$(MUINUT_INC)		\
								$(LIBFT_INC)

# compiler

CC :=							clang

# rules

$(NAME): $(LIBFT) $(OBJ) $(HEADERS)
	$(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME)

$(TEST_BIN): $(LIBFT) $(TEST_OBJ) $(HEADERS)
	$(CC) $(TEST_OBJ) $(LINK_FLAGS) -o $(TEST_BIN)

$(TEST_OBJ) $(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

check: $(TEST_BIN)
	clear
	./$(TEST_BIN)

clean:
	rm -f $(OBJ)
	rm -f $(TEST_OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(TEST_BIN)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

multi:
	$(MAKE) $(LIBFT)
	$(MAKE) check
	$(MAKE) $(NAME)

# special stuff

vpath %.c						$(SRC_DIR)		\
								$(MD5_DIR)		\
								$(SHA_DIR)		\
								$(B64_DIR)		\
								$(TST_DIR)		\
								$(MUINUT_DIR)


.PHONY: all check clean fclean re multi

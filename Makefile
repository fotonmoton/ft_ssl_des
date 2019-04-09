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
DES_DIR :=						$(SRC_DIR)/des/
KD2_DIR :=						$(SRC_DIR)/pbkdf2/
OBJ_DIR :=						$(ROOT)/obj/
INC_DIR :=						$(ROOT)/inc/
LIB_DIR :=						$(ROOT)/lib/
TST_DIR :=						$(ROOT)/t/


# project headers
MD5_HEADER :=					$(INC_DIR)/ft_md5.h
SHA_HEADER :=					$(INC_DIR)/ft_sha.h
SSL_HEADER :=					$(INC_DIR)/ft_ssl.h
B64_HEADER :=					$(INC_DIR)/ft_base64.h
DES_HEADER :=					$(INC_DIR)/ft_des.h
KD2_HEADER :=					$(INC_DIR)/ft_pbkdf2.h
TST_HEADER :=					$(INC_DIR)/t.h
HEADERS :=						$(TST_HEADER)								\
								$(MD5_HEADER)								\
								$(SHA_HEADER)								\
								$(SSL_HEADER)								\
								$(B64_HEADER)								\
								$(DES_HEADER)								\
								$(PBKDF2_HEADER)
# libraries

LIBFT_DIR :=					$(LIB_DIR)libft/
LIBFT_INC :=					-I $(LIBFT_DIR)includes/
LIBFT_LIB :=					-lft -L $(LIBFT_DIR)
LIBFT =							$(LIBFT_DIR)libft.a

OPENSSL_DIR :=					$(LIB_DIR)openssl/
OPENSSL_BLD :=					$(OPENSSL_DIR)bld/
OPENSSL_LIB :=					-lssl -lcrypto -L $(OPENSSL_BLD)lib/
OPENSSL_INC :=					-I $(OPENSSL_BLD)include/
OPENSSL_SSL :=					$(OPENSSL_BLD)lib/libssl.a
OPENSSL_CRY :=					$(OPENSSL_BLD)lib/libcrypto.a

# project source files

MD5_SRC =						ft_md5.c 									\
								ft_md5_stdin.c 								\
								ft_md5_string.c 							\
								ft_md5_file.c 								\
								ft_md5_print.c								\
								ft_md5_init.c								\
								ft_md5_update.c								\
								ft_md5_transform.c							\
								ft_md5_decode.c								\
								ft_md5_encode_len.c							\
								ft_md5_encode_register.c					\
								ft_md5_final.c								\
								ft_md5_padding.c							\
								ft_md5_digest_string.c

SHA_SRC =						ft_sha256.c 								\
								ft_sha256_string.c 							\
								ft_sha256_file.c 							\
								ft_sha256_stdin.c 							\
								ft_sha256_init.c							\
								ft_sha256_update.c							\
								ft_sha256_decode.c							\
								ft_sha256_encode_len.c						\
								ft_sha256_encode_register.c					\
								ft_sha256_transform.c						\
								ft_sha256_padding.c							\
								ft_sha256_final.c							\
								ft_sha256_digest_string.c					\
								ft_sha256_constants.c 						\
								ft_sha224_string.c 							\
								ft_sha224_file.c 							\
								ft_sha224_stdin.c 							\
								ft_sha224.c 								\
								ft_sha224_init.c 							\
								ft_sha224_update.c 							\
								ft_sha224_final.c 							\
								ft_sha224_digest_string.c					\
								ft_sha_print.c 								\
								ft_sha_usage.c

BASE64_SRC =					ft_base64.c 								\
								ft_base64_init.c 							\
								ft_base64_decode.c 							\
								ft_base64_encode.c							\
								ft_base64_init_encode_buffer.c				\
								ft_base64_encode_chunk.c 					\
								ft_base64_encode_transform.c 				\
								ft_base64_encode_finish.c 					\
								ft_base64_init_decode_buffer.c 				\
								ft_base64_decode_chunk.c 					\
								ft_base64_decode_filter.c 					\
								ft_base64_decode_transform.c 				\
								ft_base64_decode_finish.c

DES_SRC =						ft_des_initial_permutation.c 				\
								ft_des_final_permutation.c 					\
								ft_des_expansion_box.c 						\
								ft_des_s_box.c 								\
								ft_des_s_box_1.c 							\
								ft_des_s_box_2.c 							\
								ft_des_s_box_3.c 							\
								ft_des_s_box_4.c 							\
								ft_des_s_box_5.c 							\
								ft_des_s_box_6.c 							\
								ft_des_s_box_7.c 							\
								ft_des_s_box_8.c 							\
								ft_des_feistel_function_permutation.c 		\
								ft_des_feistel_function.c 					\
								ft_des_key_permuted_choice_one.c 			\
								ft_des_derive_encryption_round_key.c 		\
								ft_des_derive_decryption_round_key.c 		\
								ft_des_rotate_half_key_left.c 				\
								ft_des_rotate_half_key_right.c 				\
								ft_des_key_permuted_choice_two.c 			\
								ft_des_round.c 								\
								ft_des_process_block.c 						\
								ft_des_generate_encryption_round_keys.c 	\
								ft_des_generate_decryption_round_keys.c 	\
								ft_des_parse_args.c 						\
								ft_des_arg_parsers.c 						\
								ft_des.c 									\
								ft_des_ecb.c 								\
								ft_des_cbc.c 								\
								ft_des_init_ctx.c 							\
								ft_des_set_raw_key.c 						\
								ft_des_set_raw_iv.c 						\
								ft_des_get_password.c 						\
								ft_des_derive_key.c 						\
								ft_des_encryption_key_routine.c 			\
								ft_des_decryption_key_routine.c 			\
								ft_des_print_error.c 						\
								ft_des_encrypt.c 							\
								ft_des_decrypt.c 							\
								ft_des_decrypt_b64.c 						\
								ft_des_encrypt_b64.c 						\
								ft_des_encode_process_chunk.c 				\
								ft_des_hex_to_bit.c 						\
								ft_des_hex_to_byte.c 						\
								ft_des_byte_to_bits.c 						\
								ft_des_bits_to_bytes.c						\
								ft_des_finish_encrypt.c						\
								ft_des_buffered_read.c

KD2_SRC =						ft_hmac_sha256_init_ctx.c 					\
								ft_hmac_sha256.c 							\
								ft_pbkdf2_sha256_init_ctx.c 				\
								ft_pbkdf2_sha256.c

SRC =							main.c										\
								ft_ssl_usage.c

SRC +=							$(MD5_SRC)									\
								$(SHA_SRC)									\
								$(BASE64_SRC)								\
								$(DES_SRC)									\
								$(KD2_SRC)
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

DES_TESTS =						des_tests.c
DES_TESTS +=					$(DES_SRC)

KD2_TESTS =						pbkdf2_tests.c
KD2_TESTS +=					$(KD2_SRC)

TEST_SRC =						tests.c
TEST_SRC +=						$(MD5_TESTS)								\
								$(SHA_TESTS)								\
								$(BASE64_TESTS)								\
								$(DES_TESTS)								\
								$(KD2_TESTS)

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

LINK_FLAGS =					$(LIBFT_LIB)								\
								$(OPENSSL_LIB)

# header flags

HEADER_FLAGS =					-I $(INC_DIR)								\
								$(LIBFT_INC)								\
								$(OPENSSL_INC)

# compiler

CC :=							clang

# rules

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME)

$(TEST_BIN): $(TEST_OBJ)
	$(CC) $(TEST_OBJ) $(LINK_FLAGS) -o $(TEST_BIN)

$(TEST_OBJ) $(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c $(LIBFT) $(OPENSSL_CRY) $(OPENSSL_SSL) $(HEADERS)
	$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OPENSSL_CRY) $(OPENSSL_SSL):
	cd $(OPENSSL_DIR)					&& \
	./config --prefix=$(OPENSSL_BLD)	&& \
	make -j 4 							&& \
	make -j 4 install

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
	rm -rf $(OPENSSL_BLD)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

multi:
	$(MAKE) $(LIBFT)
	$(MAKE) $(NAME)

# special stuff

vpath %.c						$(SRC_DIR)									\
								$(MD5_DIR)									\
								$(SHA_DIR)									\
								$(B64_DIR)									\
								$(DES_DIR)									\
								$(KD2_DIR)									\
								$(TST_DIR)

.PHONY: all check clean fclean re multi

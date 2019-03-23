/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 17:58:39 by gtertysh          #+#    #+#             */
/*   Updated: 2019/01/19 17:59:19 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DES_H
# define FT_DES_H

# include <stdint.h>

# define FT_DES_BYTE_BLOCK_SIZE 8
# define FT_DES_BIT_BLOCK_SIZE 64
# define FT_DES_EXPANDED_HALF_BLOCK_SIZE 48
# define FT_DES_S_BOX_INPUT_SIZE 6
# define FT_DES_S_BOX_OUTPUT_SIZE 4
# define FT_DES_S_BOX_TABLE_ROWS 4
# define FT_DES_S_BOX_TABLE_COLUMNS 16
# define FT_DES_ROUND_KEY_SIZE 48
# define FT_DES_INITIAL_KEY_SIZE 64
# define FT_DES_REDUCED_KEY_SIZE 56
# define FT_DES_ROUND_COUNT 16
# define FT_DES_READ_SIZE 1024
# define FT_DES_MAX_HEX_KEY 16

typedef uint64_t					t_byte8;
typedef unsigned char				t_byte1;


typedef	struct						s_des_ctx
{
	int								input_fd;
	int								output_fd;
	int								decode;
	int								b64;
	int								readed;
	t_byte1							buffer[FT_DES_BYTE_BLOCK_SIZE];
	t_byte1							key[FT_DES_INITIAL_KEY_SIZE];
	t_byte1							round_keys[FT_DES_ROUND_COUNT]
									[FT_DES_ROUND_KEY_SIZE];
}									t_des_ctx;

typedef int (*t_ft_des_arg_parser_function)
	(int argc, char **argv, int position, t_des_ctx *c);

typedef struct 						s_des_argument_parser
{
	const char						*arg;
	t_ft_des_arg_parser_function	arg_parser;
}									t_des_argument_parser;

typedef struct 						s_des_chunk_buffer
{
	t_byte1							buffer[FT_DES_BYTE_BLOCK_SIZE];
	t_byte8							readed;
}									t_des_chunk_buffer;

void								ft_des_initial_permutation
(
	t_byte1 message[FT_DES_BIT_BLOCK_SIZE],
	t_byte1 initial_permutation[FT_DES_BIT_BLOCK_SIZE]
);

void								ft_des_final_permutation
(
	t_byte1 before[FT_DES_BIT_BLOCK_SIZE],
	t_byte1 final_permutation[FT_DES_BIT_BLOCK_SIZE]
);

void								ft_des_expansion_box
(
	t_byte1 half[FT_DES_BIT_BLOCK_SIZE / 2],
	t_byte1 expanded[FT_DES_EXPANDED_HALF_BLOCK_SIZE]
);

void								ft_des_s_box
(
	t_byte1 input[FT_DES_S_BOX_INPUT_SIZE],
	t_byte1 output[FT_DES_S_BOX_OUTPUT_SIZE],
	t_byte1 table[FT_DES_S_BOX_TABLE_ROWS][FT_DES_S_BOX_TABLE_COLUMNS]
);

void								ft_des_s_box_1
(
	t_byte1 input[FT_DES_S_BOX_INPUT_SIZE],
	t_byte1 output[FT_DES_S_BOX_OUTPUT_SIZE]
);

void								ft_des_s_box_2
(
	t_byte1 input[FT_DES_S_BOX_INPUT_SIZE],
	t_byte1 output[FT_DES_S_BOX_OUTPUT_SIZE]
);

void								ft_des_s_box_3
(
	t_byte1 input[FT_DES_S_BOX_INPUT_SIZE],
	t_byte1 output[FT_DES_S_BOX_OUTPUT_SIZE]
);

void								ft_des_s_box_4
(
	t_byte1 input[FT_DES_S_BOX_INPUT_SIZE],
	t_byte1 output[FT_DES_S_BOX_OUTPUT_SIZE]
);

void								ft_des_s_box_5
(
	t_byte1 input[FT_DES_S_BOX_INPUT_SIZE],
	t_byte1 output[FT_DES_S_BOX_OUTPUT_SIZE]
);

void								ft_des_s_box_6
(
	t_byte1 input[FT_DES_S_BOX_INPUT_SIZE],
	t_byte1 output[FT_DES_S_BOX_OUTPUT_SIZE]
);

void								ft_des_s_box_7
(
	t_byte1 input[FT_DES_S_BOX_INPUT_SIZE],
	t_byte1 output[FT_DES_S_BOX_OUTPUT_SIZE]
);

void								ft_des_s_box_8
(
	t_byte1 input[FT_DES_S_BOX_INPUT_SIZE],
	t_byte1 output[FT_DES_S_BOX_OUTPUT_SIZE]
);

void								ft_des_feistel_function_permutation
(
	t_byte1 input[FT_DES_BIT_BLOCK_SIZE / 2],
	t_byte1 output[FT_DES_BIT_BLOCK_SIZE / 2]
);

void								ft_des_feistel_function
(
	t_byte1 right_half[FT_DES_BIT_BLOCK_SIZE / 2],
	t_byte1 key[FT_DES_ROUND_KEY_SIZE],
	t_byte1 output[FT_DES_BIT_BLOCK_SIZE / 2]
);

void								ft_des_key_permuted_choice_one
(
	t_byte1 initial_key[FT_DES_INITIAL_KEY_SIZE],
	t_byte1 reduced_key[FT_DES_REDUCED_KEY_SIZE]
);

void								ft_des_key_permuted_choice_two
(
	t_byte1 input_key[FT_DES_REDUCED_KEY_SIZE],
	t_byte1 round_key[FT_DES_ROUND_KEY_SIZE]
);

void								ft_des_derive_encryption_round_key
(
	t_byte1 input_key[FT_DES_REDUCED_KEY_SIZE],
	t_byte1 round,
	t_byte1 round_key[FT_DES_ROUND_KEY_SIZE]
);

void								ft_des_derive_decryption_round_key
(
	t_byte1 input_key[FT_DES_REDUCED_KEY_SIZE],
	t_byte1 round,
	t_byte1 round_key[FT_DES_ROUND_KEY_SIZE]
);

void								ft_des_generate_encryption_round_keys
(
	t_byte1 input_key[FT_DES_INITIAL_KEY_SIZE],
	t_byte1 keys[FT_DES_ROUND_COUNT][FT_DES_ROUND_KEY_SIZE]
);

void								ft_des_generate_decryption_round_keys
(
	t_byte1 input_key[FT_DES_INITIAL_KEY_SIZE],
	t_byte1 keys[FT_DES_ROUND_COUNT][FT_DES_ROUND_KEY_SIZE]
);

void								ft_des_rotate_half_key_left
(
	t_byte1 half[FT_DES_REDUCED_KEY_SIZE / 2],
	t_byte1 rotation_number
);

void								ft_des_rotate_half_key_right
(
	t_byte1 half[FT_DES_REDUCED_KEY_SIZE / 2],
	t_byte1 rotation_number
);

void								ft_des_round
(
	t_byte1 left_half[FT_DES_BIT_BLOCK_SIZE / 2],
	t_byte1 right_half[FT_DES_BIT_BLOCK_SIZE / 2],
	t_byte1 key[FT_DES_ROUND_KEY_SIZE]
);

void								ft_des_process_block
(
	t_byte1 plaintext[FT_DES_BYTE_BLOCK_SIZE],
	t_byte1 keys[FT_DES_ROUND_COUNT][FT_DES_ROUND_KEY_SIZE],
	t_byte1 ciphertext[FT_DES_BYTE_BLOCK_SIZE]
);

void								ft_des_print_error
(
	const char *error
);

void								ft_des_ecb
(
	int argc,
	char **argv
);

void								ft_des_init_ctx
(
	t_des_ctx *ctx
);

int									ft_des_key_arg_parser
(
	int argc,
	char **argv,
	int position,
	t_des_ctx *c
);

int									ft_des_decode_arg_parser
(
	int argc,
	char **argv,
	int position,
	t_des_ctx *c
);

int									ft_des_encode_arg_parser
(
	int argc,
	char **argv,
	int position,
	t_des_ctx *c
);

int									ft_des_base64_arg_parser
(
	int argc,
	char **argv,
	int position,
	t_des_ctx *c
);

int									ft_des_input_file_arg_parser
(
	int argc,
	char **argv,
	int position,
	t_des_ctx *c
);

int									ft_des_output_file_arg_parser
(
	int argc,
	char **argv,
	int position,
	t_des_ctx *c
);

int									ft_des_password_arg_parser
(
	int argc,
	char **argv,
	int position,
	t_des_ctx *c
);

int									ft_des_init_vector_arg_parser
(
	int argc,
	char **argv,
	int position,
	t_des_ctx *c
);

int									ft_des_salt_arg_parser
(
	int argc,
	char **argv,
	int position,
	t_des_ctx *c
);

void								ft_des_ecb_decrypt
(
	t_des_ctx *ctx
);

void								ft_des_ecb_decrypt_b64
(
	t_des_ctx *ctx
);

void								ft_des_ecb_encrypt
(
	t_des_ctx *ctx
);

void								ft_des_ecb_encrypt_b64
(
	t_des_ctx *ctx
);

void								ft_des_ecb_encode_process_chunk
(
	t_des_ctx *ctx,
	t_byte8 reaed,
	t_byte1 buffer[FT_DES_READ_SIZE]
);

void								ft_des_ecb_finish_encrypt
(
	t_des_ctx *ctx
);

void								ft_des_generete_key_from_hex
(
	char *hex_key,
	t_byte1 initla_key[FT_DES_INITIAL_KEY_SIZE]
);

const char							*ft_des_hex_to_bit_key
(
	const char *hex_key,
	t_byte1 bits_key[FT_DES_INITIAL_KEY_SIZE]
);

#endif

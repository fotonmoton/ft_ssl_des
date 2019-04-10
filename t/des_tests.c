#include "t.h"
#include "tests.h"
#include "ft_des.h"
#include "libft.h"
#include <unistd.h>

#define S_BOX_CASES_NUMBER 3

int perform_initial_permutation()
{
	// all 64 bits:
	// 00000001 00100011 01000101 01100111 10001001 10101011 11001101 11101111
	// block contains message bits in big-endian order
	t_byte1 message[FT_DES_BIT_BLOCK_SIZE] = {
		0, 0, 0, 0, 0, 0, 0, 1,
		0, 0, 1, 0, 0, 0, 1, 1,
		0, 1, 0, 0, 0, 1, 0, 1,
		0, 1, 1, 0, 0, 1, 1, 1,
		1, 0, 0, 0, 1, 0, 0, 1,
		1, 0, 1, 0, 1, 0, 1, 1,
		1, 1, 0, 0, 1, 1, 0, 1,
		1, 1, 1, 0, 1, 1, 1, 1,
	};

	// all 64 bits after initial permutation:
	// 11001100 00000000 11001100 11111111 11110000 10101010 11110000 10101010
	t_byte1 expect[FT_DES_BIT_BLOCK_SIZE] = {
		1, 1, 0, 0, 1, 1, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 0, 0, 1, 1, 0, 0,
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 0, 0, 0, 0,
		1, 0, 1, 0, 1, 0, 1, 0,
		1, 1, 1, 1, 0, 0, 0, 0,
		1, 0, 1, 0, 1, 0, 1, 0,
	};

	t_byte1 initial_permutation[FT_DES_BIT_BLOCK_SIZE];

	ft_bzero(initial_permutation, FT_DES_BIT_BLOCK_SIZE);

	ft_des_initial_permutation(message, initial_permutation);

	int i = 0;
	while(i < FT_DES_BIT_BLOCK_SIZE)
	{
		_IS(initial_permutation[i] == expect[i]);
		i++;
	}
	_END("perform initial permutation");
}

int	perform_final_permutation()
{
	// all 64 bits:
	// 11001100 00000000 11001100 11111111 11110000 10101010 11110000 10101010
	// block contains message bits in big-endian order
	t_byte1 before[FT_DES_BIT_BLOCK_SIZE] = {
		1, 1, 0, 0, 1, 1, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 0, 0, 1, 1, 0, 0,
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 0, 0, 0, 0,
		1, 0, 1, 0, 1, 0, 1, 0,
		1, 1, 1, 1, 0, 0, 0, 0,
		1, 0, 1, 0, 1, 0, 1, 0,
	};

	// all 64 bits after final permutation:
	// 00000001 00100011 01000101 01100111 10001001 10101011 11001101 11101111
	// block contains message bits in big-endian order
	t_byte1 expect[FT_DES_BIT_BLOCK_SIZE] = {
		0, 0, 0, 0, 0, 0, 0, 1,
		0, 0, 1, 0, 0, 0, 1, 1,
		0, 1, 0, 0, 0, 1, 0, 1,
		0, 1, 1, 0, 0, 1, 1, 1,
		1, 0, 0, 0, 1, 0, 0, 1,
		1, 0, 1, 0, 1, 0, 1, 1,
		1, 1, 0, 0, 1, 1, 0, 1,
		1, 1, 1, 0, 1, 1, 1, 1,
	};

	t_byte1 final_permutation[FT_DES_BIT_BLOCK_SIZE];

	ft_bzero(final_permutation, FT_DES_BIT_BLOCK_SIZE);

	ft_des_final_permutation(before, final_permutation);

	int i = 0;
	while(i < FT_DES_BIT_BLOCK_SIZE)
	{
		_IS(final_permutation[i] == expect[i]);
		i++;
	}
	_END("perform final permutation");
}

int final_permutation_IS_reverse_of_initial()
{
	t_byte1 message[FT_DES_BIT_BLOCK_SIZE] = {
		1, 0, 1, 0, 1, 0, 1, 0,
		1, 0, 1, 0, 1, 0, 1, 0,
		1, 0, 1, 0, 1, 0, 1, 0,
		1, 0, 1, 0, 1, 0, 1, 0,
		1, 0, 1, 0, 1, 0, 1, 0,
		1, 0, 1, 0, 1, 0, 1, 0,
		1, 0, 1, 0, 1, 0, 1, 0,
		1, 0, 1, 0, 1, 0, 1, 0,
	};

	t_byte1 initial_permutation[FT_DES_BIT_BLOCK_SIZE];
	t_byte1	final_permutation[FT_DES_BIT_BLOCK_SIZE];

	ft_bzero(initial_permutation, FT_DES_BIT_BLOCK_SIZE);
	ft_bzero(final_permutation, FT_DES_BIT_BLOCK_SIZE);
	ft_des_initial_permutation(message, initial_permutation);
	ft_des_final_permutation(initial_permutation, final_permutation);

	int i = 0;
	while(i < FT_DES_BIT_BLOCK_SIZE)
	{
		_IS(final_permutation[i] == message[i]);
		i++;
	}
	_END("final permutation is reverse of initial");
}

int perform_expansion_in_feistel_function()
{
	t_byte1 expanded_half_actual[FT_DES_EXPANDED_HALF_BLOCK_SIZE];
	// half block 32 bits:
	// 1111 0000 1010 1010 1111 0000 1010 1010
	t_byte1 half_block[FT_DES_BIT_BLOCK_SIZE / 2] = {
		1, 1, 1, 1, 0, 0, 0, 0,
		1, 0, 1, 0, 1, 0, 1, 0,
		1, 1, 1, 1, 0, 0, 0, 0,
		1, 0, 1, 0, 1, 0, 1, 0,
	};

	// expanded 32 bits to 48 bits:
	// 011110 100001 010101 010101 011110 100001 010101 010101
	t_byte1 expanded_half_expected[FT_DES_EXPANDED_HALF_BLOCK_SIZE] = {
		0, 1, 1, 1, 1, 0,
		1, 0, 0, 0, 0, 1,
		0, 1, 0, 1, 0, 1,
		0, 1, 0, 1, 0, 1,
		0, 1, 1, 1, 1, 0,
		1, 0, 0, 0, 0, 1,
		0, 1, 0, 1, 0, 1,
		0, 1, 0, 1, 0, 1,
	};

	ft_bzero(expanded_half_actual, FT_DES_EXPANDED_HALF_BLOCK_SIZE);
	ft_des_expansion_box(half_block, expanded_half_actual);

	int i = 0;
	while(i < FT_DES_EXPANDED_HALF_BLOCK_SIZE)
	{
		_IS(expanded_half_actual[i] == expanded_half_expected[i]);
		i++;
	}
	_END("perform expansion in feistel function");
}

static int s_box_check
(
	t_byte1 inputs[S_BOX_CASES_NUMBER][FT_DES_S_BOX_INPUT_SIZE],
	t_byte1 expected[S_BOX_CASES_NUMBER][FT_DES_S_BOX_OUTPUT_SIZE],
	void (*box)(t_byte1 in[FT_DES_S_BOX_INPUT_SIZE],
				t_byte1 out[FT_DES_S_BOX_OUTPUT_SIZE])
)
{
	t_byte1 output[FT_DES_S_BOX_OUTPUT_SIZE];
	int j = 0;
	while(j < S_BOX_CASES_NUMBER)
	{
		box(inputs[j], output);

		int i = 0;
		while(i < FT_DES_S_BOX_OUTPUT_SIZE)
		{
			if(output[i] != expected[j][i])
				return 0;
			i++;
		}
		j++;
	}
	return 1;
}

int	s_boxes_confuse()
{
	t_byte1 s1_inputs[S_BOX_CASES_NUMBER][FT_DES_S_BOX_INPUT_SIZE] = {
		{1, 0, 0, 1, 0, 1},
		{0, 0, 0, 0, 0, 0},
		{0, 1, 1, 1, 1, 0},
	};
	t_byte1 s1_expected[S_BOX_CASES_NUMBER][FT_DES_S_BOX_OUTPUT_SIZE] = {
		{1, 0, 0, 0},
		{1, 1, 1, 0},
		{0, 1, 1, 1},
	};

	_IS(s_box_check(s1_inputs, s1_expected, ft_des_s_box_1));

	t_byte1 s2_inputs[S_BOX_CASES_NUMBER][FT_DES_S_BOX_INPUT_SIZE] = {
		{0, 0, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 1},
		{1, 1, 0, 0, 0, 0},
	};

	t_byte1 s2_expected[S_BOX_CASES_NUMBER][FT_DES_S_BOX_OUTPUT_SIZE] = {
		{1, 1, 1, 1},
		{1, 1, 0, 1},
		{0, 1, 0, 1},
	};

	_IS(s_box_check(s2_inputs, s2_expected, ft_des_s_box_2));

	t_byte1 s3_inputs[S_BOX_CASES_NUMBER][FT_DES_S_BOX_INPUT_SIZE] = {
		{0, 0, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 1},
		{1, 1, 0, 0, 0, 0},
	};

	t_byte1 s3_expected[S_BOX_CASES_NUMBER][FT_DES_S_BOX_OUTPUT_SIZE] = {
		{1, 0, 1, 0},
		{0, 0, 0, 1},
		{1, 0, 1, 1},
	};

	_IS(s_box_check(s3_inputs, s3_expected, ft_des_s_box_3));

	t_byte1 s4_inputs[S_BOX_CASES_NUMBER][FT_DES_S_BOX_INPUT_SIZE] = {
		{0, 0, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 1},
		{1, 1, 0, 0, 0, 0},
	};

	t_byte1 s4_expected[S_BOX_CASES_NUMBER][FT_DES_S_BOX_OUTPUT_SIZE] = {
		{0, 1, 1, 1},
		{0, 0, 1, 1},
		{1, 1, 1, 1},
	};

	_IS(s_box_check(s4_inputs, s4_expected, ft_des_s_box_4));

	t_byte1 s5_inputs[S_BOX_CASES_NUMBER][FT_DES_S_BOX_INPUT_SIZE] = {
		{0, 0, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1},
	};

	t_byte1 s5_expected[S_BOX_CASES_NUMBER][FT_DES_S_BOX_OUTPUT_SIZE] = {
		{0, 0, 1, 0},
		{1, 0, 1, 1},
		{0, 0, 1, 1},
	};

	_IS(s_box_check(s5_inputs, s5_expected, ft_des_s_box_5));

	t_byte1 s6_inputs[S_BOX_CASES_NUMBER][FT_DES_S_BOX_INPUT_SIZE] = {
		{0, 0, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1},
	};

	t_byte1 s6_expected[S_BOX_CASES_NUMBER][FT_DES_S_BOX_OUTPUT_SIZE] = {
		{1, 1, 0, 0},
		{0, 1, 0, 0},
		{1, 1, 0, 1},
	};

	_IS(s_box_check(s6_inputs, s6_expected, ft_des_s_box_6));

	t_byte1 s7_inputs[S_BOX_CASES_NUMBER][FT_DES_S_BOX_INPUT_SIZE] = {
		{0, 0, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1},
	};

	t_byte1 s7_expected[S_BOX_CASES_NUMBER][FT_DES_S_BOX_OUTPUT_SIZE] = {
		{0, 1, 0, 0},
		{0, 1, 1, 0},
		{1, 1, 0, 0},
	};

	_IS(s_box_check(s7_inputs, s7_expected, ft_des_s_box_7));

	t_byte1 s8_inputs[S_BOX_CASES_NUMBER][FT_DES_S_BOX_INPUT_SIZE] = {
		{0, 0, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1},
	};

	t_byte1 s8_expected[S_BOX_CASES_NUMBER][FT_DES_S_BOX_OUTPUT_SIZE] = {
		{1, 1, 0, 1},
		{0, 0, 1, 0},
		{1, 0, 1, 1},
	};

	_IS(s_box_check(s8_inputs, s8_expected, ft_des_s_box_8));

	_END("s boxes confuse");
}

int perform_premutation_in_feistel_function()
{
	t_byte1 input[FT_DES_BIT_BLOCK_SIZE / 2] = {
		1, 0, 1, 0, 1, 0, 1, 0,
		0, 1, 0, 1, 0, 1, 0, 1,
		1, 0, 1, 0, 1, 0, 1, 0,
		0, 1, 0, 1, 0, 1, 0, 1,
	};

	t_byte1 expected[FT_DES_BIT_BLOCK_SIZE / 2] = {
		1, 1, 0, 1, 0, 1, 1, 1,
		1, 0, 1, 1, 1, 0, 0, 1,
		0, 0, 0, 1, 1, 0, 1, 0,
		1, 0, 1, 0, 0, 0, 0, 0,
	};

	t_byte1 actual[FT_DES_BIT_BLOCK_SIZE / 2];

	ft_des_feistel_function_permutation(input, actual);

	int i = 0;
	while(i < FT_DES_BIT_BLOCK_SIZE / 2)
	{
		_IS(actual[i] == expected[i]);
		i++;
	}
	_END("should perform permutation in feistel function");
}

int perform_feistel_function()
{
	t_byte1 key[FT_DES_ROUND_KEY_SIZE] = {
		0, 0, 0, 1, 1, 0,
		1, 1, 0, 0, 0, 0,
		0, 0, 1, 0, 1, 1,
		1, 0, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1,
		0, 0, 0, 1, 1, 1,
		0, 0, 0, 0, 0, 1,
		1, 1, 0, 0, 1, 0,
	};
	t_byte1 right_half[FT_DES_BIT_BLOCK_SIZE / 2] = {
		1, 1, 1, 1,
		0, 0, 0, 0,
		1, 0, 1, 0,
		1, 0, 1, 0,
		1, 1, 1, 1,
		0, 0, 0, 0,
		1, 0, 1, 0,
		1, 0, 1, 0,
	};
	t_byte1 expected[FT_DES_BIT_BLOCK_SIZE / 2] = {
		0, 0, 1, 0,
		0, 0, 1, 1,
		0, 1, 0, 0,
		1, 0, 1, 0,
		1, 0, 1, 0,
		1, 0, 0, 1,
		1, 0, 1, 1,
		1, 0, 1, 1,
	};

	t_byte1 output[FT_DES_BIT_BLOCK_SIZE / 2];

	ft_des_feistel_function(right_half, key, output);

	int i = 0;
	while(i < FT_DES_BIT_BLOCK_SIZE / 2)
	{
		_IS(output[i] == expected[i]);
		i++;
	}
	_END("feistel function should encode half of a block");
}

int reduce_key_to_56_bits()
{
	t_byte1 initial_key[FT_DES_INITIAL_KEY_SIZE] = {
		1, 1, 1, 1, 1, 1, 1, 0,
		1, 1, 1, 1, 1, 1, 1, 0,
		1, 1, 1, 1, 1, 1, 1, 0,
		1, 1, 1, 1, 1, 1, 1, 0,
		1, 1, 1, 1, 1, 1, 1, 0,
		1, 1, 1, 1, 1, 1, 1, 0,
		1, 1, 1, 1, 1, 1, 1, 0,
		1, 1, 1, 1, 1, 1, 1, 0,
	};

	t_byte1 expected_reduced_key[FT_DES_REDUCED_KEY_SIZE] = {
		1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1,
	};
	t_byte1 actual_reduced[FT_DES_REDUCED_KEY_SIZE];

	ft_des_key_permuted_choice_one(initial_key, actual_reduced);

	int i = 0;
	while(i < FT_DES_REDUCED_KEY_SIZE)
	{
		_IS(actual_reduced[i] == expected_reduced_key[i]);
		i++;
	}

	_END("should reduce key size to 56 bits");
}

int rotate_half_key()
{
	t_byte1 half_key[FT_DES_REDUCED_KEY_SIZE / 2] = {
		1, 1, 1, 1, 0, 0, 0,
		0, 1, 1, 0, 0, 1, 1,
		0, 0, 1, 0, 1, 0, 1,
		0, 1, 0, 1, 1, 1, 1,
	};

	t_byte1 expected[FT_DES_REDUCED_KEY_SIZE / 2] = {
		1, 1, 0, 0, 0, 0, 1,
		1, 0, 0, 1, 1, 0, 0,
		1, 0, 1, 0, 1, 0, 1,
		0, 1, 1, 1, 1, 1, 1,
	};

	// ft_memcpy(expected, half_key, FT_DES_REDUCED_KEY_SIZE / 2);

	ft_des_rotate_half_key_left(half_key, 1);
	ft_des_rotate_half_key_left(half_key, 1);
	// ft_des_rotate_half_key_right(half_key, 2);

	int i = 0;

	while(i < FT_DES_REDUCED_KEY_SIZE / 2)
	{
		_IS(half_key[i] == expected[i]);
		i++;
	}
	_END("should rotate half of reduced key");
}

int derive_round_key()
{
	t_byte1 reduced_key[FT_DES_REDUCED_KEY_SIZE] = {
		1, 1, 1, 1, 0, 0, 0,
		0, 1, 1, 0, 0, 1, 1,
		0, 0, 1, 0, 1, 0, 1,
		0, 1, 0, 1, 1, 1, 1,
		0, 1, 0, 1, 0, 1, 0,
		1, 0, 1, 1, 0, 0, 1,
		1, 0, 0, 1, 1, 1, 1,
		0, 0, 0, 1, 1, 1, 1,
	};

	t_byte1 shifted_reduced_key[FT_DES_REDUCED_KEY_SIZE] = {
		1, 1, 1, 0, 0, 0, 0,
		1, 1, 0, 0, 1, 1, 0,
		0, 1, 0, 1, 0, 1, 0,
		1, 0, 1, 1, 1, 1, 1,
		1, 0, 1, 0, 1, 0, 1,
		0, 1, 1, 0, 0, 1, 1,
		0, 0, 1, 1, 1, 1, 0,
		0, 0, 1, 1, 1, 1, 0,
	};

	t_byte1 expected_round_key[FT_DES_ROUND_KEY_SIZE] = {
		0, 0, 0, 1, 1, 0,
		1, 1, 0, 0, 0, 0,
		0, 0, 1, 0, 1, 1,
		1, 0, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1,
		0, 0, 0, 1, 1, 1,
		0, 0, 0, 0, 0, 1,
		1, 1, 0, 0, 1, 0,
	};

	t_byte1 round_key[FT_DES_ROUND_KEY_SIZE];

	ft_des_derive_encryption_round_key(reduced_key, 1, round_key);

	int i;

	i = 0;
	while(i < FT_DES_REDUCED_KEY_SIZE)
	{
		_IS(shifted_reduced_key[i] == reduced_key[i]);
		i++;
	}

	i = 0;
	while(i < FT_DES_ROUND_KEY_SIZE)
	{
		_IS(round_key[i] == expected_round_key[i]);
		i++;
	}
	_END("should derive round key");
}

int perform_encryption_round()
{
	t_byte1 key[FT_DES_INITIAL_KEY_SIZE] = {
		0, 0, 1, 1, 1, 0, 1, 1,
		0, 0, 1, 1, 1, 0, 0, 0,
		1, 0, 0, 1, 1, 0, 0, 0,
		0, 0, 1, 1, 0, 1, 1, 1,
		0, 0, 0, 1, 0, 1, 0, 1,
		0, 0, 1, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 0, 1, 1, 1,
		0, 1, 0, 1, 1, 1, 1, 0,
	};
	t_byte1 reduced_key[FT_DES_REDUCED_KEY_SIZE];
	t_byte1 round_key[FT_DES_ROUND_KEY_SIZE];
	t_byte1 message[FT_DES_BIT_BLOCK_SIZE] = {
		0, 1, 1, 0, 0, 0, 0, 1,
		0, 1, 1, 1, 0, 0, 1, 1,
		0, 1, 1, 0, 0, 1, 0, 0,
		0, 1, 1, 0, 0, 0, 0, 1,
		0, 1, 1, 1, 0, 0, 1, 1,
		0, 1, 1, 0, 0, 1, 0, 0,
		0, 1, 1, 0, 0, 0, 0, 1,
		0, 1, 1, 1, 0, 0, 1, 1,
	};
	t_byte1 initial_permuatation[FT_DES_BIT_BLOCK_SIZE];
	t_byte1 expected_message[FT_DES_BIT_BLOCK_SIZE] = {
		0, 0, 1, 1, 0, 0, 0, 1,
		0, 0, 0, 0, 0, 0, 0, 1,
		0, 1, 1, 0, 0, 0, 1, 0,
		1, 1, 0, 1, 1, 1, 0, 1,
		0, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 1, 0, 0, 1, 0,
	};

	ft_des_initial_permutation(message, initial_permuatation);
	ft_des_key_permuted_choice_one(key, reduced_key);
	ft_des_derive_encryption_round_key(reduced_key, 1, round_key);
	ft_des_round(initial_permuatation,
		initial_permuatation + 32, round_key);

	int i = 0;
	while(i < FT_DES_BIT_BLOCK_SIZE)
	{
		_IS(initial_permuatation[i] == expected_message[i]);
		i++;
	}
	_END("should perform encryption round");
}

int encrypt_block()
{
	t_byte1 message[FT_DES_BYTE_BLOCK_SIZE] = {
		97, 115, 100, 97, 115, 100, 97, 115
	};
	t_byte1 expected_cypertext[FT_DES_BYTE_BLOCK_SIZE] = {
		6, 175, 99, 208, 71, 158, 175, 28
	};
	t_byte1 key[FT_DES_INITIAL_KEY_SIZE] = {
		0, 0, 1, 1, 1, 0, 1, 1,
		0, 0, 1, 1, 1, 0, 0, 0,
		1, 0, 0, 1, 1, 0, 0, 0,
		0, 0, 1, 1, 0, 1, 1, 1,
		0, 0, 0, 1, 0, 1, 0, 1,
		0, 0, 1, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 0, 1, 1, 1,
		0, 1, 0, 1, 1, 1, 1, 0,
	};
	t_byte1 round_keys[FT_DES_ROUND_COUNT][FT_DES_ROUND_KEY_SIZE];
	t_byte1 cyphertext[FT_DES_BYTE_BLOCK_SIZE];

	ft_des_generate_encryption_round_keys(key, round_keys);
	ft_des_process_block(message, round_keys, cyphertext);

	int i = 0;
	while(i < FT_DES_BYTE_BLOCK_SIZE)
	{
		_IS(cyphertext[i] == expected_cypertext[i]);
		i++;
	}
	_END("should encrypt block");
}

int	decrypt_block()
{
	t_byte1 cypertext[FT_DES_BYTE_BLOCK_SIZE] = {
		6, 175, 99, 208, 71, 158, 175, 28
	};
	t_byte1 expected_plaintext[FT_DES_BYTE_BLOCK_SIZE] = {
		97, 115, 100, 97, 115, 100, 97, 115
	};
	t_byte1 key[FT_DES_INITIAL_KEY_SIZE] = {
		0, 0, 1, 1, 1, 0, 1, 1,
		0, 0, 1, 1, 1, 0, 0, 0,
		1, 0, 0, 1, 1, 0, 0, 0,
		0, 0, 1, 1, 0, 1, 1, 1,
		0, 0, 0, 1, 0, 1, 0, 1,
		0, 0, 1, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 0, 1, 1, 1,
		0, 1, 0, 1, 1, 1, 1, 0,
	};
	t_byte1 round_keys[FT_DES_ROUND_COUNT][FT_DES_ROUND_KEY_SIZE];
	t_byte1 plaintext[FT_DES_BYTE_BLOCK_SIZE];

	ft_des_generate_decryption_round_keys(key, round_keys);
	ft_des_process_block(cypertext, round_keys, plaintext);

	int i = 0;
	while(i < FT_DES_BYTE_BLOCK_SIZE)
	{
		_IS(plaintext[i] == expected_plaintext[i]);
		i++;
	}
	_END("should decrypt block");
}

int	init_ctx()
{
	t_des_ctx ctx;
	int i;
	int j;
	ft_des_init_ctx(&ctx);

	i = 0;
	while(i < FT_DES_BIT_BLOCK_SIZE)
	{
		_IS(ctx.key[i] == 0);
		i++;
	}

	i = 0;
	while(i < FT_DES_ROUND_COUNT)
	{
		j = 0;
		while(j < FT_DES_ROUND_KEY_SIZE)
		{
			_IS(ctx.round_keys[i][j] == 0);
			j++;
		}
		i++;
	}
	i = 0;
	while(i < FT_DES_BYTE_BLOCK_SIZE)
	{
		_IS(ctx.buffer[i] == 0);
		i++;
	}
	i = 0;
	while(i < FT_DES_BIT_BLOCK_SIZE)
	{
		_IS(ctx.iv[i] == 0);
		i++;
	}
	_IS(ctx.readed == 0);
	_IS(ctx.input_fd == STDIN_FILENO);
	_IS(ctx.output_fd == STDOUT_FILENO);
	_IS(ctx.decode == 0);
	_IS(ctx.b64 == 0);
	_IS(ctx.raw_password == NULL);
	_IS(ctx.raw_key == NULL);
	_IS(ctx.raw_salt == NULL);
	_IS(ctx.raw_iv == NULL);
	_IS(ctx.encrypt == NULL);
	_IS(ctx.decrypt == NULL);
	_END("shoud init ctx");
}

int convert_hex_string_to_bits()
{
	t_byte1 expected_key[FT_DES_INITIAL_KEY_SIZE] = {
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
	};
	t_byte1 actual_key[FT_DES_INITIAL_KEY_SIZE];
	const char *wrong_key_char;
	int i;

	wrong_key_char = ft_des_hex_to_bit("FFFFFFFFFFFFFFFF", actual_key,
		FT_DES_INITIAL_KEY_SIZE);
	_IS(wrong_key_char == NULL);

	i = 0;
	while(i < FT_DES_INITIAL_KEY_SIZE)
	{
		_IS(expected_key[i] == actual_key[i]);
		i++;
	}

	wrong_key_char = ft_des_hex_to_bit("ffffffffffffffff", actual_key,
		FT_DES_INITIAL_KEY_SIZE);
	_IS(wrong_key_char == NULL);

	i = 0;
	while(i < FT_DES_INITIAL_KEY_SIZE)
	{
		_IS(expected_key[i] == actual_key[i]);
		i++;
	}
	_END("should convert hex string to 64 bit key");
}

int convert_short_hex_string_to_bits()
{
	t_byte1 expected_key[FT_DES_INITIAL_KEY_SIZE] = {
		1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 0, 1, 0, 0, 1, 0,
		1, 1, 0, 0, 1, 1, 0, 1,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
	};
	t_byte1 actual_key[FT_DES_INITIAL_KEY_SIZE];
	const char *wrong_key_char;
	int i;

	ft_bzero(actual_key, FT_DES_INITIAL_KEY_SIZE);
	wrong_key_char = ft_des_hex_to_bit("FF12CD", actual_key,
		FT_DES_INITIAL_KEY_SIZE);
	_IS(wrong_key_char == NULL);

	i = 0;
	while(i < FT_DES_INITIAL_KEY_SIZE)
	{
		_IS(expected_key[i] == actual_key[i]);
		i++;
	}
	_END("should convert shorter hex string to 64 bit key");
}

int convert_longer_hex_string_to_bits()
{
	t_byte1 expected_key[FT_DES_INITIAL_KEY_SIZE] = {
		1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 0, 1, 0, 0, 1, 0,
		1, 1, 0, 0, 1, 1, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 0, 1, 0, 0, 1, 0,
		1, 1, 0, 0, 1, 1, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 0, 1, 0, 0, 1, 0,
	};
	t_byte1 actual_key[FT_DES_INITIAL_KEY_SIZE];
	const char *wrong_key_char;
	int i;

	ft_bzero(actual_key, FT_DES_INITIAL_KEY_SIZE);
	wrong_key_char = ft_des_hex_to_bit("FF12CDFF12CDFF12CD", actual_key,
		FT_DES_INITIAL_KEY_SIZE);
	_IS(wrong_key_char == NULL);

	i = 0;
	while(i < FT_DES_INITIAL_KEY_SIZE)
	{
		_IS(expected_key[i] == actual_key[i]);
		i++;
	}
	_END("should convert longer hex string to 64 bit key");
}

int convert_hex_string_to_bytes()
{
	t_byte1 expected[FT_DES_BYTE_BLOCK_SIZE] = {
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	};
	t_byte1 actual[FT_DES_BYTE_BLOCK_SIZE];
	const char *wrong_char;
	int i;

	ft_bzero(actual, FT_DES_BYTE_BLOCK_SIZE);
	wrong_char = ft_des_hex_to_byte("FFFFFFFFFFFFFFFF", actual,
		FT_DES_BYTE_BLOCK_SIZE);
	_IS(wrong_char == NULL);

	i = 0;
	while(i < FT_DES_BYTE_BLOCK_SIZE)
	{
		_IS(expected[i] == actual[i]);
		i++;
	}
	_END("should convert hex to 8 byte");
}

int convert_short_hex_string_to_bytes()
{
	t_byte1 expected[FT_DES_BYTE_BLOCK_SIZE] = {
		0xcc, 0x56, 0x50, 0, 0, 0, 0, 0,
	};
	t_byte1 actual[FT_DES_BYTE_BLOCK_SIZE];
	const char *wrong_char;
	int i;

	ft_bzero(actual, FT_DES_BYTE_BLOCK_SIZE);
	wrong_char = ft_des_hex_to_byte("CC565", actual,
		FT_DES_BYTE_BLOCK_SIZE);
	_IS(wrong_char == NULL);

	i = 0;
	while(i < FT_DES_BYTE_BLOCK_SIZE)
	{
		_IS(expected[i] == actual[i]);
		i++;
	}
	_END("should convert short hex string to 8 bytes");
}

int convert_bytes_to_bits()
{
	t_byte1 expected[FT_DES_BIT_BLOCK_SIZE] = {
		1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 0, 1, 0, 0, 1, 0,
		1, 1, 0, 0, 1, 1, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 0, 1, 0, 0, 1, 0,
		1, 1, 0, 0, 1, 1, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 0, 1, 0, 0, 1, 0,
	};
	t_byte1 actual[FT_DES_BIT_BLOCK_SIZE];
	t_byte1 bytes[FT_DES_BYTE_BLOCK_SIZE];
	const char *wrong_char;
	int i;

	ft_bzero(actual, FT_DES_BYTE_BLOCK_SIZE);
	wrong_char = ft_des_hex_to_byte("FF12CDFF12CDFF12CD", bytes,
		FT_DES_BYTE_BLOCK_SIZE);
	ft_des_byte_to_bits(bytes, FT_DES_BYTE_BLOCK_SIZE, actual,
		FT_DES_BIT_BLOCK_SIZE);

	i = 0;
	while(i < FT_DES_BIT_BLOCK_SIZE)
	{
		_IS(expected[i] == actual[i]);
		i++;
	}
	_END("should convert 8 bytes to 64 bits");
}

int convert_bits_to_bytes()
{
	t_byte1 bits[FT_DES_BIT_BLOCK_SIZE] = {
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
	};
	t_byte1 expected[FT_DES_BYTE_BLOCK_SIZE] = {
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	};
	t_byte1 actual[FT_DES_BIT_BLOCK_SIZE];
	int i;

	ft_bzero(actual, FT_DES_BIT_BLOCK_SIZE);
	ft_des_bits_to_bytes(bits, FT_DES_BIT_BLOCK_SIZE, actual,
		FT_DES_BYTE_BLOCK_SIZE);

	i = 0;
	while(i < FT_DES_BYTE_BLOCK_SIZE)
	{
		_IS(expected[i] == actual[i]);
		i++;
	}
	t_byte1 bits1[FT_DES_BIT_BLOCK_SIZE] = {
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 1, 0, 0, 0, 1,
		0, 0, 1, 0, 0, 0, 1, 0,
		0, 0, 1, 1, 0, 0, 1, 1,
		0, 1, 0, 0, 0, 1, 0, 0,
		0, 1, 0, 1, 0, 1, 0, 1,
		0, 1, 1, 0, 0, 1, 1, 0,
		0, 1, 1, 1, 0, 1, 1, 1,
	};
	t_byte1 expected1[FT_DES_BYTE_BLOCK_SIZE] = {
		0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
	};
	ft_des_bits_to_bytes(bits1, FT_DES_BIT_BLOCK_SIZE, actual,
		FT_DES_BYTE_BLOCK_SIZE);
	i = 0;
	while(i < FT_DES_BYTE_BLOCK_SIZE)
	{
		_IS(expected1[i] == actual[i]);
		i++;
	}
	_END("should convert 64 bits to 8 bytes");
}

int des_tests()
{
	_SHOULD(perform_initial_permutation);
	_SHOULD(perform_final_permutation);
	_SHOULD(final_permutation_IS_reverse_of_initial);
	_SHOULD(perform_expansion_in_feistel_function);
	_SHOULD(s_boxes_confuse);
	_SHOULD(perform_premutation_in_feistel_function);
	_SHOULD(perform_feistel_function);
	_SHOULD(reduce_key_to_56_bits);
	_SHOULD(rotate_half_key);
	_SHOULD(derive_round_key);
	_SHOULD(perform_encryption_round);
	_SHOULD(encrypt_block);
	_SHOULD(decrypt_block);
	_SHOULD(init_ctx);
	_SHOULD(convert_hex_string_to_bits);
	_SHOULD(convert_short_hex_string_to_bits);
	_SHOULD(convert_longer_hex_string_to_bits);
	_SHOULD(convert_hex_string_to_bytes);
	_SHOULD(convert_short_hex_string_to_bytes);
	_SHOULD(convert_bytes_to_bits);
	_SHOULD(convert_bits_to_bytes);
	return 0;
}
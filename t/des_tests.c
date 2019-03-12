#include "t.h"
#include "tests.h"
#include "ft_des.h"
#include "libft.h"

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
		_is(initial_permutation[i] == expect[i]);
		i++;
	}
	_end("perform initial permutation");
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
		_is(final_permutation[i] == expect[i]);
		i++;
	}
	_end("perform final permutation");
}

int final_permutation_is_reverse_of_initial()
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
		_is(final_permutation[i] == message[i]);
		i++;
	}
	_end("final permutation is reverse of initial");
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
		_is(expanded_half_actual[i] == expanded_half_expected[i]);
		i++;
	}
	_end("perform expansion in feistel function");
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

	_is(s_box_check(s1_inputs, s1_expected, ft_des_s_box_1));

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

	_is(s_box_check(s2_inputs, s2_expected, ft_des_s_box_2));

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

	_is(s_box_check(s3_inputs, s3_expected, ft_des_s_box_3));

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

	_is(s_box_check(s4_inputs, s4_expected, ft_des_s_box_4));

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

	_is(s_box_check(s5_inputs, s5_expected, ft_des_s_box_5));

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

	_is(s_box_check(s6_inputs, s6_expected, ft_des_s_box_6));

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

	_is(s_box_check(s7_inputs, s7_expected, ft_des_s_box_7));

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

	_is(s_box_check(s8_inputs, s8_expected, ft_des_s_box_8));

	_end("s boxes confuse");
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
		_is(actual[i] == expected[i]);
		i++;
	}
	_end("should perform permutation in feistel function");
}

int perform_feistel_function()
{
	t_byte1 key[FT_DES_FEISTEL_FUNCTION_KEY_SIZE] = {
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
		_is(output[i] == expected[i]);
		i++;
	}
	_end("feistel function should encode half of a block");
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
		_is(actual_reduced[i] == expected_reduced_key[i]);
		i++;
	}

	_end("should reduce key size to 56 bits");
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
		_is(half_key[i] == expected[i]);
		i++;
	}
	_end("should rotate half of reduced key");
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

	t_byte1 expected_round_key[FT_DES_FEISTEL_FUNCTION_KEY_SIZE] = {
		0, 0, 0, 1, 1, 0,
		1, 1, 0, 0, 0, 0,
		0, 0, 1, 0, 1, 1,
		1, 0, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1,
		0, 0, 0, 1, 1, 1,
		0, 0, 0, 0, 0, 1,
		1, 1, 0, 0, 1, 0,
	};

	t_byte1 round_key[FT_DES_FEISTEL_FUNCTION_KEY_SIZE];

	ft_des_derive_encryption_round_key(reduced_key, 1, round_key);

	int i;

	i = 0;
	while(i < FT_DES_REDUCED_KEY_SIZE)
	{
		_is(shifted_reduced_key[i] == reduced_key[i]);
		i++;
	}

	i = 0;
	while(i < FT_DES_FEISTEL_FUNCTION_KEY_SIZE)
	{
		_is(round_key[i] == expected_round_key[i]);
		i++;
	}
	_end("should derive round key");
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
	t_byte1 round_key[FT_DES_FEISTEL_FUNCTION_KEY_SIZE];
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
	ft_des_encryption_round(initial_permuatation,
		initial_permuatation + 32, round_key);

	int i = 0;
	while(i < FT_DES_BIT_BLOCK_SIZE)
	{
		_is(initial_permuatation[i] == expected_message[i]);
		i++;
	}
	_end("should perform encryption round");
}

int encrypt_block()
{
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
	t_byte1 expected_cypertext[FT_DES_BIT_BLOCK_SIZE] = {
		0, 0, 0, 0, 0, 1, 1, 0,
		1, 0, 1, 0, 1, 1, 1, 1,
		0, 1, 1, 0, 0, 0, 1, 1,
		1, 1, 0, 1, 0, 0, 0, 0,
		0, 1, 0, 0, 0, 1, 1, 1,
		1, 0, 0, 1, 1, 1, 1, 0,
		1, 0, 1, 0, 1, 1, 1, 1,
		0, 0, 0, 1, 1, 1, 0, 0,
	};
	t_byte1 cyphertext[FT_DES_BIT_BLOCK_SIZE];

	ft_des_encrypt_block(message, key, cyphertext);

	int i = 0;
	while(i < FT_DES_BIT_BLOCK_SIZE)
	{
		_is(cyphertext[i] == expected_cypertext[i]);
		i++;
	}
	_end("should encrypt block");
}

int des_tests()
{
	_should(perform_initial_permutation);
	_should(perform_final_permutation);
	_should(final_permutation_is_reverse_of_initial);
	_should(perform_expansion_in_feistel_function);
	_should(s_boxes_confuse);
	_should(perform_premutation_in_feistel_function);
	_should(perform_feistel_function);
	_should(reduce_key_to_56_bits);
	_should(rotate_half_key);
	_should(derive_round_key);
	_should(perform_encryption_round);
	_should(encrypt_block);
	return 0;
}
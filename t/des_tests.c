#include "t.h"
#include "tests.h"
#include "ft_des.h"
#include "libft.h"

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



int des_tests()
{
	_should(perform_initial_permutation);
	_should(perform_final_permutation);
	_should(final_permutation_is_reverse_of_initial);
	_should(perform_expansion_in_feistel_function);
	return 0;
}
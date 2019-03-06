#include "t.h"
#include "tests.h"
#include "ft_des.h"
#include "libft.h"

int perform_initial_permutation()
{
	// all 64 bits:
	// 00000001 00100011 01000101 01100111 10001001 10101011 11001101 11101111
	// block contains message bits in big-endian order
	t_byte1 message[FT_DES_BIT_BLOCK_SIZE] = (t_byte1 [FT_DES_BIT_BLOCK_SIZE]) {
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
	t_byte1 expect[FT_DES_BIT_BLOCK_SIZE] = (t_byte1 [FT_DES_BIT_BLOCK_SIZE]) {
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

int des_tests()
{
	_should(perform_initial_permutation);
	return 0;
}
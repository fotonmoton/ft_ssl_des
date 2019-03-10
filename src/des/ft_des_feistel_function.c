#include "ft_des.h"

static void merge_key
(
	t_byte1 expanded_half[FT_DES_EXPANDED_HALF_BLOCK_SIZE],
	t_byte1 key[FT_DES_FEISTEL_FUNCTION_KEY_SIZE],
	t_byte1 output[FT_DES_EXPANDED_HALF_BLOCK_SIZE]
)
{
	int i = 0;
	while(i < FT_DES_EXPANDED_HALF_BLOCK_SIZE)
	{
		output[i] = expanded_half[i] ^ key[i];
		i++;
	}
}

void	ft_des_feistel_function
(
	t_byte1 right_half[FT_DES_BIT_BLOCK_SIZE / 2],
	t_byte1 key[FT_DES_FEISTEL_FUNCTION_KEY_SIZE],
	t_byte1 output[FT_DES_BIT_BLOCK_SIZE / 2]
)
{
	t_byte1 expanded[FT_DES_EXPANDED_HALF_BLOCK_SIZE];
	t_byte1 all_s_boxes[FT_DES_BIT_BLOCK_SIZE / 2];

	ft_des_expansion_box(right_half, expanded);
	merge_key(expanded, key, expanded);
	ft_des_s_box_1(expanded, all_s_boxes);
	ft_des_s_box_2(expanded + 6, all_s_boxes + 4);
	ft_des_s_box_3(expanded + 12, all_s_boxes + 8);
	ft_des_s_box_4(expanded + 18, all_s_boxes + 12);
	ft_des_s_box_5(expanded + 24, all_s_boxes + 16);
	ft_des_s_box_6(expanded + 30, all_s_boxes + 20);
	ft_des_s_box_7(expanded + 36, all_s_boxes + 24);
	ft_des_s_box_8(expanded + 42, all_s_boxes + 28);
	ft_des_feistel_function_permutation(all_s_boxes, output);
}
#include "ft_des.h"

void	ft_des_s_box_6
(
	t_byte1 input[FT_DES_S_BOX_INPUT_SIZE],
	t_byte1 output[FT_DES_S_BOX_OUTPUT_SIZE]
)
{
	static t_byte1 tbl[FT_DES_S_BOX_TABLE_ROWS][FT_DES_S_BOX_TABLE_COLUMNS] = {
		{12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11},
		{10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8},
		{ 9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6},
		{ 4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13},
	};
	ft_des_s_box(input, output, tbl);
}
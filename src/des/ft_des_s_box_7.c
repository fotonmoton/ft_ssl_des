#include "ft_des.h"

void	ft_des_s_box_7
(
	t_byte1 input[FT_DES_S_BOX_INPUT_SIZE],
	t_byte1 output[FT_DES_S_BOX_OUTPUT_SIZE]
)
{
	static t_byte1 tbl[FT_DES_S_BOX_TABLE_ROWS][FT_DES_S_BOX_TABLE_COLUMNS] = {
		{ 4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1},
		{13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6},
		{ 1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2},
		{ 6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12},
	};
	ft_des_s_box(input, output, tbl);
}
#include "ft_des.h"

void	ft_des_s_box
(
	t_byte1 input[FT_DES_S_BOX_INPUT_SIZE],
	t_byte1 output[FT_DES_S_BOX_OUTPUT_SIZE],
	t_byte1 table[FT_DES_S_BOX_TABLE_ROWS][FT_DES_S_BOX_TABLE_COLUMNS]
)
{
	t_byte1 row;
	t_byte1 column;
	t_byte1 selected;

	row = (input[0] << 1 | input[5]) & 0xf;
	column = (input[1] << 3 | input[2] << 2 | input[3] << 1 | input[4]) & 0xf;
	selected = table[row][column];
	output[0] = selected >> 3 & 1;
	output[1] = selected >> 2 & 1;
	output[2] = selected >> 1 & 1;
	output[3] = selected & 1;
}
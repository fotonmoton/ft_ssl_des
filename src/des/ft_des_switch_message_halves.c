#include "ft_des.h"

void	ft_des_switch_message_halves
(
	t_byte1 message[FT_DES_BIT_BLOCK_SIZE]
)
{
	int i;
	int tmp;
	i = 0;

	while(i < FT_DES_BIT_BLOCK_SIZE / 2)
	{
		tmp = message[i];
		message[i] = message[i + FT_DES_BIT_BLOCK_SIZE / 2];
		message[i + FT_DES_BIT_BLOCK_SIZE / 2] = tmp;
		i++;
	}
}
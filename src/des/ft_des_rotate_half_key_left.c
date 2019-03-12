#include "ft_des.h"

void	ft_des_rotate_half_key_left
(
	t_byte1 half[FT_DES_REDUCED_KEY_SIZE / 2],
	t_byte1 rotation_number
)
{
	t_byte1 i;
	t_byte1 j;
	t_byte1 tmp;

	i = 0;
	while(i < rotation_number)
	{
		tmp = half[0];
		j = 0;
		while(j < FT_DES_REDUCED_KEY_SIZE / 2 - 1)
		{
			half[j] = half[j + 1];
			j++;
		}
		half[FT_DES_REDUCED_KEY_SIZE / 2 - 1] = tmp;
		i++;
	}
}
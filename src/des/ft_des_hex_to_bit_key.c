#include "ft_des.h"
#include "libft.h"

const char		*ft_des_hex_to_bit_key
(
	const char *hex_key,
	t_byte1 bit_key[FT_DES_INITIAL_KEY_SIZE]
)
{
	t_byte1	bits4;
	int		i;
	i = 0;
	while(*hex_key && i < FT_DES_INITIAL_KEY_SIZE)
	{
		bits4 = ft_tolower(*hex_key);
		if (bits4 >= '0' && bits4 <= '9')
			bits4 = bits4 - '0';
		else if (bits4 >= 'a' && bits4 <= 'f')
			bits4 = bits4 - 'a' + 10;
		else
			return (hex_key);
		bit_key[i] = bits4 >> 3 & 1;
		bit_key[i + 1] = bits4 >> 2 & 1;
		bit_key[i + 2] = bits4 >> 1 & 1;
		bit_key[i + 3] = bits4 & 1;
		i += 4;
		hex_key++;
	}
	return (NULL);
}
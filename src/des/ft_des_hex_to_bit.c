#include "ft_des.h"
#include "libft.h"

const char		*ft_des_hex_to_bit
(
	const char *hex,
	t_byte1 *bits,
	t_byte8 bit_len
)
{
	t_byte1		bits4;
	t_byte8		i;
	i = 0;
	while(*hex && i < bit_len)
	{
		bits4 = ft_tolower(*hex);
		if (bits4 >= '0' && bits4 <= '9')
			bits4 = bits4 - '0';
		else if (bits4 >= 'a' && bits4 <= 'f')
			bits4 = bits4 - 'a' + 10;
		else
			return (hex);
		bits[i] = bits4 >> 3 & 1;
		bits[i + 1] = bits4 >> 2 & 1;
		bits[i + 2] = bits4 >> 1 & 1;
		bits[i + 3] = bits4 & 1;
		i += 4;
		hex++;
	}
	return (NULL);
}
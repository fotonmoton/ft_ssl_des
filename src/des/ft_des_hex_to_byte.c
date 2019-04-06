#include "ft_des.h"
#include "libft.h"

static int		char_to_num
(
	unsigned char c,
	unsigned char *n
)
{
	t_byte1 bits4;

	bits4 = ft_tolower(c);
	if (bits4 >= '0' && bits4 <= '9')
		*n = bits4 - '0';
	else if (bits4 >= 'a' && bits4 <= 'f')
		*n = bits4 - 'a' + 10;
	else
		return (1);
	return (0);
}

const char		*ft_des_hex_to_byte
(
	const char *hex,
	t_byte1 *bytes,
	t_byte8 byte_len
)
{
	t_byte1		first_byte_half;
	t_byte1		second_byte_half;
	t_byte8		i;
	i = 0;
	while(*hex && i < byte_len)
	{
		if (char_to_num(*hex, &first_byte_half))
			return (hex);
		bytes[i] = ((first_byte_half << 4) & 0xf0);
		if (!*(hex + 1))
			break ;
		if (char_to_num(*(hex + 1), &second_byte_half))
			return (hex + 1);
		bytes[i] |= (second_byte_half & 0xf);
		i++;
		hex += 2;
	}
	return (NULL);
}
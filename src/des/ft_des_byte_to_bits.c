#include "ft_des.h"

void	ft_des_byte_to_bits
(
	t_byte1 *bytes,
	t_byte8 bytes_len,
	t_byte1 *bits,
	t_byte8 bits_len
)
{
	t_byte8 bits_count;
	t_byte8 bytes_count;

	bits_count = 0;
	bytes_count = 0;
	while(bits_count < bits_len && bytes_count < bytes_len)
	{
		bits[bits_count] = bytes[bytes_count] >> 7 & 1;
		bits[bits_count + 1] = bytes[bytes_count] >> 6 & 1;
		bits[bits_count + 2] = bytes[bytes_count] >> 5 & 1;
		bits[bits_count + 3] = bytes[bytes_count] >> 4 & 1;
		bits[bits_count + 4] = bytes[bytes_count] >> 3 & 1;
		bits[bits_count + 5] = bytes[bytes_count] >> 2 & 1;
		bits[bits_count + 6] = bytes[bytes_count] >> 1 & 1;
		bits[bits_count + 7] = bytes[bytes_count] & 1;
		bytes_count++;
		bits_count += 8;
	}
}
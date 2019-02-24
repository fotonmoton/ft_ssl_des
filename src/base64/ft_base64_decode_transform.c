#include "ft_base64.h"
#include "libft.h"

static t_byte1 get_alphabet_index
(
	t_byte1 *alphabet,
	t_byte1 ch
)
{
	char *alphabet_addr;

	alphabet_addr = ft_strchr((const char*)alphabet, ch);
	if (!alphabet_addr)
	{
		ft_putstr("base64: invalid input\n");
		exit(1);
	}
	return (alphabet_addr - (char *)alphabet);
}

void	ft_base64_decode_transform
(
	t_base64_ctx *c,
	t_byte1 blk[FT_BASE64_DECODE_BLOCK_SIZE],
	t_byte1 decoded_block[FT_BASE64_ENCODE_BLOCK_SIZE]
)
{
	t_byte1		first_index;
	t_byte1		second_index;
	t_byte1		third_index;
	t_byte1		fourth_index;

	first_index = get_alphabet_index(c->alphabet, blk[0]);
	second_index = get_alphabet_index(c->alphabet, blk[1]);
	third_index = blk[2] == '=' ? 0 : get_alphabet_index(c->alphabet, blk[2]);
	fourth_index = blk[3] == '=' ? 0 : get_alphabet_index(c->alphabet, blk[3]);
	decoded_block[0] = first_index << 2 | second_index >> 4;
	decoded_block[1] = second_index << 4 | third_index >> 2;
	decoded_block[2] = third_index << 6 | fourth_index;
}
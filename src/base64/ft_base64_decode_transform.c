#include "ft_base64.h"
#include "libft.h"

void	ft_base64_decode_transform
(
	t_base64_ctx *ctx,
	t_byte1 blk[FT_BASE64_DECODE_BLOCK_SIZE],
	t_byte1 decoded_block[FT_BASE64_ENCODE_BLOCK_SIZE]
)
{
	t_byte1		first_index;
	t_byte1		second_index;
	t_byte1		third_index;
	t_byte1		fourth_index;
	const char	*alphabet;

	alphabet = (const char *)ctx->alphabet;
	first_index = ft_strchr(alphabet, blk[0]) - alphabet;
	second_index = ft_strchr(alphabet, blk[1]) - alphabet;
	third_index = blk[2] == '=' ? 0 : ft_strchr(alphabet, blk[2]) - alphabet;
	fourth_index = blk[3] == '=' ? 0 : ft_strchr(alphabet, blk[3]) - alphabet;

	decoded_block[0] = first_index << 2 | second_index >> 4;
	decoded_block[1] = second_index << 4 | third_index >> 2;
	decoded_block[2] = third_index << 6 | fourth_index;
}
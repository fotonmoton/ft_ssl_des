#include "libft.h"
#include "ft_base64.h"

void	ft_base64_encode_buffer(t_base64_ctx *ctx, t_byte8 len)
{
	t_byte1		first_char;
	t_byte1		second_char;
	t_byte1		third_char;
	t_byte1		fourth_char;

	first_char = (ctx->block[0] >> 2) & 0x3f;
	second_char = ((ctx->block[0] << 4) & 0x30) | ((ctx->block[1] >> 4) & 0xf);
	third_char = ((ctx->block[1] << 2) & 0x3c) | ((ctx->block[2] >> 6) & 0x3);
	fourth_char = ctx->block[2] & 0x3F;

	ctx->chars[0] = ctx->alphabet[first_char];
	ctx->chars[1] = ctx->alphabet[second_char];
	if (len < 2)
		ctx->chars[2] = '=';
	else
		ctx->chars[2] = ctx->alphabet[third_char];
	if (len < 3)
		ctx->chars[3] = '=';
	else
		ctx->chars[3] = ctx->alphabet[fourth_char];
	ft_bzero(ctx->block, FT_BASE64_BLOCK_SIZE);
}
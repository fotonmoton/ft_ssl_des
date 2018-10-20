#include "ft_md5.h"
#include "libft.h"

void ft_md5_final(BYTE1 digest[FT_MD5_DIGEST_LENGTH_BYTE], t_md5_ctx *ctx)
{
	BYTE1 length_as_bytes[FT_MD5_MESSAGE_LENGTH_BYTE];
	BYTE1 padding[FT_MD5_BLOCK_SIZE];
	BYTE8 buff_index;
	BYTE8 padding_len;

	ft_md5_encode_len(length_as_bytes, ctx->bit_len);
	buff_index = (ctx->bit_len / 8) % 64;
	padding_len = (buff_index < 56) ? (56 - buff_index) : (120 - buff_index);

	ft_md5_padding(padding);
	ft_md5_update(ctx, padding, padding_len);
	ft_md5_update(ctx, length_as_bytes, FT_MD5_MESSAGE_LENGTH_BYTE);
	ft_md5_encode_register(digest, ctx->a);
	ft_md5_encode_register(&digest[4], ctx->b);
	ft_md5_encode_register(&digest[8], ctx->c);
	ft_md5_encode_register(&digest[12], ctx->d);
	ft_bzero(ctx, sizeof(t_md5_ctx));
}
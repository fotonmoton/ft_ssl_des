#include "ft_des.h"
#include <unistd.h>

void	ft_des_ecb_finish_encrypt
(
	t_des_ctx *ctx
)
{
	t_byte1 buffer_index;
	t_byte1 padding_size;
	t_byte1 cyphertext[FT_DES_BYTE_BLOCK_SIZE];

	buffer_index = ctx->readed % FT_DES_BYTE_BLOCK_SIZE;
	padding_size = FT_DES_BYTE_BLOCK_SIZE - buffer_index;

	while(buffer_index < FT_DES_BYTE_BLOCK_SIZE)
	{
		ctx->buffer[buffer_index] = padding_size;
		buffer_index++;
	}
	ft_des_process_block(ctx->buffer, ctx->round_keys, cyphertext);
	if (ctx->b64)
	{
		ft_base64_encode_chunk(&ctx->b64_ctx, FT_DES_BYTE_BLOCK_SIZE,
			cyphertext,
			&ctx->b64_encode_buffer
		);
		ft_base64_encode_finish(&ctx->b64_ctx, &ctx->b64_encode_buffer);
	}
	else
		write(ctx->output_fd, cyphertext, FT_DES_BYTE_BLOCK_SIZE);
}
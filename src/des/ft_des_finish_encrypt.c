#include "ft_des.h"
#include <unistd.h>

void	ft_des_finish_encrypt
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
	ctx->encrypt(ctx->buffer, ctx->round_keys, ctx->iv, cyphertext);
	write(ctx->output_fd, cyphertext, FT_DES_BYTE_BLOCK_SIZE);
}
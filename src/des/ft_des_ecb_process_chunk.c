#include "ft_des.h"

void	ft_des_ecb_process_chunk
(
	t_des_ctx *ctx,
	t_byte8 readed,
	t_byte8 buffer[FT_DES_READ_SIZE]
)
{
	t_byte8		free_space_in_buffer;
	t_byte8		buffer_index;
	t_byte8		idx;

	buffer_index = ctx->readed % FT_DES_BYTE_BLOCK_SIZE;
	ctx->readed += readed;
	free_space_in_buffer = FT_DES_BYTE_BLOCK_SIZE - buffer_index;
	if (readed >= free_space_in_buffer)
	{
		ft_memcpy(&ctx->buffer[buffer_index], buffer, free_space_in_buffer);
		ft_base64_encode_write(ctx, ctx->buffer);
		idx = free_space_in_buffer;
		while(idx + FT_DES_BYTE_BLOCK_SIZE <= readed)
		{
			ft_base64_encode_write(ctx, &buffer[idx]);
			idx += FT_DES_BYTE_BLOCK_SIZE;
		}
		buffer_index = 0;
	}
	else
		idx = 0;
	ft_memcpy(&ctx->buffer[buffer_index], &buffer[idx], readed - idx);
}